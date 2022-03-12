#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "table.h"

typedef struct NODE Node;

struct NODE
{
  void *data;
  Node *next;
};

struct TABLE
{
  Node *top;
  Node *traverseNode;

  int num_nodes;
  int num_traversals;

  Comparator comparator;
};

// used to track testing values

void table_validate( Table *table )
{
  assert( NULL != table );
  if ( table->num_nodes == 0 )
    assert( table->top == NULL );
  else if ( table->num_nodes == 1 )
    assert( table->top->next == NULL );
  else // num_nodes > 1
    assert( table->top != NULL && table->top->next != NULL );
  // how far should we really go???
}

Table *table_create( Comparator new_comparator )
{
  Table *table;
  
  table = malloc( sizeof(Table) );
  
  if ( NULL != table )
  {
    table->top = NULL;
    table->traverseNode = NULL;
    
    table->num_nodes = 0;
    table->num_traversals = 0;

    table->comparator = new_comparator;
  }
  
  return table;
}

Boolean table_insert( Table *table, void *new_data )
{
  Boolean rc = FALSE;
  Node *newNode = NULL;
  Node *curr;
  Node *prev = NULL;
  
  table_validate( table );
  
  assert( new_data != NULL );
  if ( new_data )
  {
    newNode = (Node *)malloc( sizeof( Node ) );
    assert( newNode != NULL );
    
    if ( newNode )
    {
      newNode->data = new_data;
      
      // ordered insertion if a comparator is defined
      if ( NULL != table->comparator )
      {
        curr = table->top;
        assert( (curr == NULL) || (curr->data != NULL) );
        while ( curr != NULL && table->comparator( new_data, curr->data ) > 0 )
        {
          prev = curr;
          curr = curr->next;
        }
      }
      
      if ( NULL == prev )
      {
        // add to start
        newNode->next = table->top;
        table->top = newNode;        
      }
      else
      {
        // insert
        newNode->next = prev->next;
        prev->next = newNode;
      }
      table->num_nodes++;
        
      rc = TRUE;
        
      // make sure the list is stable
      table_validate( table );
    }
  }
  
  return rc;
}

void table_clear( Table *table )
{
  Node *curr;
  
  table_validate( table );
  
  curr = table->top;
  while ( table->top != NULL )
  {
    table->top = table->top->next;
    
    assert( curr );
    free( curr );
    
    curr = table->top;
    
    table->num_nodes--;
  }
  
  table_validate( table );
}

// remove an element with the given string
void *table_delete( Table *table, void *target )
{
  void *deleted = NULL;
  Node *curr;
  Node *prev = NULL;
  
  table_validate( table );
  assert( NULL != table->comparator );
  
  assert( target != NULL );

  if ( target != NULL )
  {
    curr = table->top;
    assert( (curr == NULL) || (curr->data != NULL) );
    while ( curr != NULL && table->comparator( target, curr->data ) != 0 )
    {
      prev = curr;
      curr = curr->next;
    }
    
    if ( curr != NULL )
    {
      if ( prev != NULL )
        prev->next = curr->next;
      else
        table->top = curr->next;
      
      deleted = curr->data;
      free( curr );
      table->num_nodes--;
      
      // make sure the list is stable
      table_validate( table );
    }
  }
  
  return deleted;
}

// tells us whether or not the given string is in the list
void *table_search( Table *table, void *target )
{
  void *found = NULL;
  Node *curr;
  int search_count = 0;     // how far in the list do we go?
  
  table_validate( table );
  assert( NULL != table->comparator );
  
  assert( target != NULL );
  if ( target != NULL )
  {
    curr = table->top;

    while ( curr != NULL && !found )
    {
      assert( curr->data != NULL );
      if ( table->comparator( target, curr->data ) == 0 )
      {
        found = curr->data;
        
        // make sure we're still in our list...
        assert( search_count <= table->num_nodes );
      }
      
      else
      {
        curr = curr->next;
        search_count++;
      }
    }
  }
  
  // if it's not found then we should be at the end of the list
  assert( NULL != found || (search_count == table->num_nodes) );
  
  return found;
}


// starts a list traversal by getting the data at top
void * table_first( Table *table )
{
  void *item = NULL;
  
  table_validate( table );
  
  if ( table->top != NULL )
  {
    table->traverseNode = table->top->next;
    item = table->top->data;
    assert( item != NULL );
    
    table->num_traversals = 1;
    // make sure we're still in our list...
    assert( table->num_traversals <= table->num_nodes );
  }
  
  // this isn't the safest (caller can modify the string) but we don't have to worry about extra memory mgmt...
  return item;
}


// gets the data at the current traversal node and increments the traversal
void * table_next( Table *table )
{
  void *item = NULL;
  
  table_validate( table );
  
  // no need to go past the end of the list...
  if ( table->traverseNode != NULL )
  {
    item = table->traverseNode->data;
    // if the node was freed, the item will have been set to NULL!
    assert( item != NULL );

    table->traverseNode = table->traverseNode->next;
    
    table->num_traversals++;
    // make sure we're still in our list...
    assert( table->num_traversals <= table->num_nodes );
  }
  
  // this isn't the safest (caller can modify the string) but we don't have to worry about extra memory mgmt...
  return item;
}

void table_destroy( Table *table )
{
  table_clear(table);
  
  free(table);
}
