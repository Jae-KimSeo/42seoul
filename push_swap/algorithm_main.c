#include "push_swap.h"

void b_to_a(Stack *a, Stack *b, int cnt, Pushswap* p);

//5이하를 섞을거야 
// pivot index 적절하게 설정해줘야함 

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

  if (cnt < 6){
    if (cnt > 3){
      sort_under_6_over_3_A(a, b, cnt, p);
    }
    else {
      sort_under_4_A(a, b, cnt, p);
    }
    return ;
  }
  pivot_index_big = get_high_pivot(*a, cnt);
  pivot_index_small = get_low_pivot(*a, cnt);

  while(!IsEmpty(*a) && cnt != 0)
  {
    a_top = atoi(a->head->data);
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
  
  if (cnt < 4){
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
#include <stdlib.h>

int main(int argc, char* argv[]){
    Stack *a;
    Stack *b;
    Pushswap *p;
  
    int tmp;
    int count;
    int sorted;

    sorted = TRUE;
    if (argc <= 1)
    {
      write(1, "Error", sizeof("Error"));
      return 0;
    }

    a = init();
    b = init();

    count = parcing_input(argc, argv, a);
    if (check_sorted(a) == TRUE)
      exit(0);
    
    p = push_swap_init();

    // 출력 인자들을 파이프로 넘기고 ctrl d가지 넘거야 함 
    //파이프라인, fd를 생성하고
    // write할때 fd를 생성한 값으로 넣어줌
    //파일디스크립터는 파이프를 여기에 열고 인자로 넣어주고 함수 종료 전에 클로즈하는게 나을듯 
    
    //int fds[2];
    //close(fds[0]);
    //dup2(fds[1], 1);
    //int fds[2];
    //pipe(fds);
    //close(fds[0]);
    a_to_b(a, b, size(*a), p);
    //close(fds[1]);
    //printf("check fd %d, %d\n", fds[0], fds[1]);
    //close(fds[1]); 
    //print_stack(a, b);
    printf("count %d", p->count);
    
    exit(0);
    //printf("instruction : %d\n", p->count);

    //exit(0);
    // delete_stack(a);
    // delete_stack(b);
    //system("leaks a.out");

    //메모리 leaks  
   // exit(0);
}
