#include "monty.h"

/**
 * add - The opcode add adds the top two elements of the stack.
 * @stack : The stack
 * @line_number : Cureent line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;
	second->n += top->n;
	second->prev = NULL;
	*stack = second;
	free(top);
}
