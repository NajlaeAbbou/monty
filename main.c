#define _POSIX_C_SOURCE 200809L
#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - main monty
 * @argc: number of args
 * @argv: monty file
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t readline = 1;
	stack_t *stack = NULL;
	unsigned int c = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readline > 0)
	{
		content = NULL;
		readline = getline(&content, &size, file);
		bus.content = content;
		c++;
		if (readline > 0)
		{
			m_executefunct(content, &stack, c, file);
		}
		free(content);
	}
	m_freestack(stack);
	fclose(file);
	return (0);
}
