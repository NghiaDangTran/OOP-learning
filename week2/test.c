#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int num1;
    int l = 0;

    while (l == 0)
    { //Checking l, if it is zero or not, if zero running loop again.
        printf("Invalid input. Please enter a number.");
        l = scanf("%f", &num1); //Storing Return Value of scanf in l
    }
    return 0;
}