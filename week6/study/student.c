#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 80
#define MAX_NAME 40
const char SEPARATOR[] = ",\n";

typedef struct STUDENT {
  int number;
  char name[MAX_NAME];
} Student;

int main()
{
  char line[MAX_LINE];
  char *token;
  Student student;
  
  printf("Enter student numbers and names, separated by commas.\n");
  while (NULL != fgets(line, MAX_LINE, stdin)) {

    // initialize the student (needed if there is invalid input)
    student.number = 0;
    student.name[0] = '\0';

    token = strtok(line, SEPARATOR);
    if (NULL != token) {
      student.number = atoi(token);
      token = strtok(NULL, SEPARATOR);
      if (NULL != token) {
        strncpy(student.name, token, MAX_NAME);
      }
    }
    
    printf("Student number: %d\nName: %s\n", student.number, student.name);
  }
  
  return 0;
}