// this version uses contracts to validate arguments and the state of a String

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct STRING
{
  int size;
  char *the_string;
};

typedef struct STRING String;

// lets me track strings so I know they're all deleted properly
int string_count = 0;

// the invariant
void validate_string(String *the_string)
{
  assert(NULL != the_string);
  assert(NULL != the_string->the_string);
  assert(the_string->size >= 0);
  // what is a String?
  assert('\0' == the_string->the_string[the_string->size]);
  assert(the_string->size == strlen(the_string->the_string));
}

String *new_string(char *init)
{
  String *new_string = NULL;

  assert(NULL != init);

  new_string = malloc(sizeof(String));
  // always check allocations...
  assert(NULL != new_string);

  // always make sure the allocation succeeded
  if (NULL != new_string)
  {
    new_string->the_string = malloc(strlen(init) + 1);
    assert(NULL != new_string->the_string);

    if (NULL != new_string->the_string)
    {
      strcpy(new_string->the_string, init);
      new_string->size = strlen(new_string->the_string);

      assert(new_string->size == strlen(init));

      string_count++;
    }

    // not enough memory, clean up
    else
    {
      free(new_string);
      // set ptr to NULL so we don't illegally reference it
      new_string = NULL;
    }
  }

  validate_string(new_string);

  // don't use a struct declaration...
  // struct assignment doesn't do deep copying
  return new_string;
}

String *destroy_string(String *the_string)
{
  validate_string(the_string);
  assert(string_count > 0);

  // ordering is VERY important
  if (NULL != the_string)
  {
    if (NULL != the_string->the_string)
    {
      free(the_string->the_string);
    }
    free(the_string);
  }
  the_string = NULL;

  string_count--;

  return the_string;
}

void print_string(String *the_string)
{
  validate_string(the_string);

  // ALWAYS check pointers before dereferencing to make sure we don't crash!
  if (NULL != the_string && NULL != the_string->the_string)
    printf("%*s\n", the_string->size, the_string->the_string);
}

char char_at(String *the_string, int index)
{
  char theChar = '\0'; // assume null terminator for failure conditions

  validate_string(the_string);
  // index must be in the String
  assert(index >= 0);
  assert(index < the_string->size);

  // ALWAYS check pointers before dereferencing to make sure we don't crash!
  if (NULL != the_string && NULL != the_string->the_string)
  {
    // we have to make sure that we don't go out of bounds!
    if (index >= 0 && index < the_string->size)
      theChar = the_string->the_string[index];
  }

  return theChar;
}

String *concat(String *string1, String *string2)
{
  String *new_string = NULL;

  validate_string(string1);
  validate_string(string2);

  // ALWAYS check pointers before dereferencing to make sure we don't crash!
  if (NULL != string1 && NULL != string1->the_string && NULL != string2 && NULL != string2->the_string)
  {
    new_string = malloc(sizeof(String));
    assert(NULL != new_string);

    if (NULL != new_string)
    {
      new_string->size = string1->size + string2->size;
      new_string->the_string = malloc(new_string->size + 1);
      assert(NULL != new_string->the_string);

      if (NULL != new_string->the_string)
      {
        strcpy(new_string->the_string, string1->the_string);
        strcpy(&(new_string->the_string[string1->size]), string2->the_string);

        validate_string(new_string);

        // verify that the strings are in the correct locations
        // (nothing was overwritten by one of the strcpy)
        assert(0 == strncmp(new_string->the_string, string1->the_string, string1->size));
        assert(0 == strcmp(new_string->the_string + string1->size, string2->the_string));

        string_count++;
      }
      else
      {
        free(new_string);
        new_string = NULL;
      }
    }
  }

  return new_string;
}
