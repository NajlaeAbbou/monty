#include "monty.h"

void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void free_stack(stack_t *head);
/**
* m_freestack - frees a doubly linked list
* @head: pointer
*/
void m_freestack(stack_t *head)
{
	stack_t *head0;

	head0 = head;
	while (head0)
	{
		head0 = head->next;
		free(head);
		head = head0;
	}
}

/**
 * m_executefunct - executes opcodes
 * @content: pointer
 * @stack: head stack
 * @c: int
 * @file: monty file
 * Return: xxx
 */
int m_executefunct(char *content, stack_t **stack, unsigned int c, FILE *file)
{
	instruction_t opst[] = {
		{"push", t0_push}, {"pall", t0_pall}, {"pint", t1_pint}
		, {"pop", t2_pop}, {NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");

	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, c);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", c, op);
		fclose(file);
		free(content);
		m_freestack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
