#include "monty.h"

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
	FILE *monty_file;
	char line[MAX_LINE_LENGTH], *opcode;
	stack_t *stack = NULL;
	instruction_t *instruction;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX_LINE_LENGTH, monty_file))
	{
		char *newline;
		line_number++;

		if ((newline = strchr(line, '\n')) != NULL)
			*newline = '\0';
	
		opcode = strtok(line, " \n\t");
		if (!opcode || opcode[0] == '#')
			continue;
	
		instruction = get_instruction(opcode);
		if (!instruction)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			free_stack(&stack);
			fclose(monty_file);
			exit(EXIT_FAILURE);
		}
		instruction->f(&stack, line_number);
	}
	free_stack(&stack);
	fclose(monty_file);
	return EXIT_SUCCESS;
}
