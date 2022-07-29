// this code is VERY incomplete and VERY unsafe!

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
  new_string->the_string = malloc( strlen( init ) + 1 );
    
  strcpy( new_string->the_string, init );
  new_string->size = strlen( new_string->the_string );

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
  
  new_string->size = string1->size + string2->size;
  new_string->the_string = malloc( new_string->size + 1 );
    
  strcpy( new_string->the_string, string1->the_string );
  strcpy( &(new_string->the_string[string1->size]), string2->the_string );
  
  return new_string;
}

int main()
{
  String *s1 = new_string("hello");
  String *s2 = new_string(" ");
  String *s3 = new_string("world");
  String *s4;
  
  print_string(s1);
  print_string(s2);
  print_string(s3);
  
  printf("charAt: *%c*%c*%c*\n", char_at(s1, 4), char_at(s2, 1), char_at(s3,2));
  
  s4 = concat(s1, s2);
  print_string(s4);
  
  destroy_string(s1);
  s1 = concat(s4, s3);
  print_string(s1);
  
  destroy_string(s2);
  destroy_string(s3);
  destroy_string(s4);
}