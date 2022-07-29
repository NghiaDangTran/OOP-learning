#include <stdio.h>
#include <stdlib.h>

typedef struct FREQUENCY
{
  int value;
  int count;
} Frequency;

const int MAX_UNIQUE_VALUES = 100000;

int getIndex(Frequency *frequencies, int value, int size)
{
  for (int i = 0; i < size; i++)
  {
    if (frequencies[i].value == value)
    {
      return i;
    }
  }
  return -1;
}
int compare(const void *s1, const void *s2)
{
  Frequency *e1 = (Frequency *)s1;
  Frequency *e2 = (Frequency *)s2;
  if (e1->count != e2->count)
  {
    return e2->count - e1->count;
  }
  else
  { // return the bigger value
    if (e1->value > e2->value)
      return e1->value;
    else
      return e2->value;
  }
}

// compare 2 string
int compareString(const void *s1, const void *s2)
{
  char *e1 = (char *)s1;
  char *e2 = (char *)s2;
  return strcmp(e1, e2);
}
int main(int argc, char *argv[])
{
  printf("%d ",strcmp("0xD2800b720b64B5bb92aA672A8d4838de480Cc083","0xD2800b720b64B5bb92aA672A8d4838de480Cc083"));
  return 0;
}


