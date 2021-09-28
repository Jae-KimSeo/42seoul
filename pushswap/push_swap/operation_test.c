#include "push_swap.h"

void b_to_a(Stack *a, Stack *b, int cnt);

void a_to_b(Stack *a, Stack *b, int cnt){
  int pivot_index_big;
  int pivot_index_small;
  int cnt_pb;
  int cnt_ra;
  int cnt_rb;

  cnt_pb = 0;
  cnt_ra = 0;
  cnt_rb = 0;

  if (a == NULL || b == NULL)
      return ;
  if (cnt < 3){
    if (cnt == 2)
      if (a->head->data > a->head->prev->data)
        sa(a);
    return ;
  }
  if (a->head->data > a->head->prev->data){
    pivot_index_big = a->head->data;
    pivot_index_small = a->head->prev->data;
    //push_head(b, pop_head(a));
  }
  else {
    pivot_index_big = a->head->prev->data;
    pivot_index_small = a->head->data;
    //push_head(b, pop_head(a));
  }

  while(!IsEmpty(*a) && cnt != 0)
  {
    if (a->head->data >= pivot_index_big){
      ra(a);
      cnt_ra++;
    }
    else {
      pb(a, b);
      cnt_pb++;
      if (a->head->data >= pivot_index_small)
      {
        rb(b);
        cnt_rb++;
      }
    }
    cnt--;
  }
  if (cnt_ra < cnt_rb){
    for (int i = 0; i < cnt_ra; i++)
      rrr(a, b);
    for (int i = 0; i < cnt_rb - cnt_ra; i++)
      rb(b);
  }
  else 
  {
    for (int i = 0; i < cnt_rb; i++)
      rrr(a, b);
    for (int i = 0; i < cnt_ra - cnt_rb; i++)
      ra(a);
  }  

  a_to_b(a, b, cnt_ra);
  b_to_a(a, b, cnt_pb);
  b_to_a(a, b, cnt_pb - cnt_rb);
  printf("check");
  printf("\n");
//   print_stack(a, b);
  printf("\n");
}

void b_to_a(Stack *a, Stack *b, int cnt){
  int pivot_index_big;
  int pivot_index_small;
  int cnt_pa;
  int cnt_ra;
  int cnt_rb;

  cnt_pa = 0;
  cnt_ra = 0;
  cnt_rb = 0;

  if (a == NULL || b == NULL)
      return ;
  if (cnt < 3){
    if (cnt == 2)
      if (b->head->data > b->head->prev->data)
        sb(b);
    while (cnt != 0){
      pa(a, b);
      cnt--;
    }
    return ;
      }
  if (b->head->data > b->head->prev->data){
    pivot_index_big = b->head->data;
    pivot_index_small = b->head->prev->data;
    //push_head(a, pop_head(b));
  }else {
    pivot_index_big = b->head->prev->data;
    pivot_index_small = b->head->data;
  }


  while(!IsEmpty(*b) && cnt != 0)
  {
    //피봇값을 고정하지 않으려면
    // 피봇값을 따로 변수로 저장 
    // 비교해서 크면 rra 작으면 ra 
  if (b->head->data < pivot_index_small){
      rb(b);
      cnt_rb++;
    }
    else {
      pa(a, b);
      cnt_pa++;
      if (b->head->data < pivot_index_big)
      {
        ra(a);
        cnt_ra++;
      }
    }
  cnt--;
  }
  a_to_b(a, b, cnt_pa - cnt_ra);

  if (cnt_ra < cnt_rb){
    for (int i = 0; i < cnt_ra; i++)
      rrr(a, b);
    for (int i = 0; i < cnt_rb-cnt_ra; i++)
      rb(b);
  }
  else 
  {
    for (int i = 0; i < cnt_rb; i++)
      rrr(a, b);
    for (int i = 0; i < cnt_ra-cnt_rb; i++)
      ra(a);
  }  
  a_to_b(a, b, cnt_ra);
  b_to_a(a, b, cnt_rb);

  printf("\n");
//   print_stack(a, b);
  printf("\n");
}

/*
check_input()
{
  
  2.중복 숫자가 들어온 경우. error
  3.MAXINT가 넘은 경우
  4.인자가 안들어온 경우 아무것도 출력이 안되야됨
  5.정렬이 된 숫자가 들어온 경우 아무것도 출력이 안되야함.
  6.
}

check_input_number()
{
  1.숫자가 아닌 매개변수가 들어온 경우. error
  2.매개변수가 띄어쓰기가 있는 경우 count++
  3.매개변수가 숫자인데 "1 2" 3 4 의 경우 1 2 3 4로 자르기
}
*/

int IsNumber(int c)
{
  if((c >= '0' && c <= '9'))
    return (1);   
  else
    return (0);
}

#include <string.h>
int count_input_number(char *input)
{
  int i;
  int count;

  i = 0;
  count = 0;
  if(strchr(input, ' ') != NULL) {
    while (input[i] != '\0')
    {
      if (input[i] == ' ')
      {
        i++;
        count--;
      }
      if (IsNumber(input[i]) == 0)
      {
        write(1, "Error", sizeof("Error"));
        return (0);
      }
      printf("%c\n", input[i]);
      i++;
    }
    count = count + i;
  }
  else {
    printf("no space");
    printf("%s\n", input);
  }
  return (count);
}

int main(int argc, char* argv[]){
    Stack *a;
    Stack *b;
    int i;
    int split_count;
    int tmp;

    if (argc <= 1)
    {
      write(1, "Error", sizeof("Error"));
      return 0;
    }
    a = init();
    b = init();
    i = 1;
    split_count = 0;

    //count까지 함.
    while (i < argc) {
      tmp = count_input_number(argv[i]);
      if(split_count < tmp) {
        split_count = tmp;
      }
      i++;
    }
    
    printf("split_count: %d\n", split_count);
    for (int i = 1; i < argc; i++) {
        
    }
    delete_stack(a);
    delete_stack(b);
}