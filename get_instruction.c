#include "monty.h"

/**
 * get_instruction - Get the function corresponding to an opcode
 * @opcode: The opcode to find
 * Return: A pointer to the function, or NULL if not found
 */
instruction_t *get_instruction(char *opcode)
{
	int i;

	static instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (&instructions[i]);
	}
	return (NULL);
}

