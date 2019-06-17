#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "stack_.h"

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

struct h_stack_t {
	unsigned int stack_size;
	stack_t next;
};

stack_head stack_empty()
{	
	stack_head p_stack = NULL;
	p_stack = malloc(sizeof(struct h_stack_t));
	return p_stack;
}

stack_head stack_push(stack_head s, stack_elem_t elem)
{
	stack_t aux = NULL;
	
	//  = (stack_t) malloc(..) explicit form.
	aux = malloc(sizeof(struct _stack_t)); 

	if ( aux == NULL ){
		fprintf (stderr, "Invalid pointer. \n");
		exit (EXIT_FAILURE);
	}
		
	aux -> value = elem;		// (*aux).value
	aux -> next = s -> next;	// (*aux).next
	
	s -> next = aux;

	++(s -> stack_size);

	return s;
}	

stack_head stack_pop(stack_head s)
{	
	assert( s != NULL );

	stack_t aux = NULL;

	aux = (s -> next);

	(s -> next) = (s -> next) -> next;

	free(aux);
	
	return s;
}

unsigned int stack_size(stack_head s)
{
	return (s -> stack_size);	
}

stack_elem_t stack_top(stack_head s)
{
	assert( s != NULL );

	return ( (s -> next) -> value );
}

bool stack_is_empty(stack_head s)
{
	return ( s == NULL );
}

stack_elem_t* stack_to_array(stack_head s)
{
	stack_t aux = NULL;
	unsigned int size = stack_size(s);
	stack_elem_t * array = calloc( size, sizeof(stack_elem_t)); // Requesting space for #size elements of type stack_elem_t.

	aux = s -> next;
	
	for ( unsigned int i = size; i > 0u; --i ) {
		array[i-1u] = aux -> value;
		aux = aux -> next;
	}
	
	return array;
}

stack_head stack_destroy(stack_head s)
{
	while( !stack_is_empty(s) )
		stack_pop(s);

	return (s);
}
