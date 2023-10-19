#include "monty.h"

/**
 * free_stack - Frees all nodes in a stack_t doubly linked list
 * @stack: Double pointer to the head of the stack
 */
void free_stack(stack_t **stack)
{
	stack_t *current, *temp;

	current = *stack;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}

/**
 * is_numeric - Checks if a string is a numeric value.
 * @str: The string to check.
 * Return: 1 if numeric, 0 otherwise.
 */
int is_numeric(char *str)
{
	if (!str)
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
