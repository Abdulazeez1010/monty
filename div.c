#include "monty.h"

/**
 * div - The opcode div divides the second top element of the
 * stack by the top element of the stack.
 * @stack : The stack
 * @line_number : Current line number
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;
	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	second->n /= top->n;
	second->prev = NULL;
	*stack = second;
	free(top);
}
