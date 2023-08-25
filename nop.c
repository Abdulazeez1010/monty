#include "monty.h"

/**
 * nop - The opcode nop doesn’t do anything.
 * @stack : The stack
 * @line_number : Current line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (*stack == NULL)
		return;
	return;
}
