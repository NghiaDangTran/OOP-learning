// this version adds some typical unit tests to verify the behaviour of String

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
void validate_string( String *the_string )
{
  assert( NULL != the_string );
  assert( NULL != the_string->the_string );
  assert( the_string->size >= 0 );
  // what is a String?
  assert( '\0' == the_string->the_string[the_string->size] );
  assert( the_string->size == strlen( the_string->the_string ) );
}


String * new_string( char *init )
{
  String *new_string = NULL;
  
  assert( NULL != init );
  
  new_string = malloc( sizeof( String ) );
  // always check allocations...
  assert( NULL != new_string );
  
  // always make sure the allocation succeeded
  if ( NULL != new_string )
  {
    new_string->the_string = malloc( strlen( init ) + 1 );
    assert( NULL != new_string->the_string );
    
    if ( NULL != new_string->the_string )
    {
      strcpy( new_string->the_string, init );
      new_string->size = strlen( new_string->the_string );
      
      assert( new_string->size == strlen( init ) );
      
      string_count++;
    }
    
    // not enough memory, clean up
    else
    {
      free( new_string );
      // set ptr to NULL so we don't illegally reference it
      new_string = NULL;
    }
  }
  
  validate_string( new_string );
  
  // don't use a struct declaration...
  // struct assignment doesn't do deep copying
  return new_string;
}

String * destroy_string( String *the_string )
{
  validate_string( the_string );
  assert( string_count > 0 );
  
  // ordering is VERY important
  if ( NULL != the_string ) {
    if ( NULL != the_string->the_string ) {
      free( the_string->the_string );
    }
    free( the_string );
  }
  the_string = NULL;
  
  string_count--;
  
  return the_string;
}

void print_string( String *the_string )
{
  validate_string( the_string );
  
  // ALWAYS check pointers before dereferencing to make sure we don't crash!
  if ( NULL != the_string && NULL != the_string->the_string )
    printf( "%*s\n", the_string->size, the_string->the_string );
}

char char_at( String *the_string, int index )
{
  char theChar = '\0';     // assume null terminator for failure conditions
  
  validate_string( the_string );
  // index must be in the String
  assert( index >= 0 );
  assert( index < the_string->size );
  
  // ALWAYS check pointers before dereferencing to make sure we don't crash!
  if ( NULL != the_string && NULL != the_string->the_string )
  {
    // we have to make sure that we don't go out of bounds!
    if ( index >= 0 && index < the_string->size )
      theChar = the_string->the_string[index];
  }

  return theChar;
}

String * concat( String *string1, String *string2 )
{
  String *new_string = NULL;
  
  validate_string( string1 );
  validate_string( string2 );
  
  // ALWAYS check pointers before dereferencing to make sure we don't crash!
  if ( NULL != string1 && NULL != string1->the_string && NULL != string2 && NULL != string2->the_string )
  {
    new_string = malloc( sizeof( String ) );
    assert( NULL != new_string );
  
    if ( NULL != new_string )
    {
      new_string->size = string1->size + string2->size;
      new_string->the_string = malloc( new_string->size + 1 );
      assert( NULL != new_string->the_string );
      
      if ( NULL != new_string->the_string )
      {
        strcpy( new_string->the_string, string1->the_string );
        strcpy( &(new_string->the_string[string1->size]), string2->the_string );
        
        validate_string( new_string );
        
        // verify that the strings are in the correct locations
        // (nothing was overwritten by one of the strcpy)
        assert( 0 == strncmp(new_string->the_string, string1->the_string, string1->size) );
        assert( 0 == strcmp(new_string->the_string + string1->size, string2->the_string) );
        
        string_count++;
      }
      else
      {
        free( new_string );
        new_string = NULL;
      }
    }
  }
  
  return new_string;
}

// we need this to automatically verify the contents of a String

int to_array( String *string, char *array, int max_len )
{
  validate_string( string );
  assert( NULL != array );
  assert( max_len >= 0 );
  
  int len = 0;
  
  while (len < max_len-1 && '\0' != string->the_string[len]) {
    // question: should we be using string[len] directly, or char_at?
    array[len] = char_at( string, len );
    len++;
  }
  
  assert( len < max_len );
  array[len] = '\0';
  
  validate_string( string );
  
  return len;
}

int main( int argc, char *argv[] )
{
  // how to test:
  //  - consider all of the ways a String may be used (black box)
  //  - consider all of the "tricky" parts of the implementation (white box)
  // note: assert() is not the best mechanism for automated testing
  // also: these should be divided into smaller functions

  String *test1, *test2, *test3, *test4, *test5, *test6;
#define MAX_C_STR 80
  char c_str[MAX_C_STR];
  int len;

  /*** "Typical" usage ***/
  
  test1 = new_string("hello, world!"); // length = 13
  test2 = new_string("bye for now.");  // length = 12
  test3 = new_string(" ");             // length = 1
  
  printf("Testing printing strings:\n\n");
  printf("hello world: ");
  print_string(test1);
  printf("bye for now: ");
  print_string(test2);
  printf("space: ");
  print_string(test3);
  printf("\nprinting tests completed.\n");
  
  printf("\nTesting char_at:\n");
  
  assert('h' == char_at(test1, 0));
  assert(',' == char_at(test1, 5));
  assert('!' == char_at(test1, 12));
  assert('f' == char_at(test2, 4));
  assert('.' == char_at(test2, 11));
  assert(' ' == char_at(test3, 0));
  
  printf("char_at tests completed.\n");
  
  printf("\nTesting string contents:\n");

  len = to_array(test1, c_str, MAX_C_STR);
  assert(13 == len);
  assert(13 == strlen(c_str));
  assert(0 == strcmp("hello, world!", c_str));

  len = to_array(test2, c_str, MAX_C_STR);
  assert(12 == len);
  assert(12 == strlen(c_str));
  assert(0 == strcmp("bye for now.", c_str));

  len = to_array(test3, c_str, MAX_C_STR);
  assert(1 == len);
  assert(1 == strlen(c_str));
  assert(0 == strcmp(" ", c_str));

  len = to_array(test1, c_str, 10);
  assert(9 == len);
  assert(9 == strlen(c_str));
  assert(0 == strcmp("hello, wo", c_str));
  
  printf("to_array tests completed.\n");

  printf("\nTesting string concatenation:\n");

  test4 = concat(test1, test3);
  len = to_array(test4, c_str, MAX_C_STR);
  assert(14 == len);
  assert(14 == strlen(c_str));
  assert(0 == strcmp("hello, world! ", c_str));

  test5 = concat(test4, test2);
  len = to_array(test5, c_str, MAX_C_STR);
  assert(26 == len);
  assert(26 == strlen(c_str));
  assert(0 == strcmp("hello, world! bye for now.", c_str));

  // concat a string to itself
  test6 = concat(test2, test2);
  len = to_array(test6, c_str, MAX_C_STR);
  assert(24 == len);
  assert(24 == strlen(c_str));
  assert(0 == strcmp("bye for now.bye for now.", c_str));

  printf("concatenation tests completed.\n");
  
  printf("\nDestroying strings and checking reference count.\n");
  
  test6 = destroy_string(test6);
  assert(NULL == test6);
  test5 = destroy_string(test5);
  assert(NULL == test5);
  test4 = destroy_string(test4);
  assert(NULL == test4);
  test3 = destroy_string(test3);
  assert(NULL == test3);
  test2 = destroy_string(test2);
  assert(NULL == test2);
  test1 = destroy_string(test1);
  assert(NULL == test1);
  assert(0 == string_count);

  printf("string destruction completed.\n");

  /*** Edge cases ***/

  // 1-char strings were already tested
  // char at beginning and end were tested
  
  printf("\nTesting empty strings:\n");
  
  test1 = new_string("");
  test2 = new_string("not empty");
  
  printf("Testing printing empty strings:\n");
  print_string(test1);

  printf("\nTesting empty string contents:\n");

  len = to_array(test1, c_str, MAX_C_STR);
  assert(0 == len);
  assert(0 == strlen(c_str));
  assert('\0' == c_str[0]);

  // concat empty to empty
  test3 = concat(test1, test1);
  len = to_array(test3, c_str, MAX_C_STR);
  assert(0 == len);
  assert(0 == strlen(c_str));
  assert('\0' == c_str[0]);

  // concat empty to not empty, both sides
  test4 = concat(test1, test2);
  test5 = concat(test4, test1);
  len = to_array(test5, c_str, MAX_C_STR);
  assert(9 == len);
  assert(9 == strlen(c_str));
  assert(0 == strcmp("not empty", c_str));

  printf("\nDestroying empty strings.\n");

  test5 = destroy_string(test5);
  assert(NULL == test5);
  test4 = destroy_string(test4);
  assert(NULL == test4);
  test3 = destroy_string(test3);
  assert(NULL == test3);
  test2 = destroy_string(test2);
  assert(NULL == test2);
  test1 = destroy_string(test1);
  assert(NULL == test1);
  assert(0 == string_count);

  printf("\nEmpty string tests completed.\n");
  
  /*** Special cases ***/
  
  printf("\nTesting a string with an embedded '\\0':\n");
  
  test1 = new_string("hello\0world");

  len = to_array(test1, c_str, MAX_C_STR);
  assert(5 == len);
  assert(5 == strlen(c_str));
  assert(0 == strcmp("hello", c_str));
    
  test1 = destroy_string(test1);
  assert(NULL == test1);
  assert(0 == string_count);
  
  printf("\nSpecial case tests completed.\n");

  /*** Invalid cases ***/

#ifdef NDEBUG
  printf("\nTesting invalid cases.\n");

  // Here we could test things like passing NULL to new_string, concat, etc.
  // We could also pass values out-of-range to char_at.
  // Problem: we can only do this if we turn off assertions. But then none
  //          of our test results will be verified!

  printf("\nInvalid case tests completed.\n");
#endif  

  printf("\nChecking string_count.\n\n");
  assert(0 == string_count);
  
  printf("Tests successfully completed.\n");
  
  return 0;
}
