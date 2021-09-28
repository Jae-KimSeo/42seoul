#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "util.h"
#include "sort_util.h"
#include "stack_link_list.h"
#define TRUE 1
#define FALSE 0

typedef struct pushswap {
  int count;
} Pushswap;

int check_input_number(char *input, Pushswap *p);
void sa(Stack *a, int ss);
void sb(Stack *b, int ss);
void ss(Stack *a, Stack *b);
void pa(Stack *a, Stack *b);
void pb(Stack *a, Stack *b);
void ra(Stack *a, int rr);
void rb(Stack *b, int rr);
void rr(Stack *a, Stack *b);
void rra(Stack *a, int rrr);
void rrb(Stack *b, int rrr);
void rrr(Stack *a, Stack *b);

#endif 