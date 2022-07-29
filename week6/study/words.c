#include <stdio.h>
#include <string.h>

#define MAX_LINE 80
const char SEPARATOR[] = " \n";

int main()
{
  char line[MAX_LINE];
  char *token;
  int word_count;
  
  while (NULL != fgets(line, MAX_LINE, stdin)) {
    word_count = 0;
    token = strtok(line, SEPARATOR);
    while (NULL != token) {
      printf("%02d: *%s*\n", word_count, token);
      word_count++;
      token = strtok(NULL, SEPARATOR);
    }
    printf("Total number of words on the line: %d\n", word_count);
  }
  
  return 0;
}