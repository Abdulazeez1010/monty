#include "monty.h"

/**
 * sub - The opcode sub subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack : The stack
 * @line_number : Current line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;
	second->n -= top->n;
	second->prev = NULL;
	*stack = second;
	free(top);
}
