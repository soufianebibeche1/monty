#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n\t");

	if (!arg || !is_numeric(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	push_stack(stack, atoi(arg));
}

/**
 * push_stack - Pushes an element onto the stack.
 * @stack: Double pointer to the beginning of the stack.
 * @value: Value to push onto the stack.
 */
void push_stack(stack_t **stack, int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;

	if (*stack)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	else
	{
		new_node->next = NULL;
	}

	*stack = new_node;
}
