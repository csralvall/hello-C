#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void print_stack(stack_elem_t* array, unsigned int size)
{
	for ( unsigned int i = 0u; i < size; ++i )
		printf("Elemento %i: %i.\n", i, array[i]);
}

int main(void)
{
	stack_elem_t var = 0;
	stack_t pila = stack_empty();
	stack_elem_t* aux = NULL;
	unsigned int size = 0u;

	printf("Size of the stack: "); 
	scanf("%u.\n", &size);

	for ( unsigned int i = 0u; i < size; i++ ) {
		printf("New element: ");
		scanf("%i.\n", &var);
		pila = stack_push(pila,var);
	}

	size = stack_size(pila);
	
	printf("The size of the stack is: %u.\n", size);
	
	aux = stack_to_array(pila);

	print_stack(aux,size);
	
	return 0;
}
