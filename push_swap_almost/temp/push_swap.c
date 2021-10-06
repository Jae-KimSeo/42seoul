#include "push_swap.h"


t_Pushswap *push_swap_init(){
  t_Pushswap *ret;
  if (!(ret = (t_Pushswap*)malloc(sizeof(t_Pushswap))))
    return (NULL);
  ret->count = 0;

  return (ret);
}
int sa(Stack *a, int ss){
    if (size(*a) < 2)
      return (0);
    if (ss == 0){
      //dup2(1, STDOUT_FILENO);
      write(1, "sa\n", 3);
      //write(4, "sa\n", sizeof("sa\n"));

    }
    element m, n;
    m = pop_head(a);
    n = pop_head(a);
    push_head(a, m);
    push_head(a, n);

    return (1);
}

int sb(Stack *b, int ss){
    if (size(*b) < 2)
      return (0);
    if (ss == 0){
      write(1, "sb\n", 3);
      //write(4, "sb\n", sizeof("sb\n"));
    }
    element m, n;
    m = pop_head(b);
    n = pop_head(b);
    push_head(b, m);
    push_head(b, n);
    return (1);
}

int ss(Stack *a, Stack *b){
    if (size(*a) == 0)
      return (0);

    if (size(*b) == 0)
      return (0);

  write(1, "ss\n", 3);
  //write(4, "ss\n", sizeof("ss\n"));
  sa(a, 1);
  sb(b, 1);

  return (1);
}

int pa(Stack *a, Stack *b){

  if (IsEmpty(*b)){
    return (0);
  }

  write(1, "pa\n", 3);
  //write(4, "pa\n", sizeof("pa\n"));

  element item;
  item = pop_head(b);
  push_head(a, item);

  return (1);
}

int pb(Stack *a, Stack *b){

  if (IsEmpty(*a)){
    return (0);
  }
  write(1, "pb\n", 3);
  //write(4, "pb\n", sizeof("pb\n"));

  element item;
  item = pop_head(a);
  push_head(b, item);

  return (1);
}

int ra(Stack *a, int rr){

  if (size(*a) < 2)
      return (0);
  if (rr == 0){
    write(1, "ra\n", 3);
    //write(4, "ra\n", sizeof("ra\n"));
  }
  element item;
  item = pop_head(a);
  push_tail(a, item);

  return (1);

}

int rb(Stack *b, int rr) {

  if (size(*b) < 2)
    return (0);
  if (rr == 0){
    write(1, "rb\n", 3);
    //write(4, "rb\n", sizeof("rb\n"));
  }
  element item;
  item = pop_head(b);
  push_tail(b, item);
  return (1);
}

int rr(Stack *a, Stack *b){
    if (size(*a) == 0)
      return (0);

    if (size(*b) == 0)
      return (0);

  write(1, "rr\n", 3);
  //write(4, "rr\n", sizeof("rr\n"));
  ra(a, 1);
  rb(b, 1);

  return (1);
}

int rra(Stack *a, int rrr){

  if (a->count < 2)
      return (0);
  if (rrr == 0){
    write(1, "rra\n", 4);
    //write(4, "rra\n", sizeof("rra\n"));

  }
  element item;
  item = pop_tail(a);
  push_head(a, item);

  return (1);
}

int rrb(Stack *b, int rrr){
  if (b->count < 2)
      return (0);
  if (rrr == 0){
    write(1, "rrb\n", 4);
    //write(4, "rrb\n", sizeof("rrb\n"));

  }
  element item;
  item = pop_tail(b);
  push_head(b, item);

  return (1);
}

int rrr(Stack *a, Stack *b){
    if (size(*a) == 0)
      return (0);
    if (size(*b) == 0)
      return (0);
  write(1, "rrr\n", 4);
  //write(4, "rrr\n", sizeof("rrr\n"));
  rra(a, 1);
  rrb(b, 1);

  return (1);
}