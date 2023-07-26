#include "monty.h"

/**
 * t0_push - The opcode push pushes an element to the stack.
 * @head: double pointer
 * @c: int
 */
void t0_push(stack_t **head, unsigned int c)
{
	int i, mark, j;

	i = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				mark = 1;
		}
		if (mark == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", c);
			fclose(bus.file);
			free(bus.content);
			m_freestack(*head);
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", c);
		fclose(bus.file);
		free(bus.content);
		m_freestack(*head);
		exit(EXIT_FAILURE);
	}

	j = atoi(bus.arg);
	if (bus.lifi == 0)
		add_node(head, j);
	else
		add_queue(head, j);
}

/**
 * t0_pall -  prints all the values on the stack
 * @head: double pointer
 * @c: int
 */
void t0_pall(stack_t **head, unsigned int c)
{
	stack_t *head0;

	(void)c;

	head0 = *head;
	if (head0 == NULL)
		return;
	while (head0)
	{
		printf("%d\n", head0->n);
		head0 = head0->next;
	}
}

/**
 * add_node - add node
 * @head: double pointer
 * @n: int
*/
void add_node(stack_t **head, int n)
{

	stack_t *new, *head0;

	head0 = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{ printf("Error\n");
		exit(0); }
	if (head0)
		head0->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}

/**
 * add_queue - add node to the tail stack
 * @head: double pointer
 * @n: int
*/
void add_queue(stack_t **head, int n)
{
	stack_t *new, *head0;

	head0 = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
	}
	new->n = n;
	new->next = NULL;
	if (head0)
	{
		while (head0->next)
			head0 = head0->next;
	}
	if (!head0)
	{
		*head = new;
		new->prev = NULL;
	}
	else
	{
		head0->next = new;
		new->prev = head0;
	}
}
