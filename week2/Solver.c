#include <stdio.h>
#include <stdlib.h>

/**
 * Solver.c 
 *
 * COMP 2160 SECTION A02
 * ASSIGNMENT    Assignment 1, question 2
 * AUTHOR        Nghia Dang, 7863117
 * DATE          04-10-2021
 *
 * PURPOSE: a sample java program change into c progaming
 */

// a constance of max length of the array
#define MAX_COUNT 30

// initialize all function used in main
void reverseSort(int[], int);
void print_arr(int[], int, char);
int solve(int[], int[], int, int);
int rsolve(int[], int, int[], int, int, int);

/**
 * main function
 * 
 * INPUT PARAMETERS:
 *    array of number
 * OUTPUT PARAMETERS:
 *    return another array of number
 */

int main(int numParms, char *parms[])
{
    // Variable like in Java progam
    int count = 0, target;
    int *array, *solution;
    int solutionCount = 0;

    // but in here I used a int boolean to determine
    // if the main stop or not
    int user_error = 0;

    // a loop run untill the user wrong input or exit progam
    while (1)
    {
        // the user_error will check the user input good or not
        if ((user_error = scanf("%d", &count)) == 0 || user_error==EOF)
        {
            // if user enter not a number
            // print the error
            // end the loop too
            printf("This is not a number .\n");
            break;
        }
        else
        {
            if (count > MAX_COUNT)
            {
                printf("Invalid count : %d. \n", count);
            }
            else
            {
                // orther wise evrything the same with java

                array = (int *)malloc(sizeof(int) * count);
                // caution for array and solution array
                // because the java program need a dynamic array length
                // then I have to change using pointer length

                for (int i = 0; i < count; i++)
                {
                    // again check user input
                    if (scanf("%d", &array[i]) != 1)
                    {
                        printf("This is not a number.\n");

                        break;
                    }
                }
                if (scanf("%d", &target) != 1)
                {
                    // again check user input
                    printf("This is not a number.\n");

                    break;
                }

                solution = (int *)malloc(sizeof(int) * count);

                reverseSort(array, count);

                solutionCount = solve(array, solution, target, count);

                if (solutionCount > 0)
                {

                    print_arr(solution, solutionCount, 'f');
                }
                else
                {
                    printf("Count = %d :no Solution. \n", count);
                }
            }
        }
    }

    return 0;
}




///////////////////////////// end of main ////////////////////////////////////////////////////////




/**
 * reverseSort function
 * PURPOSE: rever the array 
 * INPUT PARAMETERS:
 *    the normal array and the length of it
 * OUTPUT PARAMETERS:
 *   change the array
 */

void reverseSort(int array[], int length)
{
    // everything is the same with java but 
    // now we need the extra length of the array
    int max, maxPos;
    for (int i = 0; i < length - 1; i++)
    {
        max = array[i];
        maxPos = -1;
        for (int j = i + 1; j < length; j++)
        {
            if (array[j] > max)
            {
                max = array[j];
                maxPos = j;
            }
        }
        if (maxPos > 0)
        {
            array[maxPos] = array[i];
            array[i] = max;
        }
    }
}


///////////////////////////////// end of  reverseSort /////////////////////////////////


/**
 * solve function
 * PURPOSE: the public call 
 * INPUT PARAMETERS:
 *   array , solution , target , array length 
 * OUTPUT PARAMETERS:
 *   solve the array
 */


int solve(int array[], int solution[], int target, int length)
{
    return rsolve(array, length, solution, 0, 0, target);
}


///////////////////////////////// end of  solve /////////////////////////////////




/**
 * rsolve function
 * PURPOSE: the private call 
 * INPUT PARAMETERS:
 *   array , solution , target , array length 
 * OUTPUT PARAMETERS:
 *   solve the array
 */

int rsolve(int array[], int unprocessed, int solution[], int solutionCount, int soFar, int target)
{
    int lastPos, result;

    if (soFar == target)
    {
        result = solutionCount;
    }
    else if (unprocessed == 0)
    {
        result = 0;
    }
    else
    {
        lastPos = unprocessed - 1;
        result = rsolve(array, lastPos, solution, solutionCount, soFar, target);
        if (result == 0 && soFar + array[lastPos] <= target)
        {
            solution[solutionCount] = array[lastPos];
            result = rsolve(array, unprocessed - 1, solution, solutionCount + 1, soFar + array[lastPos], target);
        }
    }

    return result;
}

///////////////////////////////// end of  rsolve /////////////////////////////////




/**
 * print_arr function
 * PURPOSE: this will print array in foward or rever direction
 * INPUT PARAMETERS:
 *   array , length , direction
 * OUTPUT PARAMETERS:
 *   print the array in the direction we want
 */


void print_arr(int arr[], int lenght, char direction)

{

   

    if (direction == 'f')
    {

        for (int i = 0; i < lenght; i++)

        {
            printf("%d, ", arr[i]);
        }
    }

    else
    {
        for (int i = lenght - 1; i >= 0; i--)

        {
            printf("%d, ", arr[i]);
        }
    }

    printf("\n");
}
///////////////////////////////// end of  print_arr /////////////////////////////////

