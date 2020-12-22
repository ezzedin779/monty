#include "monty.h"
/**
 * _add - Adds
 * @stack: the stack
 * @line_number: line number
 */
void _add(stack_t **stack, unsigned int line_number)
{
  if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
      _error_choice(short_error(line_number, "add"));
      return;
    }

  (*stack)->next->next->n += (*stack)->next->n;
  _pop(stack, line_number);
}

/**
 * _sub - substracts
 * @stack: the stack
 * @line_number: line number
 */
void _sub(stack_t **stack, unsigned int line_number)
{
  if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
      _error_choice(short_error(line_number, "sub"));
      return;
    }

  (*stack)->next->next->n -= (*stack)->next->n;
  _pop(stack, line_number);
}

/**
 * _div - divide
 * @stack: the stack
 * @line_number: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
  if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
      _error_choice(short_error(line_number, "div"));
      return;
    }

  if ((*stack)->next->n == 0)
    {
      _error_choice(div_error(line_number));
      return;
    }

  (*stack)->next->next->n /= (*stack)->next->n;
  _pop(stack, line_number);
}

/**
 * _mul - multiply
 * @stack: the stack
 * @line_number: line number
 *
 */
void _mul(stack_t **stack, unsigned int line_number)
{
  if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
      _error_choice(short_error(line_number, "mul"));
      return;
    }

  (*stack)->next->next->n *= (*stack)->next->n;
  _pop(stack, line_number);
}

/**
 *_mod - modulos
 * @stack: the stack
 * @line_number: line number
 */
void _mod(stack_t **stack, unsigned int line_number)
{
  if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
      _error_choice(short_error(line_number, "mod"));
      return;
    }

  if ((*stack)->next->n == 0)
    {
      _error_choice(div_error(line_number));
      return;
    }

  (*stack)->next->next->n %= (*stack)->next->n;
  _pop(stack, line_number);
}
