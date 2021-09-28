#include "push_swap.h"
#include "string.h"

void b_to_a(Stack *a, Stack *b, int cnt);

//5이하를 섞을거야 
// pivot index 적절하게 설정해줘야함 


void a_to_b(Stack *a, Stack *b, int cnt){
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
  if (cnt < 3){
    sort_under_6_A(a, b, cnt);
    return ;
  }
  pivot_index_big = get_high_pivot(*a, cnt);
  pivot_index_small = get_low_pivot(*a, cnt);

  printf("At Stack A, pivot : (1)%d (2)%d \n", pivot_index_big, pivot_index_small);
  print_stack(a,b);
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
  printf("check stack A cnt_ra, cnt_rb, cnt_pb: %d %d %d\n", cnt_ra, cnt_rb, cnt_pb);
  print_stack(a, b);
    if (cnt_ra - cnt_rb > 2 || cnt_ra - cnt_rb < -2){
      printf("PIVOT_ERROR");
      return ;
    }
    for (int i = 0; i < cnt_ra; i++)
      rrr(a, b);
    if (cnt_ra < cnt_rb)
      rrb(b, 0);
    else if (cnt_rb > cnt_ra)
      rra(a, 0);
  print_stack(a, b);
  a_to_b(a, b, cnt_ra);
  print_stack(a, b);
  b_to_a(a, b, cnt_rb);
  print_stack(a, b);
  b_to_a(a, b, cnt_pb - cnt_rb);
  print_stack(a, b);
}

void b_to_a(Stack *a, Stack *b, int cnt){
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
  
  if (cnt < 3){
    sort_under_6_B(a, b, cnt);
    return ;
  }
  pivot_index_big = get_high_pivot(*b, cnt);
  pivot_index_small = get_low_pivot(*b, cnt);

  printf("At Stack B, pivot : (1)%d (2)%d \n", pivot_index_big, pivot_index_small);

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
  printf("check stack B cnt_ra, cnt_rb, cnt_pa : %d %d %d\n", cnt_ra, cnt_rb, cnt_pa);
  print_stack(a, b);
  a_to_b(a, b, cnt_pa - cnt_ra);
  
  if (cnt_ra - cnt_rb > 2 || cnt_ra - cnt_rb < -2){
      printf("PIVOT_ERROR");
      return ;
  }
  for (int i = 0; i < cnt_ra; i++)
    rrr(a, b);
  if (cnt_ra < cnt_rb)
    rrb(b, 0);
  else if (cnt_ra > cnt_rb) 
    rra(a, 0);
  print_stack(a, b);
  a_to_b(a, b, cnt_ra);
  print_stack(a, b);
  b_to_a(a, b, cnt_rb);
}
#include <stdlib.h>

int main(int argc, char* argv[]){
    Stack *a;
    Stack *b;

    int tmp;
    int sorted;

    sorted = TRUE;
    if (argc <= 1)
    {
      write(1, "Error", sizeof("Error"));
      return 0;
    }
    a = init();
    b = init();

    for (int i = 1; i < argc; i++){
       if (i != 1){
        if (atoi(peek_head(a)) > atoi(argv[i]))
          sorted = FALSE;
       }
       push_head(a, argv[i]);
    }
    if (sorted == TRUE)
      return (0);

    a_to_b(a, b, size(*a));
    print_stack(a, b);

    //exit(0);
    // delete_stack(a);
    // delete_stack(b);
    //system("leaks a.out");

    //메모리 leaks  
   // exit(0);
}