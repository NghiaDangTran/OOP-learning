#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "require.h"

#include "regions.h"

int main()
{
  fprintf(stderr, "test5.c: strange and invalid blocks\n");

  rinit("one", 1024);
  
  assert(!rfree(0));
  rsize(ralloc(0));
  rfree(ralloc(0));
  assert(!rfree(0));
  
  rchoose("one");
  for (int i = 0; i <= 1033; i++) {
    rfree(ralloc(i));
  }

  rdump();
  
  for (int i = 0; i < 1024/8; i++) {
    assert(rsize(ralloc(1)) == 8);
  }
  rsize(ralloc(1));
  rfree(ralloc(1));
  
  fprintf(stderr,"\nEnd of processing.\n");

  return 0;
}