#include "monty.h"

/**
 * multiply - The opcode mul multiplies the second top element of the stack
 * with the top element of the stack.
 * stack by the top element of the stack.
 * @stack : The stack
 * @line_number : Current line number
 */
void multiply(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;
	second->n *= top->n;
	second->prev = NULL;
	*stack = second;
	free(top);
}
