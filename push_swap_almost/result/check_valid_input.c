#include "push_swap.h"

int	parcing_input(int argc, char **argv, t_Stack *a)
{
	int			input_count;
	char		*input;
	int			i;
	int			j;
	char		**ptr;

	i = 1;
	if (argc == 1)
	{
		exit (0);
	}
	while (argv[i])
	{
		ptr = ft_split(argv[i], ' ');
		if (ft_strlen(ptr[0]) == ft_strlen(argv[i]))
		{
			input = argv[i];
			if (check_valid_input(input, a) == TRUE)
			{
				push_tail(a, input);
				input_count++;
			}
			else
			{
				write(1, "Error", 5);
				exit (1);
			}
		}
		else
		{
			j = 0;
			while (ptr[j])
			{
				input = ptr[j];
				if (check_valid_input(input, a) == TRUE)
				{
					push_tail(a, input);
					input_count++;
				}
				else
				{
					write(1, "Error", 5);
					exit (1);
				}
				j++;
			}
		}
		i++;
	}
	return (input_count);
}

int	check_valid_input(char *input, t_Stack *a)
{
	t_ListNode	*ptr;
	int			i;

	i = 0;
	ptr = a->head;
	while (ptr)
	{
		if (ptr->data == input)
			return (FALSE);
		ptr = ptr->prev;
	}
	while (input[i])
	{
		if (ft_isdigit(input[i]) == 0)
			return (FALSE);
		i++;
	}
	if (ft_atoi(input) > INT_MAX)
		return (FALSE);
	return (TRUE);
}

int	check_sorted(t_Stack *a, int cnt)
{
	t_ListNode	*ptr;
	int num;

	if (size(*a) < 2)
		return (TRUE);
	ptr = a->head;
	while (ptr->prev && num != 0)
	{
		if (atoi(ptr->data) > atoi(ptr->prev->data))
			return (FALSE);
		ptr = ptr->prev;
		num--;
	}
	return (TRUE);
}


int check_reverse_sorted(t_Stack *b, int cnt){
	t_ListNode *ptr;
	int num;

	if (size(*b) < 2)
		return (TRUE);
	ptr = b->head;
	num = cnt;
	while (ptr->prev && num != 0)
	{
		if (ft_atoi(ptr->data) < ft_atoi(ptr->prev->data))
			return (FALSE);
		ptr = ptr->prev;
		num--;
	}
	return (TRUE);
	}
