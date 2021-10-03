#include "push_swap.h"

void a_to_b(Stack *a, Stack *b, int cnt, Pushswap *p){
  int pivot_index_big;
  int pivot_index_small;
  int a_top;
  int a_second;
  int cnt_pb;
  int cnt_ra;
  int cnt_rb;

  cnt_pb = 0;
  cnt_ra = 0;
  cnt_rb = 0;

  if (a->head == NULL)
    return ;
  if (a == NULL || b == NULL)
      return ;

  if (cnt < 20)
  {
    sort_under_20_A(a, b, cnt, p);
    return ;
  }
  
  pivot_index_big = get_high_pivot(*a, cnt);
  pivot_index_small = get_low_pivot(*a, cnt);

  while(!IsEmpty(*a) && cnt != 0)
  {
    a_top = ft_atoi(a->head->data);
    if (a_top >= pivot_index_big){
      ra(a, 0);
      cnt_ra++;
    }
    else {
      pb(a, b);
      cnt_pb++;
      if (a_top >= pivot_index_small)
      {
        rb(b, 0);
        cnt_rb++;
      }
    }
    cnt--;
  }
  p->count += cnt_ra + cnt_rb + cnt_pb;
    if (cnt_ra - cnt_rb > 2 || cnt_ra - cnt_rb < -2){
      write(1, "PIVOT_ERROR\n", 12);
      return ;
    }

    if (cnt_ra < cnt_rb){
      for (int i = 0; i < cnt_ra; i++)
        rrr(a, b);
      rrb(b, 0);
      p->count += cnt_rb;
    }
    else if (cnt_rb < cnt_ra){
      for (int i = 0; i < cnt_rb; i++)
        rrr(a, b);
      rra(a, 0);
      p->count += cnt_ra;
    }
    else{
      for (int i = 0; i < cnt_ra; i++)
        rrr(a, b);
      p->count += cnt_ra;
    }
  a_to_b(a, b, cnt_ra, p);
  b_to_a(a, b, cnt_rb, p);
  b_to_a(a, b, cnt_pb - cnt_rb, p);
  }

