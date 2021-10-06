#include "push_swap.h"

static void	sort_sa_A(t_Stack *a, t_Pushswap *p)
{
	t_ListNode	*ptr;

	ptr = a->head;
	if (atoi(ptr->data) > atoi(ptr->prev->data))
	{
		sa(a, 0);
		p->count++;
	}
}

static void	sort_at_3_A(t_Stack *a, t_Stack *b, int cnt, t_Pushswap *p)
{
	t_ListNode	*ptr;

	ptr = a->head->prev;
	if (size(*a) == cnt)
	{
		if (atoi(ptr->prev->data) < atoi(ptr->data))
		{
			rra(a, 0);
			p->count++;
		}
	}
	else
	{
		if (atoi(ptr->prev->data) < atoi(ptr->data))
		{
			ra(a, 0);
			sa(a, 0);
			rra(a, 0);
			p->count += 3;
		}
	}
	sort_sa_A(a, p);
	print_stack(a ,b);
	write(1, "99-40\n", 4);
}

static void	sort_over_2_A(t_Stack *a, t_Stack *b, int cnt, t_Pushswap *p)
{
	t_ListNode	*ptr;

	ptr = a->head;
	if (atoi(ptr->prev->data) < atoi(ptr->data))
	{
		sa(a, 0);
		p->count++;
	}
	if (cnt == 3)
	{
		sort_at_3_A(a, b, cnt, p);
		ptr = a->head;
		if (atoi(ptr->data) > atoi(ptr->prev->data))
		{
			sa(a, 0);
			p->count++;
		}
	}
	print_stack(a ,b);
	write(1, "4-41\n", 4);
}

void	sort_under_4_A(t_Stack *a, t_Stack *b, int cnt, t_Pushswap *p)
{
	int			num;
	t_ListNode	*ptr;

	print_stack(a ,b);
	write(1, "4-69\n", 4);
	//if (check_sorted(a, cnt))
	//	return ;
	if (cnt >= 2)
		sort_over_2_A(a, b, cnt, p);
}
