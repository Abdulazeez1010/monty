#include "monty.h"

/**
 * pchar - The opcode pchar prints the char at the top of the stack,
 * followed by a new line.
 * @stack : The stack
 * @line_number : Current line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	if ((current->n) > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(current->n);
}
