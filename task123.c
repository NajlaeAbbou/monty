#include "monty.h"
/**
 * t1_pint -  prints the value at the top of the stack
 * @head: double pointer
 * @c: int unused
 */
void t1_pint(stack_t **head, unsigned int c)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", c);
		fclose(bus.file);
		free(bus.content);
		m_freestack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * t2_pop -  removes the top element of the stack.
 * @head: double pointer
 * @c: int
 */
void t2_pop(stack_t **head, unsigned int c)
{
	stack_t *head0;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", c);
		fclose(bus.file);
		free(bus.content);
		m_freestack(*head);
		exit(EXIT_FAILURE);
	}
	head0 = *head;
	*head = head0->next;
	free(head0);
}

/**
 * t3_swap - swaps the top two elements of the stack..
 * @head: double pointer
 * @c: int
 */
void t3_swap(stack_t **head, unsigned int c)
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
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", c);
		fclose(bus.file);
		free(bus.content);
		m_freestack(*head);
		exit(EXIT_FAILURE);
	}
	head0 = *head;
	a = head0->n;
	head0->n = head0->next->n;
	head0->next->n = a;
}
