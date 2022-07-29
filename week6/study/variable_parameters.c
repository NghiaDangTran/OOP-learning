#include <stdio.h>

int f(int *x, int *y)
{
  *x = 4;
  *y = 5;
  return 6;
}

// this is an old example; now we know why it works
// (the "to" array is a pointer, and we are changing the values pointed to)
int my_strncpy(char to[], char from[], int max_length)
{
  int len = 0;
  
  while ('\0' != from[len] && len < max_length - 1) {
    to[len] = from[len];
    len++;
  }
  to[len] = '\0';
  
  return len;
}

int main()
{
  int a, b, c;

  a = 1;
  b = 2;
  c = 3;
  
  printf("a: %d b: %d c: %d\n", a, b, c);

  a = f(&b, &c);
  // note: there is no way to pass a literal to the second parameter of f
  // e.g. we can call f(100, c) but not f(b, &100)

  printf("a: %d b: %d c: %d\n", a, b, c);
  
  return 0;
}