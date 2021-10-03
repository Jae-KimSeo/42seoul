#include "push_swap.h"

void b_to_a(Stack *a, Stack *b, int cnt, Pushswap *p){
  int pivot_index_big;
  int pivot_index_small;
  int cnt_pa;
  int cnt_ra;
  int cnt_rb;
  int b_top;

  cnt_pa = 0;
  cnt_ra = 0;
  cnt_rb = 0;

  if (a == NULL || b == NULL)
      return ;

  if (cnt < 4)
  {
    sort_under_4_B(a, b, cnt, p);
    return ;
  }

  pivot_index_big = get_high_pivot(*b, cnt);
  pivot_index_small = get_low_pivot(*b, cnt);

  while(!IsEmpty(*b) && cnt != 0)
  {
    b_top = atoi(b->head->data);
    //피봇값을 고정하지 않으려면
    // 피봇값을 따로 변수로 저장 
    // 비교해서 크면 rra 작으면 ra 
    if (b_top < pivot_index_small){
      rb(b, 0);
      cnt_rb++;
    }
    else {
      pa(a, b);
      cnt_pa++;
      if (b_top < pivot_index_big)
      {
        ra(a, 0);
        cnt_ra++;
      }
    }
  cnt--;
  }
  p->count += cnt_rb + cnt_ra + cnt_pa;
  a_to_b(a, b, cnt_pa - cnt_ra, p);
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
}