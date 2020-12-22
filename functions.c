#include "monty.h"
/**
* _push - new thing in the list
* @stack: the stack
* @line_number: line number
*/
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}

	if (tokens[1] == NULL)
	{
		_error_choice(int_error(line_number));
		return;
	}

	for (i = 0; tokens[1][i]; i++)
	{
		if (tokens[1][i] == '-' && i == 0)
			continue;
		if (tokens[1][i] < '0' || tokens[1][i] > '9')
		{
			_error_choice(int_error(line_number));
			return;
		}
	}
	new->n = atoi(tokens[1]);
	tmp = (*stack)->next;
	new->prev = *stack;
	new->next = tmp;
	if (tmp)
	tmp->prev = new;
	(*stack)->next = new;
}
/**
 * _nop - nothing
 * @stack: the stack
 * @line_number: line number
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * _pall - prints the values
 * @stack: the stack
 * @line_number: line number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * _pint - Prints the top value of stack
 * @stack: the stack
 * @line_number: line number
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		_error_choice(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * _pop - removes the first value
 * @stack: stack
 * @line_number: line number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		_error_choice(pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}
