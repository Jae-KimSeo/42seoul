#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#define TRUE 1
#define FALSE 0
#define INT_MAX 2147483647
#include "stack_link_list.h"
#include "libft/libft.h"


typedef struct pushswap {
  int count;
} Pushswap;

//int check_input_number(char *input, Pushswap *p);
Pushswap* push_swap_init();
int sa(Stack *a, int ss);
int sb(Stack *b, int ss);
int ss(Stack *a, Stack *b);
int pa(Stack *a, Stack *b);
int pb(Stack *a, Stack *b);
int ra(Stack *a, int rr);
int rb(Stack *b, int rr);
int rr(Stack *a, Stack *b);
int rra(Stack *a, int rrr);
int rrb(Stack *b, int rrr);
int rrr(Stack *a, Stack *b);

void sort_under_4_A(Stack *a, Stack *b, int cnt, Pushswap *p);
void sort_under_4_B(Stack *a, Stack *b, int cnt, Pushswap *p);
void sort_using_one_A(Stack *a, Stack *b, int cnt, Pushswap *p);
void sort_under_20_B(Stack *a, Stack *b, int cnt, Pushswap *p);

int parcing_input(int argc, char **argv, Stack *a);
int check_valid_input(char *input, Stack *a);
int check_sorted(Stack *a, int cnt);
int check_reverse_sorted(Stack *b, int cnt);

void a_to_b(Stack *a, Stack *b, int cnt, Pushswap *p);
void b_to_a(Stack *a, Stack *b, int cnt, Pushswap *p);
int	roll_back(Stack *a, Stack *b, int cnt_ra, int cnt_rb);

int get_middle_pivot(Stack *a, int cnt);
int get_high_pivot(Stack *s, int cnt);
int get_low_pivot(Stack *s, int cnt);

#endif 