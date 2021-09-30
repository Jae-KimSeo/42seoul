#include "push_swap.h"

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



void sort_under_6_over_3_A(Stack *a, Stack *b, int cnt, Pushswap *p){
    
    int min;
    int head;
    int post_head;
    int tail;
    int code;
    int num;

    num = cnt;
    while (num > 3){
        print_stack(a, b);
        min = INT_MAX;
        head = atoi(a->head->data);
        post_head = atoi(a->head->prev->data);
        tail = atoi(a->tail->data);
        if (head > post_head){
            min = post_head;
            code = 2;
        }
        else{
            min = head;
            code = 1;    
        }
        if (min > tail){
            min = tail;
            code = 3;
        }
    
        if (code == 1){
            pb(a, b);
            p->count++;
        }
        else if (code == 2){
            sa(a, 0);
            pb(a, b);
            p->count += 2;
        } else {
            rra(a, 0);
            pb(a, b);
            p->count += 2;
        }
        if (num == 5 && code == 3){
            rra(a, 0);
            p->count++;
        }else if (num == 5){
            ra(a, 0);
            p->count++;
        }
        num--;
    }
    sort_under_4_A(a, b, num, p);
    sort_under_4_B(a, b, 2, p);
}

void sort_under_4_A(Stack *a, Stack *b, int cnt, Pushswap* p){
  if (cnt == 0)
    return ;
  int a_top;
  int a_second;
  int min;
  int num;
  int tmp_cnt;
  int rotate_num;
  ListNode *ptr;

  num = cnt;

  /*
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
*/
  
    ptr = a->head;
    if(cnt >= 2){
    
            if (atoi(ptr->prev->data) < atoi(ptr->data)){
               sa(a, 0);
                p->count++;
        
            ptr = a->head->prev;
            if (cnt == 3){
                if (atoi(ptr->prev->data) < atoi(ptr->data)){
                    ra(a, 0);
                    sa(a, 0);
                    rra(a, 0);
                    p->count+=3;
                    ptr = a->head;
                    if (atoi(ptr->data) > atoi(ptr->prev->data)){
                        sa(a, 0);
                        p->count++;
                    }
                }
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

static int check_value_in_array(int *s, int value, int cnt){
    int i;

    i = 0;
    if (s == NULL)
        return (-1);
    while(s[i] != -1 && i < cnt){
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
    memset(upper, -1, (upper_cnt) * sizeof(int));
    i = 0;
    num = upper_cnt;

    while (num != 0){
        //max를 지워야해 
        max = -1;
        size = cnt;
        ptr = s.head;
        while(size != 0){
            top = atoi(ptr->data);
            if (top > max){
                if (check_value_in_array(upper, top, upper_cnt) == 0)
                    max = top;
            }
            if (ptr->prev != NULL)
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
   
    if (cnt % 3 == 2 || cnt % 3 == 0)
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
    memset(lower, -1, lower_cnt * sizeof(int));
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
            if (ptr->prev != NULL)
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