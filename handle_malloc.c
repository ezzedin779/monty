#include "monty.h"
/**
* malloc_error - malloc error
* Return: EXIT_FAILURE
*/
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
/**
* init_stack - intitialize the stack
* @stack: the stack
* Return: EXIT SUCCESS or fail
*/
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}
