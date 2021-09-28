#include "sort_util.h"
#include "string.h"

#define TRUE 1
#define FALSE 0

/*
int check_already_sorted(Stack a){
    int first, second;
    
    first = atoi(pop_head(a));
    while (!IsEmpty(a)){
        second = atoi(pop_head(a));
        if (first > second)
            return (FALSE);
        first = second;
    }
    return (TRUE);
}
*/
void sort_under_6_A(Stack *a, Stack *b, int cnt){
  if (cnt < 2)
    return ;
  int a_top;
  int a_second;
  int min;
  int num;
  int tmp_cnt;
  int rotate_num;
  ListNode *ptr;

  num = cnt;
  while (num >= 3){

    tmp_cnt = 0;
    rotate_num = 0;
    ptr= a->head;
    min = a_top = atoi(ptr->data);
    for (int i = 0; i < num; i++){ 
      a_top = atoi(ptr->data);
      if (a_top < min){
        min = a_top;
        rotate_num = tmp_cnt;
      }
      tmp_cnt++;
      ptr = ptr->prev;
    }
    if (IsFull(*b))
      return ;
    for (int i = 0; i < rotate_num; i++)
        ra(a, 0);
    pb(a, b);
    for (int i = 0; i < rotate_num; i++)
        rra(a, 0);    
    num--;
}
if (atoi(a->head->prev->data) > atoi(a->head->data))
    sa(a, 0);
    
while (cnt >= 3){
    pa(a, b);
    cnt--;
}
}

void sort_under_6_B(Stack *a, Stack *b, int cnt){
  if (cnt < 2){
    if (cnt == 1)
        pa(a, b);
    return ;
  }

  int b_top;
  int max;
  int num;
  int tmp_cnt;
  int rotate_num;
  ListNode *ptr;

  num = cnt;
  while (num >= 3){
    tmp_cnt = 0;
    rotate_num = 0;
    ptr= b->head;
    max = 0;
    for (int i = 0; i < num; i++){ 
      b_top = atoi(ptr->data);
      if (b_top > max){
        max = b_top;
        rotate_num = tmp_cnt;
      }
      tmp_cnt++;
      ptr = ptr->prev;
    }
    if (IsFull(*a))
      return ;
    for (int i = 0; i < rotate_num; i++)
        rb(b, 0);
    pa(a, b);
    for (int i = 0; i < rotate_num; i++)
        rrb(b, 0);
    num--;
  }
  if (atoi(b->head->prev->data) > atoi(b->head->data))
    sb(b, 0);
  while(num != 0){
    pa(a, b);
    ra(a, 0);
    num--;
  }
}
//2개의 피봇을 찾아야해
// 하나는 1/3, 하나는 2/3
// cnt 해서 up 은 cnt의 1/3개, down은 cnt의 아래로1/3개

static int check_value_in_array(int *s, int value, int cnt){
    int i;

    i = 0;
    if (s == NULL)
        return (-1);
    while(s[i] != 0 && i < cnt){
        if (s[i] == value){
            return 1;
        }
        i++;
    }
    return 0;
}

int get_high_pivot(Stack s, int cnt){
    //원하는 값보다 큰 max를 cnt/3 개 만큼 찾으면 됨 
    int upper_cnt;

    if (cnt % 3 == 2)
        upper_cnt = (int)(cnt/3) + 1;
    else
        upper_cnt = (int)(cnt/3);
    int max;
    int top;
    int size;
    int i;
    int *upper;
    int num;
    ListNode *ptr;

    if (!(upper = (int *)malloc(sizeof(int) * (upper_cnt))))
        exit(1);
    memset(upper, 0, upper_cnt * sizeof(int));
    i = 0;
    num = upper_cnt;
    while (num != 0){
        //max를 지워야해 
        max = 0;
        size = cnt;
        ptr = s.head;
        while(size != 0){
            top = atoi(ptr->data);
            if (top > max){
                if (check_value_in_array(upper, top, upper_cnt) == 0)
                    max = top;
            }
            ptr = ptr->prev;
            size--;
        }
        upper[i] = max;
        i++;
        num--;
    }
    free(upper);
    return (max);
}


int get_low_pivot(Stack s, int cnt){
    //원하는 값보다 큰 max를 cnt/3 개 만큼 찾으면 됨 
    int lower_cnt;
   
    if (cnt % 3 == 0 || cnt % 3 == 2)
        lower_cnt = (int)(cnt/3) + 1; 
    else if (cnt % 3 == 1)
        lower_cnt = (int)(cnt/3) + 2;
    
    int min;
    int top;
    int size;
    int i;
    int *lower;
    int num;
    ListNode *ptr;

    if (!(lower = (int *)malloc(sizeof(int) * (lower_cnt))))
        exit(1);
    memset(lower, 0, lower_cnt * sizeof(int));
    i = 0;
    num = lower_cnt;
    while (num != 0){
        //max를 지워야해 
        min = INT_MAX;
        size = cnt;
        ptr = s.head;
        while(size != 0){
            top = atoi(ptr->data);
            if (top < min){
                if (check_value_in_array(lower, top, lower_cnt) == 0)
                {
                    min = top;
                }
            }
            ptr = ptr->prev;
            size--;
        }
        lower[i] = min;
        i++;
        num--;
    }
    free(lower);
    return (min);
}