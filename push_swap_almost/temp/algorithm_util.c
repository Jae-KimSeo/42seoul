#include "push_swap.h"

void sort_under_20_A(Stack *a, Stack *b, int cnt, Pushswap *p){
    
    int pivot;
    int num;
    int cnt_pb;
    int cnt_ra;
    ListNode *ptr;
    cnt_pb = 0;
    cnt_ra = 0;
    pivot = get_middle_pivot(a, cnt);
    num = cnt;
	int part;

    if (check_sorted(a, cnt))
        return ;
	if (cnt < 4)
	{
		sort_under_4_A(a, b, cnt, p);
		return ;
	}
	part = TRUE;
	if (size(*a) == cnt)
		part = FALSE;
    while (num != 0){
        ptr = a->head;
        if (ft_atoi(ptr->data) < pivot) // 지금 n, n+1 개씩 먹음 
        {
            pb(a, b);
            cnt_pb++;
            p->count++;
        }
        else
        {
            if ((cnt_pb == (cnt - (int)(cnt/2) - 1)) && (ft_atoi(ptr->prev->data) < pivot))
            {
                sa(a, 0);
                pb(a, b);
                cnt_pb++;
                p->count += 2;
            } 
            else
            {
                ra(a, 0);
                cnt_ra++;
                p->count++;
            }
        }
		if (cnt_pb == (int)(cnt/2)) // ra를 더돌리지 않을 것 
			break;
        num--;
    }
    int i;
    i = 0;
	if (part == TRUE) // rra가 의미있고 (전체가 아니라 부분), 
    {
    	while (i < cnt_ra)
		{
        	rra(a, 0);
        	p->count++;
        	i++;
    	}
	}
    sort_under_20_A(a, b, cnt - cnt_pb, p);// 여기에는 a스택에 있는 전체 element가 들어가야함 
    b_to_a(a, b, cnt_pb, p);
    //sort_under_20_B(a, b, cnt_pb, p);
}

/*
void sort_under_4_A(Stack *a, Stack *b, int cnt, Pushswap *p){
  if (cnt == 0)
    return ;
  int a_top;
  int a_second;
  int min;
  int num;
  int tmp_cnt;
  int rotate_num;
  ListNode *ptr;

    if (check_sorted(a, cnt))
        return ;
  num = cnt;
    ptr = a->head;
    if(cnt >= 2){
            if (atoi(ptr->prev->data) < atoi(ptr->data)){
                sa(a, 0);
                p->count++;
            }
            ptr = a->head->prev;
            if (cnt == 3){
                if (size(*a) == cnt){
                    if (atoi(ptr->prev->data) < atoi(ptr->data)){
                        rra(a, 0);
                        p->count++;
                    }
                }else{
                    if (atoi(ptr->prev->data) < atoi(ptr->data)){
                        ra(a, 0);
                        sa(a, 0);
                        rra(a, 0);
                        p->count+=3;
                        }
                    }
                ptr = a->head;
                if (atoi(ptr->data) > atoi(ptr->prev->data)){
                        sa(a, 0);
                        p->count++;
                }
            }
        }
    }




void sort_under_4_B(Stack *a, Stack *b, int cnt, Pushswap *p){
  if (cnt == 0){
    return ;
  }

  int b_top;
  int max;
  int num;
  int tmp_cnt;
  int rotate_num;
  ListNode *ptr;

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
    if (cnt >= 2){
        if (cnt == 3){
            if (atoi(ptr->prev->data) > atoi(ptr->data)){
                sb(b, 0);
                p->count++;
            }
                ptr = b->head->prev->prev;
            if (atoi(ptr->data) > atoi(b->head->data)){
                rb(b, 0);
                rb(b, 0);
                pa(a, b);
                rrb(b, 0);
                rrb(b, 0);
                p->count += 5;
            }
            else {
                pa(a, b);
                p->count++;    
            }
        }
        ptr = b->head;
        if (atoi(ptr->data) < atoi(ptr->prev->data)){
            sb(b, 0);
            p->count++;
        }
        pa(a, b);
        p->count++;
    }
    pa(a, b);
    p->count ++;
}
//2개의 피봇을 찾아야해
// 하나는 1/3, 하나는 2/3
// cnt 해서 up 은 cnt의 1/3개, down은 cnt의 아래로1/3개

*/
/*
void sort_under_20_B(Stack *a, Stack *b, int cnt, Pushswap *p)
{
    int pivot;
	int num;
	int cnt_pa;
	int cnt_rb;
	int part;
	int i;
	ListNode *ptr;

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
    
	if (cnt < 4){
		sort_under_4_B(a, b, cnt, p);
		return ;
	}
	cnt_pa = 0;
	cnt_rb = 0;
	i = 0;
	pivot = get_middle_pivot(b, cnt);
	part = TRUE;
	if (size(*b) == cnt)
		part = FALSE;
    while (num != 0)
	{
		ptr = b->head;
		{
			if (ft_atoi(ptr->data) > pivot) // 2n + 1 일때 n + 1개, 2n일때 n개 
			{
				pa(a, b);
				cnt_pa++;
				p->count++;
			}
			else
			{
                if ((cnt_pa == (cnt - (int)(cnt/2) - 1)) && (ft_atoi(ptr->prev->data) > pivot))
                {
                    sb(a, 0);
                    pa(a, b);
                    cnt_pa++;
                    p->count += 2;
                } 
                else
                {
				    rb(b, 0);
				    cnt_rb++;
				    p->count++;
                }
			}
			if (cnt_pa == (int)(cnt/2))
				break;
			num--;
		}
	}
    if (part == TRUE)
	{
		while (i < cnt_rb)
		{
			rrb(b, 0);
			p->count++;
			i++;
		}
	}
	sort_under_20_A(a, b, cnt_pa, p);
	sort_under_20_B(a, b, cnt - cnt_pa, p);   
}

*/