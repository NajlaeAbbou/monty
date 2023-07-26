#include "monty.h"

/**
 * t4_add - adds the top two elements of the stack.
 * @head: double pointer
 * @c: int
 */
void t4_add(stack_t **head, unsigned int c)
{
	stack_t *head0;
	int l, a;

	l = 0;
	head0 = *head;
	while (head0)
	{
		head0 = head0->next;
		l++;
	}
	if (l< 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", c);
		fclose(bus.file);
		free(bus.content);
		m_freestack(*head);
		exit(EXIT_FAILURE);
	}
	head0 = *head;
	a = head0->n + head0->next->n;
	head0->next->n = a;
	*head = head0->next;
	free(head0);
}

/**
 *t5_nop - doesn’t do anything. 
 *@head: pointer
 *@c: int
 */
void t5_nop(stack_t **head, unsigned int c)
{
	(void) c;
	(void) head;
}

/**
 *t6_sub -  subtracts the top element of the stack from the second
 *@head: pointer
 *c: int
 */
void t6_sub(stack_t **head, unsigned int c)
{
	stack_t *head0;
	int res, i;

	head0 = *head;
	for (i = 0; head0 != NULL; i++)
		head0 = head0->next;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", c);
		fclose(bus.file);
		free(bus.content);
		m_freestack(*head);
		exit(EXIT_FAILURE);
	}
	head0 = *head;
	res = head0->next->n - head0->n;
	head0->next->n = res;
	*head = head0->next;
	free(head0);
}
