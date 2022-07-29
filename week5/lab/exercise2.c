#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 2
#define NUM_INDEX 100
#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))
int Containarr(char[][NUM_INDEX][NUM_INDEX], int);
int main()
{

  char data[NUM_INDEX][MAX_LINE];
  char input[MAX_LINE];
  // *** declare more variables as required
  int location = 0;
  char dataprocess[NUM_INDEX][NUM_INDEX][NUM_INDEX];
  char str[80] = "Ab manitoba";
  const char s[] = " ";
  char *token;

  
  // for(int i=0;i<NELEMS(arr);i++)
  // {
  //   arr[i]=-1;
  // }
  // printf("%d \n", Containarr(arr,NELEMS(arr)));

  // fill the array with empty strings
  for (int i = 0; i < NUM_INDEX; i++)
  {
    data[i][0] = '\0';
    // dataprocess[i][0][0]="asdasd";
    for (int j = 0; j < NUM_INDEX; j++)
      strcpy(dataprocess[i][j], "\0");
  }
  // strcpy(dataprocess[0][Containarr(dataprocess, 0)], "type");
  // strcpy(dataprocess[0][Containarr(dataprocess, 0)], "123");
  // printf("%syes\n", (dataprocess[0][1]));

  // printf("\n%d \n", Containarr(dataprocess, 0));

  // *** perform the input and processing

  while (NULL != fgets(input, MAX_LINE, stdin))
  {
      
// token = strtok(input, s);
//     location = atoi(token);

  //   
  //   token = strtok(NULL, s);
  // strcpy(dataprocess[location][Containarr(dataprocess, location)], token);
  // puts(input);
 input[strlen(input) - 1] = '\0';
  break;
  }

      printf("%s", input);

  // for(int i=0;i<NUM_INDEX;i++)
  // {

  //   printf(" %s ",dataprocess[0][i]);
  // }

  return 0;
}





int Containarr(char data[][NUM_INDEX][NUM_INDEX], int at)
{
  int result = 0;

  for (int j = 0; j < NUM_INDEX; j++)
  {
    if (strlen(data[at][j]) > 0)
    {

      result += 1;
    }
  }
  return result;
}