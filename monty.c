#include <stdio.h>
#include "monty.h"

/**
 * arg_validation - validate user input argv
 */

void arg_validation(void)
{
	printf("USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * main - monty translator * @argc: argument count
 * @argc:  argument count from promt
 * @argv: argument content
 * Return: 0
 */

int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	char *line = NULL;
	size_t len = 0, i;
	char *opcode;
	FILE *file;

	stack_t **stack;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{NULL, NULL}
	};
	if (argc != 2 || argv[1] == NULL)
		arg_validation();
	stack = malloc(sizeof(stack_t *));
	*stack = NULL;
	file = fopen(argv[1], "r");/* read monty.m file */
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(stack);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, file) != EOF)) /* Line by line copy into line */
	{
		line_number++;
		line[strlen(line) - 1] = '\0'; /* remove \n from the end of line */
		opcode = strtok(line, " ");
		if(opcode != NULL)
		{
			for (i = 0; instructions[i].f != NULL; i++) /*Still have functions to call*/
			{
				if (strcmp(instructions[i].opcode, opcode) == 0) /* Matched a case */
				{
					instructions[i].f(stack, line_number, line, file);
					break;
				}
			}
			if (instructions[i].f == NULL)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				clean_up(line, stack, file);
				exit(EXIT_FAILURE);
			}
		}
	}
	clean_up(line, stack, file);
	return (0);
}
