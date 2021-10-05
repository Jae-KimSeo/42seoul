#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0
# define INT_MAX 2147483647
# include "stack_link_list.h"
# include "libft/libft.h"

typedef struct s_pushswap {
	int		count;
}				t_Pushswap;

t_Pushswap		*push_swap_init(void);
int				sa(t_Stack *a, int ss);
int				sb(t_Stack *b, int ss);
int				ss(t_Stack *a, t_Stack *b);
int				pa(t_Stack *a, t_Stack *b);
int				pb(t_Stack *a, t_Stack *b);
int				ra(t_Stack *a, int rr);
int				rb(t_Stack *b, int rr);
int				rr(t_Stack *a, t_Stack *b);
int				rra(t_Stack *a, int rrr);
int				rrb(t_Stack *b, int rrr);
int				rrr(t_Stack *a, t_Stack *b);

void			sort_under_4_A(t_Stack *a, t_Stack *b, int cnt, t_Pushswap *p);
void			sort_under_4_B(t_Stack *a, t_Stack *b, int cnt, t_Pushswap *p);
void			sort_under_6_over_3_A(t_Stack	*a, t_Stack *b, int cnt, t_Pushswap *p);
int				get_high_pivot(t_Stack	s, int	cnt);
int				get_low_pivot(t_Stack	s, int	cnt);

int				parcing_input(int argc, char **argv, t_Stack *a);
int				check_valid_input(char *input, t_Stack *a);
int				check_sorted(t_Stack *a, int cnt);
int				check_reverse_sorted(t_Stack *b, int cnt);

#endif