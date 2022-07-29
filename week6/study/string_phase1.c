// this version checks the return values from malloc, and cleans up on error

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct STRING
{
  int size;
  char *the_string;
};

typedef struct STRING String;


String * new_string( char *init )
{
  String *new_string = NULL;
  
  new_string = malloc( sizeof( String ) );
  
  // always make sure the allocation succeeded
  if ( NULL != new_string )
  {
    new_string->the_string = malloc( strlen( init ) + 1 );
    
    if ( NULL != new_string->the_string )
    {
      strcpy( new_string->the_string, init );
      new_string->size = strlen( new_string->the_string );
    }
    
    // not enough memory, clean up
    else
    {
      free( new_string );
      // set ptr to NULL so we don't illegally reference it
      new_string = NULL;
    }
  }
  
  // don't use a struct declaration...
  // struct assignment doesn't do deep copying
  return new_string;
}

String * destroy_string( String *the_string )
{
  // ordering is VERY important
  free( the_string->the_string );
  free( the_string );
  the_string = NULL;

  return the_string;
}

void print_string( String *the_string )
{
  printf( "%*s\n", the_string->size, the_string->the_string );
}

char char_at( String *the_string, int index )
{
  return the_string->the_string[index];
}

String * concat( String *string1, String *string2 )
{
  String *new_string = NULL;
  
  new_string = malloc( sizeof( String ) );
  
  if ( NULL != new_string )
  {
    new_string->size = string1->size + string2->size;
    new_string->the_string = malloc( new_string->size + 1 );
    
    if ( NULL != new_string->the_string )
    {
      strcpy( new_string->the_string, string1->the_string );
      strcpy( &(new_string->the_string[string1->size]), string2->the_string );
    }
    else
    {
      free( new_string );
      new_string = NULL;
    }
  }
  
  return new_string;
}
