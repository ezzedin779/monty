#include "monty.h"

/**
* free_stack - Frees a stack
* @h: A pointer to the stack
*/
void free_stack(stack_t **h)
{
	stack_t *tmp = *h;

	while (*h)
	{
		tmp = (*h)->next;
		free(*h);
		*h = tmp;
	}
}

/**
* free_tokens - Frees the tokens
*/
void free_tokens(void)
{
	size_t i = 0;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i]; i++)
		free(tokens[i]);

	free(tokens);
}
/**
* len_array - Gets the length of current tokens
* Return: Length of current tokens
*/
unsigned int len_array(void)
{
	unsigned int toks_len = 0;

	while (tokens[toks_len])
		toks_len++;
	return (toks_len);
}
/**
* empty_check - Check if it's safe or not ?
* @line: the line
* @delim: delimiters
* Return: 1 or 0
*/
int empty_check(char *line, char *delim)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (line[i] == delim[j])
				break;
		}
		if (delim[j] == '\0')
			return (0);
	}

	return (1);
}

/**
* op_error - error opcode
* @opcode: Opcode
* @line_number: Line number
* Return: failed
*/
int op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	return (EXIT_FAILURE);
}
