#include "monty.h"
/**
 *main - Monty Interpreter
 *@argc: number of arguments
 *@argv: the arguments
 *Return: 0 or 1
 */
int main(int argc, char *argv[])
{
  FILE file = NULL;
  int ex = EXIT_SUCCESS;

  if (argc != 2)
    {
      fprintf(stderr, "USAGE: monty file\n");
      return (EXIT_FAILURE);
    }
  file = fopen(argv[1], "r");
  if (file == NULL)
    {
      fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
      return (EXIT_FAILURE);
    }
  ex = _interpreter(file);
  fclose(file);
  return (ex);
}
