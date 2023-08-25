#include "monty.h"

/**
 * mod - The opcode mod computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack : The stack
 * @line_number : Current line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;
	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	second->n = second->n % top->n;
	second->prev = NULL;
	*stack = second;
	free(top);
}
