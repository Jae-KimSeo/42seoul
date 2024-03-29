#include "push_swap.h"

static void	sort_at_3_B(t_Stack *a, t_Stack *b, int cnt, t_Pushswap *p)
{
	t_ListNode	*ptr;

	ptr = b->head;
	if (ft_atoi(ptr->prev->data) > ft_atoi(ptr->data))
	{
		sb(b, 0);
		p->count++;
	}
	ptr = b->head->prev->prev;
	if (ft_atoi(ptr->data) > ft_atoi(b->head->data))
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

static void	sort_over_2_B(t_Stack *a, t_Stack *b, int cnt, t_Pushswap *p)
{
	t_ListNode	*ptr;

	if (cnt == 3)
		sort_at_3_B(a, b, cnt, p);
	ptr = b->head;
	if (ft_atoi(ptr->data) < ft_atoi(ptr->prev->data))
	{
		sb(b, 0);
		p->count++;
	}
	pa(a, b);
	print_stack(a, b);
	p->count++;
}
int akk = 0;
#include <stdio.h>
void	sort_under_4_B(t_Stack *a, t_Stack *b, int cnt, t_Pushswap *p)
{
	int			num;
	t_ListNode	*ptr;

	akk++;
	printf("akk : %d\n", akk);
	num = cnt;
	print_stack(a ,b);
	write(1, "5-52\n", 4);
	printf("ccount : %d \n", cnt);
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

	print_stack(a ,b);
	write(1, "5-69\n", 4);
}
