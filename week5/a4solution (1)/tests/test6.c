#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "require.h"

#include "regions.h"

int main()
{
  rsize_t size;
  const int SIZE = 8191;
  char *ptrs[SIZE];
  int i;

  fprintf(stderr, "test6.c: lots of little chars\n");

  assert(rsize(NULL) == 0);
  assert(rsize(ptrs) == 0);

  size = SIZE * 8 - 7;
  assert(rinit("lots of little chars", size));
  
  for (i = 0; i < SIZE; i++) {
    ptrs[i] = ralloc(1);
    assert(NULL != ptrs[i]);
  }
  
  assert(NULL == ralloc(1));
  assert(rsize(ptrs[0]) > 0);
  assert(rsize(ptrs[SIZE - 1]) > 0);
  
  for (i = 1; i < SIZE; i++) {
    assert(ptrs[i] > ptrs[i - 1]);
    assert(ptrs[i] > ptrs[0] && ptrs[i] < ptrs[0] + size);
  }
  
  for (i = 0; i < SIZE - 1; i++) {
    assert(rfree(ptrs[i]));
  }
  
  for (i = 0; i < SIZE - 1; i++) {
    assert(!rfree(ptrs[i]));
    assert(rsize(ptrs[i]) == 0);
  }
  
  rdump();
  
  rdestroy("lots of little chars");

  assert(rsize(NULL) == 0);
  assert(rsize(ptrs) == 0);

  fprintf(stderr,"\nEnd of processing.\n");

  return 0;
}