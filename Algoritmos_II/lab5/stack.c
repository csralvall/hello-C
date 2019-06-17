#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "stack.h"

/*
 * void * malloc(size_t bytes);
 * void * calloc(size_t nitemS, size_t size);
 * void * realloc(void* ptr, size_t size);
 * void free (void* ptr);
*/

struct _stack_t {
	stack_elem_t value;
	stack_t next;
}; 

stack_t stack_empty()
{	
	stack_t p_stack = NULL;
	return p_stack;
}

stack_t stack_push(stack_t s, stack_elem_t elem)
{
	stack_t aux = NULL;
	
	//  = (stack_t) malloc(..) es la forma explicita
	aux = malloc(sizeof(struct _stack_t)); 

	if ( aux == NULL ){
		fprintf (stderr, "Invalid pointer. \n");
		exit (EXIT_FAILURE);
	}
		
	aux -> value = elem;	// (*aux).value
	aux -> next = s;	// (*aux).next
	
	s = aux;

	return s;
}	

stack_t stack_pop(stack_t s)
{	
	assert( s != NULL );

	stack_t aux = NULL;

	aux = s;

	s = s -> next;

	free(aux);
	
	return s;
}

unsigned int stack_size(stack_t s)
{
	unsigned int size = 0u;
	stack_t aux = NULL;

	aux = s;

	while (aux != NULL) {
		++size;
		aux = aux -> next;
	}

	return size;	
}

stack_elem_t stack_top(stack_t s)
{
	assert( s != NULL );

	return ( s -> value );
}

bool stack_is_empty(stack_t s)
{
	return ( s == NULL );
}

stack_elem_t* stack_to_array(stack_t s)
{
	stack_t aux = NULL;
	unsigned int size = stack_size(s);
	stack_elem_t * array = calloc( size, sizeof(stack_elem_t));

	aux = s;
	
	for ( unsigned int i = size; i > 0u; --i ) {
		array[i-1u] = aux -> value;
		aux = aux -> next;
	}
	
	return array;
}

stack_t stack_destroy(stack_t s)
{
	while( !stack_is_empty(s) )
		s = stack_pop(s);

	return (s);
}
