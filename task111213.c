#include "monty.h"

/**
 * t11_pchar - prints the char at the top of the stack
 * @head: double pointer
 * @c: int
 */
void t11_pchar(stack_t **head, unsigned int c)
{
	stack_t *head0;

	head0 = *head;
	if (!head0)
	{
		m_function(*head, c, "can't pchar, stack empty", 0);
	}
	if (head0->n > 127 || head0->n < 0)
	{
		m_function(*head, c, "can't pchar, value out of range", 0);
	}
	printf("%c\n", head0->n);
}

/**
 * t12_pstr - prints the string starting at the top of the stack
 * @head: double pointer
 * @c: int
 */
void t12_pstr(stack_t **head, unsigned int c)
{
	stack_t *head0;
	(void)c;

	head0 = *head;
	while (head0)
	{
		if (head0->n > 127 || head0->n <= 0)
		{
			break;
		}
		printf("%c", head0->n);
		head0 = head0->next;
	}
	printf("\n");
}

/**
 *t13_rotl- rotates the stack to the top
 *@head: double pointer
 *@c: int
 */
void t13_rotl(stack_t **head,  unsigned int c)
{
	stack_t *head0, *a;

	head0 = *head;
	(void)c;
	if (head0 == NULL || head0->next == NULL)
	{
		return;
	}
	a = head0->next;
	a->prev = NULL;
	while (head0->next != NULL)
	{
		head0 = head0->next;
	}
	head0->next = *head;
	(*head)->next = NULL;
	(*head)->prev = head0;
	(*head) = a;
}

