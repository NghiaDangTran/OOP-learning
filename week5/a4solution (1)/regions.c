#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "regions.h"
#include "map.h"
#include "table.h"

// Align region size to this value
const int ALIGNMENT = 8;

typedef struct {
  void *data;
  char *name;
  Table *blocks;
  rsize_t size;
  rsize_t used;
} Region;

typedef struct {
  void *data;
  rsize_t size;
} Block;

static Map *regions = NULL;
static Region *chosen = NULL;

static int compare_blocks(void *b1, void *b2)
{
  return ((Block *)b1)->data - ((Block *)b2)->data;
}

static void align(rsize_t *size)
{
  if (*size % ALIGNMENT != 0) {
    *size += ALIGNMENT - *size % ALIGNMENT;
  }
}

static void validate_region(Region *r)
{
  assert(NULL != r);
  assert(NULL != r->data);
  assert(NULL != r->name);
  assert(NULL != r->blocks);
  if (NULL != r) {
    table_validate(r->blocks);
  }
  assert(r->size > 0);
  assert(r->used >= 0);
  assert(r->used <= r->size);
}

static void validate_block(Block *b)
{
  assert(NULL != b->data);
  assert(b->size > 0);
}

static void validate_ptr_in_region(Region *r, void *ptr) {
  validate_region(r);
  assert(ptr != NULL);
  assert(ptr >= r->data);
  assert(ptr < r->data + r->size);
}

Boolean rinit(const char *region_name, rsize_t region_size)
{
  Boolean rc = FALSE;
  Region *region;
  
  assert(NULL != region_name);
  assert(region_size > 0);
  
  if (NULL != region_name && region_size > 0) {
    
    if (NULL == regions) {
      regions = map_create();
    }
  
    assert(NULL != regions);
    if (NULL != regions && !map_exists(regions, region_name)) {

      region = malloc(sizeof(Region));
    
      if (NULL != region) {

        align(&region_size);
        region->data = malloc(region_size);
        
        if (NULL != region->data) {

          region->name = malloc(strlen(region_name) + 1);

          if (NULL != region->name) {

            region->blocks = table_create(compare_blocks);
          
            if (NULL != region->blocks) {

              strcpy(region->name, region_name);
              region->size = region_size;
              region->used = 0;

              if (map_set(regions, region_name, region)) {

                chosen = region;
                validate_region(chosen);
                rc = TRUE;

              } else {
                table_destroy(region->blocks);
                free(region->name);
                free(region->data);
                free(region);
              }

            } else {
              free(region->name);
              free(region->data);
              free(region);
            }

          } else {
            free(region->data);
            free(region);
          }

        } else {
          free(region);
        }
      }
    }
    
  }
  
  return rc;
}

Boolean rchoose(const char *region_name)
{
  Boolean rc = FALSE;
  Region *region;
  
  assert(NULL != region_name);
  
  if (NULL != region_name && NULL != regions) {
    region = map_get(regions, region_name);
    
    if (NULL != region) {
      chosen = region;
      validate_region(chosen);
      rc = TRUE;
    }
  }

  return rc;
}

const char *rchosen()
{
  char *name = NULL;
  
  if (NULL != chosen) {
    name = chosen->name;
    assert(NULL != name);
  }
  
  return name;
}

void *ralloc(rsize_t block_size)
{
  Block *curr;
  Boolean found = FALSE;
  void *last_loc;
  rsize_t space;
  void *loc = NULL;
  
  assert(block_size > 0);
  validate_region(chosen);
  
  if (block_size > 0 && NULL != chosen) {
    align(&block_size);
    last_loc = chosen->data;
    
    // first fit
    curr = table_first(chosen->blocks);
    while (NULL != curr && !found) {

      validate_block(curr);
      space = curr->data - last_loc;
      
      if (space >= block_size) {
        found = TRUE;
      } else {
        last_loc = curr->data + curr->size;
        curr = table_next(chosen->blocks);
      }
    }
    
    if (!found) {
      // look for space at the end
      space = chosen->data + chosen->size - last_loc;
      found = space >= block_size;
    }
    
    if (found) {
      curr = malloc(sizeof(Block));

      if (NULL != curr) {
        curr->data = last_loc;
        curr->size = block_size;
        
        if (table_insert(chosen->blocks, curr)) {
          validate_block(curr);

          loc = curr->data;
          chosen->used += block_size;

          validate_ptr_in_region(chosen, loc);
          memset(loc, 0, block_size);
        } else {
          free(curr);
        }
      }
    }
  }
  
  return loc;
}

rsize_t rsize(void *block_ptr)
{
  Block block;
  Block *found;
  rsize_t size = 0;
  
  assert(NULL != block_ptr);
  validate_region(chosen);
  
  if (NULL != chosen && NULL != block_ptr) {
    validate_ptr_in_region(chosen, block_ptr);
    
    block.data = block_ptr;
    block.size = 0;
    
    found = table_search(chosen->blocks, &block);
    if (NULL != found) {
      validate_block(found);
      size = found->size;
    }
  }
  
  return size;
}

Boolean rfree(void *block_ptr)
{
  Block block;
  Block *found;
  Boolean rc = FALSE;
  
  assert(NULL != block_ptr);
  validate_region(chosen);
  
  if (NULL != chosen && NULL != block_ptr) {
    validate_ptr_in_region(chosen, block_ptr);
    
    block.data = block_ptr;
    block.size = 0;
    
    found = table_delete(chosen->blocks, &block);
    if (NULL != found) {
      validate_block(found);

      chosen->used -= found->size;
      rc = TRUE;

      validate_region(chosen);
    }
  }
  
  return rc;
}

void rdestroy(const char *region_name)
{
  Region *region;
  
  assert(NULL != region_name);
  
  if (NULL != regions && NULL != region_name) {
    region = map_delete(regions, region_name);
    
    if (NULL != region) {
      if (region == chosen) {
        chosen = NULL;
      }
      table_destroy(region->blocks);
      free(region->name);
      free(region->data);
      free(region);
    }
  }
}

void rdump()
{
  Region *curr;
  Block *bcurr;
  
  if (NULL == regions) {
    printf("*** Regions not allocated\n");

  } else {

    curr = map_first(regions);
    if (NULL == curr) {
      printf("*** No regions\n");
    }

    while (NULL != curr) {
      validate_region(curr);
      printf("*** Region %s:\n", curr->name);
    
      bcurr = table_first(curr->blocks);
      while (NULL != bcurr) {
        validate_block(bcurr);
      
        printf("    %p: %d\n", bcurr->data, bcurr->size);
        bcurr = table_next(curr->blocks);
      }
    
      printf("Free space: %d%%\n", (curr->size - curr->used) * 100 / curr->size);
      curr = map_next(regions);
    }
  }
}
