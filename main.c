#include "monty.h"

/**
 * main - The main function
 * @argc : Argument count
 * @argv : Argument vector
 * Return: if successfule EXIT_SUCCESS, otherwise, EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	int found;
	unsigned int line_number;
	ssize_t i;
	char line[256];
	char *token;
	stack_t *stack;
	FILE *file;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack = NULL;
	line_number = 0;
	while (fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		token = strtok(line, " \t\n");
		if (token == NULL)
			continue;
		found = 0;
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(token, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				found = 1;
				break;
			}
		}
		if (!found)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
	return (EXIT_SUCCESS);
}
