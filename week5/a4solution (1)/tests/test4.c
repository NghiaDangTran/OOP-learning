#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "require.h"

#include "regions.h"

int main()
{
  fprintf(stderr, "test4.c: strange and invalid regions\n");
  
  rdump();

  assert(NULL == rchosen());
  rdestroy(NULL);
  
  assert(!rchoose(NULL));
  assert(!rchoose("hello"));
  
  assert(!rinit(NULL, 1));
  assert(!rchoose(NULL));
  assert(!rinit("good", 0));

  assert(rinit("hello", 1024));
  assert(rinit("world", 2048));

  assert(!rchoose(""));
  assert(strcmp(rchosen(), "world") == 0);
  rinit("", 4096); // may or may not work

  assert(!rchoose(NULL));
  assert(!rinit(NULL, 1));
  assert(!rinit("bad", 0));

  assert(rchoose("hello"));
  assert(!rinit("hello", 8));
  assert(!rinit("world", 8));
  assert(strcmp(rchosen(), "hello") == 0);
  assert(ralloc(512));

  assert(rchoose("world"));
  assert(!rchoose(NULL));
  assert(!rchoose("bad"));
  assert(strcmp(rchosen(), "world") == 0);
  assert(ralloc(2048));
  
  rdestroy(NULL);
  rdestroy("bad");
  rdestroy("");
  rdestroy("hello");
  assert(rinit("hello", 1024));
  rdestroy("world");
  rdestroy(NULL);
  rdestroy("bad");
  
  rdump();
  
  fprintf(stderr,"\nEnd of processing.\n");

  return 0;
}