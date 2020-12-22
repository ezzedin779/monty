#include "monty.h"

/**
* get_fun - find functions
* @opcode: The opcode to match.
* Return: the function
*/
void (*get_fun(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}
	return (NULL);
}

/**
*_interpreter - the interpreter core
*@file: the file needed
*Return: succes or error
*/
int _interpreter(FILE *file)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t buf_size = 0, ex = EXIT_SUCCESS;
	unsigned int line_count = 0, _tok_len = 0;
	void (*op_fun)(stack_t **f, unsigned int count);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (getline(&line, &buf_size, file) != -1)
	{
		line_count++;
		tokens = _tokenise(line, DELIM);
		if (tokens == NULL)
		{
			if (empty_check(line, DELIM))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		op_fun = get_fun(tokens[0]);
		if (op_fun == NULL)
		{
			free_stack(&stack);
			ex = op_error(tokens[0], line_count);
			free_tokens();
			break;
		}
		_tok_len = len_array();
		op_fun(&stack, line_count);
		if (len_array() != _tok_len)
		{
			if (tokens && tokens[_tok_len])
				ex = atoi(tokens[_tok_len]);
			else
				ex = EXIT_FAILURE;
			free_tokens();
			break;
		}
		free_tokens();
	}
	free_stack(&stack);
	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}
	free(line);
	return (ex);
}
