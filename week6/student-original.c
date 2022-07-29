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

typedef enum BOOLEAN {
  FALSE,
  TRUE
} Boolean;

Boolean csv_to_student(char *line, Student *student)
{
  Boolean result = FALSE;
  char *token;

  // initialize the student (needed if there is invalid input)
  student->number = 0;
  student->name[0] = '\0';

  token = strtok(line, SEPARATOR);
  if (NULL != token) {
    student->number = atoi(token);
    token = strtok(NULL, SEPARATOR);
    if (NULL != token) {
      strncpy(student->name, token, MAX_NAME);
      result = TRUE;
    }
  }
  
  return result;
}

int main()
{
  char line[MAX_LINE];
  Student student;
  
  printf("Enter student numbers and names, separated by commas.\n");
  while (NULL != fgets(line, MAX_LINE, stdin)) {

    if (csv_to_student(line, &student)) {
      printf("Student number: %d\nName: %s\n", student.number, student.name);
    } else {
      fprintf(stderr, "Invalid input: %s\n", line);
    }
  }
  
  return 0;
}