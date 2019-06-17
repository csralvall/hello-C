#include <assert.h>
#include <stdlib.h>
#include "map.h"

struct _node_t {
    map_t left;
    map_t right;
    key_t key;
    value_t value;
};

map_t map_empty() {
    return NULL;
}

static bool is_abb(map_t map) {
   bool b = false;

   if(map == NULL || (map != NULL && map->left == NULL && map->right == NULL)) {
     b = true;
   }else if(map->left != NULL){
     if(map->right != NULL)
       b = is_abb(map->left) && is_abb(map->right);
     b = is_abb(map->left);
   }else if(map->right != NULL){
     b = is_abb(map->right);
   }

   return b;
}

static bool is_empty(map_t map) {
   return (map == NULL);			// Guido's good idea.
}


static map_t create_node(key_t key, value_t value, map_t left, map_t right) {
    map_t node = NULL;
    node = malloc(sizeof(struct _node_t));	// Allocating space for the new object.

    node -> right = right;
    node -> left = left; 
    node -> key = key; 
    node -> value = value; 

    return (node);				// Returning the pointer to the new object.
}

static map_t free_node(map_t node) {
    free(node); 				// Alternative option: node = NULL; return (node);
    return map_empty();
}

map_t map_put(map_t map, key_t key, value_t value) {
    assert(key != NULL);
    assert(value != NULL);
    assert(is_abb(map));

    map_t node = map;

    if ( is_empty(node) )						// Another Guido's good idea.
       node = create_node(key, value, map_empty(), map_empty());	// Another Guido's good idea.
    else if ( key_less(key,node -> key) ) {
       node -> left = map_put(node -> left,key,value);	// Map -> left will be the changed left sub tree of map.
    }else if ( !key_less(key,node -> key)) {
       node -> right = map_put(node -> right,key,value);// Map -> right will be the changed right sub tree of map.
    }else if ( key_eq(key,node -> key) )
       node -> value = value;

    return (node);
}

value_t map_get(map_t map, key_t key) {
    assert(key != NULL);
    assert(is_abb(map));
    
    value_t value = NULL;
    map_t node = map;

    if ( key_eq(key,node -> key) )
       value = node -> value;
    else if ( key_less(key,node -> key) )
       value = map_get(node -> left,key);
    else if ( !key_less(key,node -> key) )
       value = map_get(node -> right,key);

    return (value);
}

bool map_contains(map_t map, key_t key) {
    assert(key != NULL);
    assert(is_abb(map));

    bool b = false;

    if ( !is_empty(map) ) {
       if ( key_eq(key,map -> key) )
          b = true;
       else if ( key_less(key,map -> key) )
          b = map_contains(map -> left,key);
       else if ( !key_less(key,map -> key) )
          b = map_contains(map -> right,key);
   }

    return (b);
}

static map_t find_fatherOf_max(map_t map) {
   map_t father = map;
   map_t son = map;

   while ( son -> right != NULL ) {
      father = son;
      son = son -> right;
   }

   return (father);
}

static map_t remove_node(map_t map) {
   map_t node = map;
   map_t right = map->right;
   map_t left = map->left;
   map_t father = NULL;
   map_t son = NULL;

   string_destroy(node->key);
   string_destroy(node->value);
   free_node(node);

   if(right == NULL) {
     node = left;
   } else if(left == NULL) {
     node = right;
   } else {
	if(left->right == NULL) {
          left->right = right;
          node = left;
        } else {
          father = find_fatherOf_max(node);
          son = father->right;
          father->right = son->left;
          son->left = left;
          son->right = right;
          node = son;
        }
   }

   return node;
}


map_t map_remove(map_t map, key_t key) {	// The only true good idea that you have ever had.
    map_t result = map;

    if (map != NULL) {
       if ( key_eq(key,result->key) ) {
          result = remove_node(result);
       }else if (key_less(key, result->key))
          result->left = map_remove(result->left,key);
       else if (key_less(result-> key,key))
          result -> right = map_remove(result->right,key);
    }

    return result;
}

map_t map_destroy(map_t map) {

    if ( !is_empty(map) ) {
        map_destroy(map -> right);
        map_destroy(map -> left);
        string_destroy(map -> key);
        string_destroy(map -> value);
        free_node(map);
    }

    return (map);
}


void map_dump(map_t map, FILE *file) {
    if (map != NULL) {
        map_dump(map->left, file);
        key_dump(map->key, file);
        fprintf(file, ": ");
        value_dump(map->value, file);
        fprintf(file, "\n");
        map_dump(map->right, file);
    }
}
