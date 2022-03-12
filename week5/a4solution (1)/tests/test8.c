#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "require.h"

#include "regions.h"

int main()
{
  const int NUM_REGIONS = 1000;
  const int BLOCK_SIZE = 64;
  char names[NUM_REGIONS][10];
  void *first_ptrs[NUM_REGIONS];
  int i, j;

  fprintf(stderr, "test8.c: lots of both\n");

  assert(NULL == ralloc(1));
  rdestroy(NULL);
  rdestroy("goodbye");
  assert(0 == rfree(NULL));
  assert(0 == rfree(names));
  
  for (i = 0; i < NUM_REGIONS; i++) {
    sprintf(names[i], "r%d", i);
    assert(rinit(names[i], BLOCK_SIZE * (i + 1)));
    assert(strcmp(rchosen(), names[i]) == 0);
  }
  
  for (i = NUM_REGIONS - 1; i >= 0; i--) {
    assert(rchoose(names[i]));
    assert(NULL != (first_ptrs[i] = ralloc(BLOCK_SIZE)));
    for (j = 0; j < i; j++) {
      assert(NULL != ralloc(BLOCK_SIZE));
    }
    assert(NULL == ralloc(1));
  }

  for (i = 0; i < NUM_REGIONS; i++) {
    assert(rchoose(names[i]));
    for (j = 0; j < i + 1; j++) {
      assert(BLOCK_SIZE == rsize(first_ptrs[i] + j * BLOCK_SIZE));
    }
    assert(strcmp(rchosen(), names[i]) == 0);
  }
  
  for (i = 0; i < NUM_REGIONS; i++) {
    rdestroy(names[i]);
  }
  
  rdump();
  
  fprintf(stderr,"\nEnd of processing.\n");

  return EXIT_SUCCESS;
}