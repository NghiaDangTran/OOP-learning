#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// much of this code comes from student.c

#define MAX_LINE 80
#define MAX_NAME 40

const char SEPARATOR[] = ",\n";

typedef struct STUDENT {
  int number;
  char name[MAX_NAME];
} Student;

int main()
{
  Student *students;
  int array_len, i;
  char line[MAX_LINE];
  char *token;
  
  printf("How many students do you want to enter? ");
  line[0] = '\0';
  fgets(line, MAX_LINE, stdin);
  array_len = atoi(line);
  
  // use calloc to initialize each student to empty
  students = calloc(array_len, sizeof(Student));
  
  printf("Enter student numbers and names, separated by commas.\n");
  for (i = 0; i < array_len; i++) {
    if (NULL == fgets(line, MAX_LINE, stdin)) {
      fprintf(stderr, "Unexpected end of file\n");
    } else {

      // don't need initialize the student (b/c we used calloc)
      // student.number = 0;
      // student.name[0] = '\0';

      token = strtok(line, SEPARATOR);
      if (NULL != token) {
        students[i].number = atoi(token);
        token = strtok(NULL, SEPARATOR);
        if (NULL != token) {
          strncpy(students[i].name, token, MAX_NAME);
        }
      }
    }
  }
  
  // if (i < array_len) error: not enough students entered!
  
  for (int i = 0; i < array_len; i++) {
    printf("Student %3d: %s %d\n", (i+1), students[i].name, students[i].number);
  }

  free(students);
  
  return 0;
}