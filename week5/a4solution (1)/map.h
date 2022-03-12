#ifndef _MAP_H
#define _MAP_H

typedef struct TABLE Map;

Map *map_create();
int map_set(Map *map, const char *key, void *value);
void *map_get(Map *map, const char *key);
void *map_delete(Map *map, const char *key);
int map_exists(Map *map, const char *key);
void *map_first(Map *map);
void *map_next(Map *map);
void map_destroy(Map *map);

#endif
