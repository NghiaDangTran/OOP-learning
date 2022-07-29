#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * Duplicates.c
 *
 * COMP 2160 SECTION A02
 * ASSIGNMENT    Assignment 1, question 1
 * AUTHOR        Nghia Dang, 7863117
 * DATE          04-10-2021
 *
 * PURPOSE: a sample java program change into c progaming
 */



/* global variable declaration */

int stringLenght(char[]);
void testCountDuplicateWords(int, char[]);
int countDuplicateWords(char[]);
void append(char[], char);
void substring(char[], char[], int, int);
int compare(char[], char[]);
int findWord(char[], char[]);



// a constance of max length of the array
int tests_Executed = 0;
int tests_Failed = 0;
#define MAX_WORD_LENGTH 15




/**
 * main function
 * 
 * all the test case
 */



int main()
{

  printf("Testing typical cases\n");
  testCountDuplicateWords(0, "hello world");
  testCountDuplicateWords(0, "bye-bye");
  testCountDuplicateWords(1, "the quick brown foxes jumped over the lazy dogs");
  testCountDuplicateWords(0, "The quick brown foxes jumped over the lazy dogs");
  testCountDuplicateWords(2, "A palindrome: a man a plan a canal panama");
  testCountDuplicateWords(8, "I felt happy because I saw the others were happy and because I knew I should feel happy but I wasnt really happy");
  testCountDuplicateWords(3, "One fish two fish\nred fish blue\nfish");
  testCountDuplicateWords(5, "doo be \t doo be \t doo be \t  doo");
  testCountDuplicateWords(8, "... -- -- -- ...\n... -- -- -- ...");
  testCountDuplicateWords(26, "a b c d e f g h i j k l m n o p q r s t u v w x y z a b c d e f g h i j k l m n o p q r s t u v w x y z");
  printf(" \nTesting empty cases\n");
  testCountDuplicateWords(0, "");
  testCountDuplicateWords(0, " ");
  testCountDuplicateWords(0, "\t \t");
  testCountDuplicateWords(0, "   \n  \n  ");
  printf(" \nTesting invalid cases\n");
  testCountDuplicateWords(-1, "the word antidisestablishmentarianism is very long but antidisestablishmentarianism is a political movement");
  testCountDuplicateWords(-1, "abcdefghijabcdef");
  testCountDuplicateWords(0, "abcdefghijabcde");
  printf(" \nTesting edge cases\n");
  testCountDuplicateWords(1, "go Jets go");
  testCountDuplicateWords(2, "tomato tomato potato potato");
  testCountDuplicateWords(2, " tomato tomato potato potato ");
  testCountDuplicateWords(7, "buffalo buffalo buffalo buffalo buffalo buffalo buffalo buffalo");
  printf(" \nThese tests will be opposite in the C version\n");
  testCountDuplicateWords(1, "In Java, the strings may contain \0 in the interior");
  testCountDuplicateWords(0, "In C, the strings cannot contain \0 in the interior");

  printf("\n Total number of tests executed: %d\n ",tests_Executed);
  printf("\n Number of tests passed: %d \n", (tests_Executed - tests_Failed));
  printf("\nNumber of tests failed: %d  \n",tests_Failed);
  return 0;
}
/////////////////////////////////////// end of main ///////////////////////// 






/**
 * testCountDuplicateWords function
 * PURPOSE: count the fail and succes of evry input
 * INPUT PARAMETERS:
 *   expected number to pass  and the string 
 * OUTPUT PARAMETERS:
 *   nonce
 */


void testCountDuplicateWords(int expected, char str[])
{
// this is the same with java program
  int result = countDuplicateWords(str);

  if (result == expected)
  {
    printf("Passed:  %d  from %s \n", result, str);
    
  }
  else
  {

    printf("FAILED:  %d  instead of  %d from  %s \n ", result, expected, str);

    tests_Failed++;
  }

  tests_Executed++;
}
////////////////////////////// end of testCountDuplicateWords//////////////////////////////////



/**
 * countDuplicateWords function
 * PURPOSE: count the number of duplicate words in string
 * INPUT PARAMETERS:
 *  string
 * OUTPUT PARAMETERS:
 *   return the number of the same words
 */

int countDuplicateWords(char str[])
{

  // same variables with java
  int count = 0;
  char word[1000] = "\0";
  int pos;
  char currentChar = '\0';

  // this string is for the substring function
  char copy[1000]= "\0";

  pos = 0;
  while (pos < stringLenght(str) && count >= 0)
  {
    currentChar = str[pos];
    
    if (isspace(currentChar))
    {

      if (stringLenght(word) > 0)
      {
        substring(str, copy, pos, stringLenght(str));
        

        if (findWord(copy, word))
        {

          count++;
        }

        substring(word, word, stringLenght(word), stringLenght(word));
        // this will clear all word in the string
      }
    }
    else
    {
      if (stringLenght(word) >= MAX_WORD_LENGTH)
      {
        count = -1;
      }
      else
      {

        append(word, currentChar);
        // we cant do string arithmetic in c so I add another append function 
      }
    }
    pos++;
  }

  return count;
}

///////////////////////////////////// end of countDuplicateWords ///////////////////////////////






/**
 * findWord function
 * PURPOSE: find the string that may contain in word string
 * INPUT PARAMETERS:
 *  string , string 
 * OUTPUT PARAMETERS:
 *  return boolean true if we found that words
 */


int findWord(char str[], char word[])
{
  char checkWord[1000] = "\0";
  int checkPos = 0;
  int dontCheckWord = 0, found = 0; // boolean value 0 =false, 1= true
  char checkChar = '\0';
  dontCheckWord = 0;


  while (checkPos < stringLenght(str) && found == 0)
  {
    checkChar = str[checkPos];

    if (isspace(checkChar))
    {
      // compare will check if 2 string is the same
      if (compare(word, checkWord) && !dontCheckWord)
      {

        found = 1;
      }
      dontCheckWord = 0;
      substring(checkWord, checkWord, stringLenght(checkWord), stringLenght(checkWord));
    }
    else
    {
      if (stringLenght(checkWord) >= stringLenght(word))
      {

        dontCheckWord = 1;
      }

      else
      {

        append(checkWord, checkChar);
      }
    }
    checkPos = checkPos + 1;
  }

  if (!found && !dontCheckWord && stringLenght(word) > 0)
    found = compare(word, checkWord);

  return found;
}
//////////////////////////////////////////// end of findWord ///////////////////////////////





/**
 * stringLenght function
 * PURPOSE: return the length of the string
 * INPUT PARAMETERS:
 *  string 
 * OUTPUT PARAMETERS:
 *  out put of where the '\0'
 */

int stringLenght(char str[])
{
  int result = 0;

  while (str[result] != '\0')
  { // count the result untill we find the '\0'
    result++;
  }
  return result;
}


//////////////////////////////////////////// end of stringLenght ///////////////////////////////////////





/**
 * substring function
 * PURPOSE: will copy the str from the start to end
 * or can use to delete the string
 * INPUT PARAMETERS:
 *  string original, string copy , start position, end position
 * OUTPUT PARAMETERS:
 *  nonce
 */



void substring(char str[], char copy[], int start, int end)
{
  int at = 0;

  while (at < end)
  {
    copy[at] = str[start + at];
    at++;
  }
  copy[at] = '\0';
}

//////////////////////////////////////////// end of substring ///////////////////////////////////////



/**
 * append function
 * PURPOSE: at one more char into the string 
 * 
 * INPUT PARAMETERS:
 *  string original,and the char to add
 * OUTPUT PARAMETERS:
 *  nonce
 */

void append(char str[], char value)
{
  str[stringLenght(str)] = value;
  str[stringLenght(str) + 1] = '\0';
}

//////////////////////////////////////////// end of append ///////////////////////////////////////




/**
 * compare function
 * PURPOSE: a boolean to check if the 2 string is the same
 * 
 * INPUT PARAMETERS:
 *  string original,and the second string
 * OUTPUT PARAMETERS:
 *  true , false
 */ 
int compare(char str1[], char str2[])
{
  if (stringLenght(str1) != stringLenght(str2))
    return 0;
  for (int i = 0; i < stringLenght(str1); i++)
  {
    if (str1[i] != str2[i])
      return 0;
  }

  return 1;
}