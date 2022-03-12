#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "map.h"
#include "table.h"

typedef struct {
	char *key;
	void *value;
} MapEntry;

static int compare_keys(void *entry1, void *entry2)
{
	return strcmp(((MapEntry *)entry1)->key, ((MapEntry *)entry2)->key);
}

static void validate_entry(MapEntry *e)
{
	assert(NULL != e);
	assert(NULL != e->key);
	assert(strlen(e->key) > 0); // just force key to be scanned
}

Map *map_create()
{
	return table_create(compare_keys);
}

int map_set(Map *map, const char *key, void *value)
{
	MapEntry *entry;
	int done = 0;
	int rc = 1;
	
	assert(NULL != map);
	assert(NULL != key);

	entry = table_first(map);
	while (NULL != entry && !done) {
		if (strcmp(entry->key, key) == 0) {
			done = 1;
		}
		entry = table_next(map);
	}
	
	if (NULL == entry) {
		entry = malloc(sizeof(MapEntry));

		if (NULL == entry) {
			rc = 0;

		} else {
			entry->key = malloc(strlen(key) + 1);

			if (NULL != entry->key) {

				strcpy(entry->key, key);
				rc = table_insert(map, entry);
				validate_entry(entry);

				if (!rc) {
					free(entry->key);
					free(entry);
				}

			} else {
				free(entry);
			}
		}
	}
	
	if (rc) {
		entry->value = value;
	}
	
	return rc;
}

void *map_get(Map *map, const char *key)
{
	MapEntry *entry;
	int done = 0;
	void *value = NULL;
	
	assert(NULL != map);
	assert(NULL != key);
	
	entry = table_first(map);
	while (NULL != entry && !done) {
		validate_entry(entry);

		if (strcmp(entry->key, key) == 0) {
			done = 1;
		} else {
			entry = table_next(map);
		}

	}
	
	if (NULL != entry) {
		value = entry->value;
	}
	
	return value;
}

void *map_delete(Map *map, const char *key)
{
	MapEntry target;
	MapEntry *entry = NULL;
	void *value = NULL;

	assert(NULL != map);
	assert(NULL != key);

	target.key = (char *)key;
	target.value = NULL;
	
	entry = table_delete(map, &target);
	
	if (NULL != entry) {
		validate_entry(entry);

		value = entry->value;
		free(entry->key);		
		free(entry);
	}
	
	return value;
}

int map_exists(Map *map, const char *key)
{
	MapEntry target;
	MapEntry *entry;

	assert(NULL != map);
	assert(NULL != key);

	target.key = (char *)key;
	target.value = NULL;
	
	entry = table_search(map, &target);
	if (NULL != entry) {
		validate_entry(entry);
	}
	
	return NULL != entry;
}

void *map_first(Map *map)
{
	MapEntry *entry;
	void *value = NULL;

	assert(NULL != map);

	entry = table_first(map);
	if (NULL != entry) {
		validate_entry(entry);
		value = entry->value;
	}
	
	return value;
}

void *map_next(Map *map)
{
	MapEntry *entry;
	void *value = NULL;

	assert(NULL != map);

	entry = table_next(map);
	if (NULL != entry) {
		validate_entry(entry);
		value = entry->value;
	}
	
	return value;
}

void map_destroy(Map *map)
{
	MapEntry *entry;
	
	assert(NULL != map);
	
	entry = table_first(map);
	while (NULL != entry) {
		validate_entry(entry);

		free(entry->key);
		free(entry);
		
		entry = table_next(map);
	}
	
	table_destroy(map);
}
