#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME 40

typedef struct STUDENT {
  int number;
  char name[MAX_NAME];
} Student;

void f1(Student s)
{
  s.number = 42;
  strcpy(s.name, "zaphod");
}

void f2(Student *s)
{
  s->number = 99;
  strcpy(s->name, "zaphod");
}

Student f3()
{
  Student *st = { -1, "reaALY" };
  
  return st;
}

int main()
{
  Student array[] = {
    { 1234, "john" },
    { 5678, "jane" }
  };
  const int NUM_STUDENTS = 2;

  for (int i = 0; i < NUM_STUDENTS; i++) {
    printf("%d %s\n", array[i].number, array[i].name);
  }
  
  // we know we can't do this:
  // Student array2[] = array;
  // however, we can do this:
  Student *array2 = array;
  
  // not a deep copy
  array2[0].number = -999;
  printf("%d %s\n", array[0].number, array[0].name);

  // but we can do this
  Student s = array[1];
  
  // and this is a deep copy
  s.number = 0;
  printf("%d %s\n", s.number, s.name);
  printf("%d %s\n", array[1].number, array[1].name);
  
  // which also shows the difference between these:
  f1(s);
  printf("%d %s\n", s.number, s.name);
  f2(&s);
  printf("%d %s\n", s.number, s.name);
  s = f3();
  printf("%d %s\n", s.number, s.name);
  
  return 0;
}