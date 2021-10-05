#include "push_swap.h"

static void	sort_at_3_B(Stack *a, Stack *b, int cnt, Pushswap *p)
{
	ListNode	*ptr;

	ptr = b->head;
	if (atoi(ptr->prev->data) > atoi(ptr->data))
	{
		sb(b, 0);
		p->count++;
	}
	ptr = b->head->prev->prev;
	if (atoi(ptr->data) > atoi(b->head->data))
	{
		rb(b, 0);
		rb(b, 0);
		pa(a, b);
		rrb(b, 0);
		rrb(b, 0);
		p->count += 5;
	}
	else
	{
		pa(a, b);
		p->count++;
	}
}

static void	sort_over_2_B(Stack *a, Stack *b, int cnt, Pushswap *p)
{
	ListNode	*ptr;

	if (cnt == 3)
		sort_at_3_B(a, b, cnt, p);
	ptr = b->head;
	if (atoi(ptr->data) < atoi(ptr->prev->data))
	{
		sb(b, 0);
		p->count++;
	}
	pa(a, b);
	p->count++;
}

void	sort_under_4_B(Stack *a, Stack *b, int cnt, Pushswap *p)
{
	int			num;
	ListNode	*ptr;

	num = cnt;
	if (check_reverse_sorted(b, cnt) == TRUE)
	{
		while (num != 0)
		{
			pa(a, b);
			p->count++;
			num--;
		}
		return ;
	}
	ptr = b->head;
	if (cnt >= 2)
		sort_over_2_B(a, b, cnt, p);
	pa(a, b);
	p->count ++;
}
