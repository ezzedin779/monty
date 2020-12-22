#include "monty.h"
/**
* short_error - short stack
* @line_number: line number
* @op: Operation
* Return: EXIT_FAILURE
*/
int short_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
* div_error - div by 0
* @line_number: line number
* Return: EXIT_FAILURE
*/
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}
/**
* pop_error - failure
* @line_number: line number
* Return: EXIT_FAILURE
*/
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
* pint_error - empty stack
* @line_number: line number
* Return: EXIT_FAILURE
*/
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
/**
 * _error_choice - last element is error
 * @error_code: string in tokens
 */
void _error_choice(int error_code)
{
	int tok_len = 0, i = 0;
	char *exit = NULL;
	char **new_toks = NULL;

	tok_len = len_array();
	new_toks = malloc(sizeof(char *) * (tok_len + 2));
	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}
	while (i < tok_len)
	{
		new_toks[i] = tokens[i];
		i++;
	}
	exit = get_int(error_code);
	if (!exit)
	{
		free(new_toks);
		fprintf(stderr, "Error: malloc failed\n");
		return;
	}
	new_toks[i++] = exit;
	new_toks[i] = NULL;
	free(tokens);
	tokens = new_toks;
}
