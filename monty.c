#include <stdio.h>
#include "monty.h"

/**
 * line_remove_count - removes \n at end of line and count line
 * @line_number: number of the line of file * @line: line read from file
 * @line: line from file
 */

void line_remove_count(unsigned int *line_number, char *line)
{
	(*line_number)++;
	line[strlen(line) - 1] = '\0';
}


/**
 * file_validation- check if file was opened, also free stack
 * @file: fopen of montyfile.m
 * @argv: arguments from prompt
 */

void file_validation(FILE *file, char **argv)
{
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

/**
 * arg_validation - validate user input argv
 * @argc: argument count from prompt * @argv: argument values from prompt
 * @argv: argument values from promt
 */

void arg_validation(int argc, char **argv)
{
	if (argc != 2 || argv[1] == NULL)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * main - monty translator
 * @argc: argument count
 * @argc:  argument count from promt
 * @argv: argument content
 * Return: 0
 */

int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	char *line = NULL, *opcode = NULL;
	size_t len = 0, i;
	FILE *file;

	stack_t **stack;
	instruction_t instructions[] = {{"push", push}, {"pall", pall}, {"pop", pop},
		{"add", add}, {NULL, NULL}
	};
	arg_validation(argc, argv);
	file = fopen(argv[1], "r");/* read monty.m file */
	file_validation(file, argv);
	stack = malloc(sizeof(stack_t *));
	*stack = NULL;
	while ((getline(&line, &len, file) != EOF)) /* Line by line copy into line */
	{
		line_remove_count(&line_number, line);
		opcode = strtok(line, " ");
		for (i = 0; instructions[i].f != NULL && opcode != NULL; i++)/*calls*/
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
	clean_up(line, stack, file);
	return (0);
}
