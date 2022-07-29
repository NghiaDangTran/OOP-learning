#include <stdio.h>
#include <string.h>

int main()
{
  char str[] = "hello, world!";
  char *c_ptr;
  int count;
  int array[] = { 1, 2, 3, 4, -1 };
  int *i_ptr, sum; // sum is NOT a pointer!
  
  c_ptr = str; // an array *is* an immutable pointer

  printf("Both the array and the pointer point to the same place:\n %p %p\n", c_ptr, str);

  // dereference the first character four different ways
  printf("First character: %c %c %c %c\n\n", str[0], *str, *c_ptr, c_ptr[0]);
  
  // calculate strlen without calling strlen
  // loop through all the characters
  count = 0;
  while ('\0' != *c_ptr) {
    printf("%02d: %c\n", count, *c_ptr);
    // printf("%p: %c\n", c_ptr, *c_ptr); // print pointer and value
    count++;
    c_ptr++; // makes c_ptr point to the next character
  }
  printf("\nTotal length: %d\n", count);
  
  // is this more/less readable than using array notation [] ?
  i_ptr = array;
  sum = 0;
  while (*i_ptr >= 0) {
    // printf("%p: %d\n", i_ptr, *i_ptr); // print pointer and value
    sum += i_ptr[1];
    i_ptr++;
  }
  printf("\nSum of values: %d\n", sum);
  
  return 0;
}