#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int *dynamic;
  int *array;
  int array_len = 10;
  
  // this gives us *one* integer (pretty useless):

  dynamic = malloc(sizeof(int));
  *dynamic = -333;
  printf("%p: %d\n", dynamic, *dynamic);
  free(dynamic);
  
  // create an array instead, of any length we like:

  array = malloc(array_len * sizeof(int));
  // the memory is uninitialized and may be filled with garbage
  // to initialize the memory to zero, call the following instead:
  // array = calloc(array_len, sizeof(int))

  for (int i = 0; i < array_len; i++) {
    // *(array + i) = i * 10;
    array[i] = (i+1) * 10;
  }
  
  for (int i = 0; i < array_len; i++) {
    printf("%p: %d\n", &array[i], array[i]);
  }

  free(array);
  
  return 0;
}