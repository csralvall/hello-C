/**
*  @file stack.h
*  @brief TAD Stack definition
*/
#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>

/**
* @brief Stack type definition
*/
typedef struct _stack_t * stack_t;

/**
* @brief Stack header type definition
*/
typedef struct h_stack_t * stack_head;

/**
* @brief Stack elements type definition
*/
typedef char stack_elem_t;

/**
* @brief Creates an empty stack_t
* @return An empty stack
*/
stack_head stack_empty();

/**
* @brief Inserts an element at the top of the stack
* @param s A stack
* @param elem An element to push into the stack
* @return The new stack with 'elem' at the top
*/
stack_head stack_push(stack_head s, stack_elem_t elem);

/**
* @brief Removes the element at the top of the stack
* @param s A stack
* @return The new stack with the top element removed
* @note Only applies to non-empty stacks
*/
stack_head stack_pop(stack_head s);

/**
* @brief Returns the size of the stack
* @param s A stack
* @return The size of the stack
*/
unsigned int stack_size(stack_head s);

/**
* @brief Returns the element at the top of the stacks
* @param s A stacks
* @return The element at the top of the stack
* @note Only applies to non-empty stacks
*/
stack_elem_t stack_top(stack_head s);

/**
* @brief Check if the given stack is empty
* @param s A stack
* @return true if the stack is empty, false otherwise
*/
bool stack_is_empty(stack_head s);

/**
* @brief Creates an array with all the elements of the stack
* @param s A stack
* @return An array containing all the elements of the stack. The stack top element
* becomes the rightmost element of the array. The size of the resulting
* array is determined by 'stack_size(s)'
*/
stack_elem_t *stack_to_array(stack_head s);

/**
* @brief Destroys the stack
* @param s A stack
* @note All memory resources are freed
*/
stack_head stack_destroy(stack_head s);


#endif