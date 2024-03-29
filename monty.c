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
 *arg_validation - validate user input argv
 *@argc: argument count from command prompt
 *@argv: argument value from command prompt
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
	char *line = NULL;
	size_t len = 0;
	int i = 0;
	FILE *file;
	stack_t **stack;

	arg_validation(argc, argv);
	file = fopen(argv[1], "r");/* read monty.m file */
	file_validation(file, argv);
	stack = malloc(sizeof(stack_t *));
	if (stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	*stack = NULL;
	while ((getline(&line, &len, file) != EOF)) /* Line by line copy into line */
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != '#' && line[i] != '\0')
		{
			line_remove_count(&line_number, line);
			ops_exe(stack, line, line_number, file);
		}
		i = 0;
	}
	clean_up(line, stack, file);
	return (0);
}
