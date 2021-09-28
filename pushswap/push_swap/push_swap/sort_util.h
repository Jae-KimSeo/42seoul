#ifndef _SORT_UTIL_H
# define _SORT_UTIL_H
# define INT_MAX 2147483647

#include "stack_link_list.h"
#include "push_swap.h"


void sort_under_6_A(Stack *a, Stack *b, int cnt);
void sort_under_6_B(Stack *a, Stack *b, int cnt);
int get_high_pivot(Stack s, int cnt);
int get_low_pivot(Stack s, int cnt);

#endif