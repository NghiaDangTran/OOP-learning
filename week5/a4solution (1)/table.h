#ifndef _TABLE_H
#define _TABLE_H

#ifndef _REGIONS_H
typedef enum {
   FALSE,
   TRUE
} Boolean;
#endif

typedef struct TABLE Table;

typedef int (*Comparator)(void *, void *);

void table_validate( Table *table );
Table *table_create( Comparator new_comparator );
Boolean table_insert( Table *table, void *new_data );
void *table_delete( Table *table, void *target );
void table_clear( Table *table );
void *table_search( Table *table, void *target );
void * table_first( Table *table );
void * table_next( Table *table );
void table_destroy( Table *table );

#endif