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
		m_function(*head, c, "can't pint, stack empty", 0);
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
		m_function(*head, c, "can't pop an empty stack", 0);
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
	int a;

	m_function(*head, c, "can't swap, stack too short", 1);
	head0 = *head;
	a = head0->n;
	head0->n = head0->next->n;
	head0->next->n = a;
}
