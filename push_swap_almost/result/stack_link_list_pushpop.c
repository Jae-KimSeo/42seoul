#include "stack_link_list.h"

void	push_head(t_Stack *a, t_element data)
{
	if (IsFull(*a))
	{
		write(1, "is Full", sizeof("is Full"));
		return ;
	}
	a->head = insert_first(a->head, data);
	write(1, "sllp-11\n", 8);
	if (a->tail == NULL)
		a->tail = a->head;
	a->count++;
}

void	push_tail(t_Stack *a, t_element data)
{
	if (IsFull(*a))
	{
		write(1, "is Full", sizeof("is Full"));
		return ;
	}
	a->tail = insert_last(a->tail, data);
	if (a->head == NULL)
		a->head = a->tail;
	a->count++;
}

t_element	pop_head(t_Stack *a)
{
	t_element	ret;

	if (IsEmpty(*a))
	{
		write(1, "is Empty", sizeof("is Empty"));
		return (NULL);
	}

	write(1, "13-39\n", 6);
	ret = a->head->data;
	if (size(*a) == 1)
		a->tail = NULL;
	a->head = delete_first(a->head);
	write(1, "13-44\n", 6);
	a->count--;
	return (ret);
}

t_element	pop_tail(t_Stack *a)
{
	t_element	ret;

	if (IsEmpty(*a))
	{
		write(1, "is Empty", sizeof("is Empty"));
		return (NULL);
	}
	ret = a->tail->data;
	if (size(*a) == 1)
		a->head = NULL;
	a->tail = delete_last(a->tail);
	a->count--;
	return (ret);
}

void	print_stack(t_Stack *a, t_Stack *b)
{
	int			len;
	t_ListNode	*ptr1;
	t_ListNode	*ptr2;

	ptr1 = a->head;
	ptr2 = b->head;
	write(1, "\n", sizeof("\n"));
	while (ptr1 != NULL || ptr2 != NULL)
	{
		len = 0;
		if (ptr1 == NULL)
			write(1, "_", sizeof("_"));
		else
			write(1, ptr1->data, ft_strlen(ptr1->data));
		write(1, " ", sizeof(" "));
		if (ptr2 == NULL)
			write(1, "_", sizeof("_"));
		else
			write(1, ptr2->data, ft_strlen(ptr2->data));
		write(1, "\n", sizeof("\n"));
		if (ptr1 != NULL)
			ptr1 = ptr1->prev;
		if (ptr2 != NULL)
			ptr2 = ptr2->prev;
	}
	write(1, "\n", sizeof("\n"));
}
