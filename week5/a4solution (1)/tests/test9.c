#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "require.h"

#include "regions.h"

#define COUNT 8
const int SIZE = 64;
void *ptrs[4][COUNT];

void setup(int pos, int size, char start)
{
  int i, j;
  char *str;

  for (i = 0; i < COUNT; i++) {
    assert(NULL != (ptrs[pos][i] = ralloc(size / COUNT)));
    str = ptrs[pos][i];
    for (j = 0; j < size / COUNT - 1; j++) {
      str[j] = start + j;
    }
    str[j] = '\0';
  }
}

void check(int pos, int size, char start) {
  int i;
  char str[SIZE];

  for (i = 0; i < size / COUNT - 1; i++) {
    str[i] = start + i;
  }
  str[i] = '\0';

  for (i = 0; i < COUNT; i++) {
    assert(size / COUNT == rsize(ptrs[pos][i]));
    assert(strcmp(ptrs[pos][i], str) == 0);
  }
}

int main()
{
  int i;

  fprintf(stderr, "test9.c: many uses\n");

  assert(rinit("first", SIZE));
  assert(rinit("second", SIZE * 2));
  assert(rinit("third", SIZE * 3));
  assert(rinit("fourth", SIZE * 4));
  
  assert(rchoose("fourth"));
  setup(3, SIZE * 4, 'a');
  assert(rchoose("first"));
  setup(0, SIZE, '0');
  assert(rchoose("third"));
  setup(2, SIZE * 3, ' ');
  assert(rchoose("second"));
  setup(1, SIZE * 2, 'A');
  
  rdump();

  assert(0 == rsize(ptrs[0][0]));
  assert(0 == rsize(ptrs[2][0]));
  assert(0 == rsize(ptrs[3][0]));

  assert(rchoose("first"));
  check(0, SIZE, '0');
  assert(rchoose("second"));
  check(1, SIZE * 2, 'A');
  assert(rchoose("third"));
  check(2, SIZE * 3, ' ');
  assert(rchoose("fourth"));
  check(3, SIZE * 4, 'a');

  rdestroy("third");

  assert(0 == rsize(ptrs[2][0]));
  assert(0 == rsize(ptrs[2][COUNT - 1]));
  assert(!rfree(ptrs[2][0]));
  assert(!rfree(ptrs[2][COUNT - 1]));

  assert(rchoose("first"));
  check(0, SIZE, '0');
  assert(rchoose("second"));
  check(1, SIZE * 2, 'A');
  assert(rchoose("fourth"));
  check(3, SIZE * 4, 'a');

  assert(rchoose("second"));
  
  for (i = COUNT - 1; i >= 0; i--) {
    assert(rfree(ptrs[1][i]));
  }

  assert(rchoose("fourth"));
  assert(0 == rsize(ptrs[1][0]));
  assert(0 == rsize(ptrs[1][COUNT - 1]));
  assert(!rfree(ptrs[1][0]));
  assert(!rfree(ptrs[1][COUNT - 1]));
  assert(rchoose("second"));
  assert(0 == rsize(ptrs[1][0]));
  assert(0 == rsize(ptrs[1][COUNT - 1]));
  assert(!rfree(ptrs[1][0]));
  assert(!rfree(ptrs[1][COUNT - 1]));

  assert(rchoose("first"));
  check(0, SIZE, '0');
  assert(rchoose("fourth"));
  check(3, SIZE * 4, 'a');

  assert(!rchoose("third"));
  rdestroy("fourth");
  assert(rchoose("first"));
  check(0, SIZE, '0');

  for (i = 0; i < COUNT; i++) {
    assert(rfree(ptrs[0][i]));
  }

  assert(0 == rsize(ptrs[0][0]));
  assert(0 == rsize(ptrs[0][COUNT - 1]));
  assert(!rfree(ptrs[0][0]));
  assert(!rfree(ptrs[0][COUNT - 1]));

  rdump();

  fprintf(stderr,"\nEnd of processing.\n");

  return 0;
}