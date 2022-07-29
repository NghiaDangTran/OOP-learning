#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 80
#define MAX_Length 100



typedef struct
{
char name[MAX_Length];
char contain[MAX_Length][MAX_Length];
int count;
} StringArr;
int main()
{
  StringArr alldata[100];
char c[] = "c string";

char contain[MAX_Length][MAX_Length];
strcpy(contain[0],"Edmonton");
strcpy(contain[1],"Edmonton with hat");


printf("%s",contain[1]);
    
  
  return 0;
}

// void add value in to the string array