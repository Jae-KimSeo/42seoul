#include "push_swap.h"

static void	sort_sa_A(Stack *a, t_Pushswap *p)
{
	ListNode	*ptr;

	ptr = a->head;
	if (atoi(ptr->data) > atoi(ptr->prev->data))
	{
		sa(a, 0);
		p->count++;
	}
}

static void	sort_at_3_A(Stack *a, Stack *b, int cnt, t_Pushswap *p)
{
	ListNode	*ptr;

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
}

static void	sort_over_2_A(Stack *a, Stack *b, int cnt, t_Pushswap *p)
{
	ListNode	*ptr;

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
}

void	sort_under_4_A(Stack *a, Stack *b, int cnt, t_Pushswap *p)
{
	int			num;
	ListNode	*ptr;

	if (check_sorted(a, cnt))
		return ;
	if (cnt >= 2)
		sort_over_2_A(a, b, cnt, p);
}
