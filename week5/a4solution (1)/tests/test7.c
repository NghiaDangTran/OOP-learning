#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "require.h"

#include "regions.h"

static const int NUM_REGIONS = 10240;
static char names[NUM_REGIONS][10];
static void *blocks[NUM_REGIONS];

int main()
{
  int i;

  fprintf(stderr, "test7.c: %d regions\n", NUM_REGIONS);
  
  rdump();
  
  assert(!rinit(NULL, 1));
  assert(!rinit("good", 0));

  for (i = 0; i < NUM_REGIONS; i++) {
    sprintf(names[i], "r%d", i);
    assert(rinit(names[i], ((i % 1000)+2)*8));
    assert(NULL != (blocks[i] = ralloc(8 + (i % 2) * 8)));
    assert(strcmp(rchosen(), names[i]) == 0);
  }

  for (i = NUM_REGIONS-1; i >= 0; i--) {
    void *temp;
    sprintf(names[i], "r%d", i);
    assert(rchoose(names[i]));
    assert(strcmp(rchosen(), names[i]) == 0);
    assert(rsize(blocks[i]) == (8 + (i % 2) * 8));
    temp = ralloc(8);
    assert(temp == blocks[i]+(8 + (i % 2) * 8));
  }
  
  assert(!rinit(names[NUM_REGIONS/2], 100));
  assert(!rinit(names[NUM_REGIONS - 1], 100));
  
  for (i = NUM_REGIONS / 2; i >= 0; i-=2) {
    rdestroy(names[i]);
    assert(!rchoose(names[i]));
    assert(rchoose(names[i+1]));
  }
  for (i = NUM_REGIONS / 2 + 1; i < NUM_REGIONS; i++) {
    rdestroy(names[i]);
    assert(!rchoose(names[i]));
  }
  for (i = NUM_REGIONS / 2-1; i >= 0; i-=2) {
    rdestroy(names[i]);
    assert(!rchoose(names[i]));
  }

  for (i = 0; i < NUM_REGIONS; i++) {
    assert(!rchoose(names[i]));
  }
  
  rdump();
  
  fprintf(stderr,"\nEnd of processing.\n");

  return 0;
}