#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 40

typedef struct STUDENT {
  int number;
  char name[MAX_NAME];
} Student;

int main()
{
  Student array[] = {
    { 1234, "john" },
    { 5678, "jane" }
  };
  const int NUM_STUDENTS = 2;
  Student *s_ptr;

  for (int i = 0; i < NUM_STUDENTS; i++) {
    printf("%d %s\n", array[i].number, array[i].name);
  }
  
  // do it again, with pointers
  // this is a demonstration only; the previous loop is better!
  s_ptr = array;
  for (int i = 0; i < NUM_STUDENTS; i++) {
    printf("%p: %d %s\n", s_ptr, s_ptr->number, s_ptr->name);
    s_ptr++;
  }
  
  return 0;
}