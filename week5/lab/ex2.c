#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 80
#define NUM_INDEX 100
int Containarr(char[][NUM_INDEX][NUM_INDEX], int);

int main()
{
    char data[NUM_INDEX][MAX_LINE];
    char input[MAX_LINE] = "\0";
    // *** declare more variables as required

    int location = 0;
    char dataprocess[NUM_INDEX][NUM_INDEX][NUM_INDEX];
    const char s[] = " ";
    char *token;

    // fill the array with empty strings
    for (int i = 0; i < NUM_INDEX; i++)
    {
        data[i][0] = '\0';
        for (int j = 0; j < NUM_INDEX; j++)
            strcpy(dataprocess[i][j], "\0");
    }

    // *** perform the input and processing

    while (NULL != fgets(input, MAX_LINE, stdin))
    {
        if (strcmp(input, "quit\n") == 0)
        {
            break;
        }

        token = strtok(input, s);
        location = atoi(token);

        token = strtok(NULL, "\n");
        if (token[strlen(token) - 1] == '\n')
            token[strlen(token) - 1] = '\0';
        strcpy(dataprocess[location][Containarr(dataprocess, location)], token);

        input[strlen(input) - 1] = '\0';
    }

    for (int i = 0; i < NUM_INDEX; i++)
    {
        if (strlen(dataprocess[i][0]) > 0)
        {
            printf("%02d ", i);
            for (int j = 0; j < Containarr(dataprocess, i); j++)
            {

                printf("%s,", dataprocess[i][j]);
            }
            printf("\n");
        }
    }

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
