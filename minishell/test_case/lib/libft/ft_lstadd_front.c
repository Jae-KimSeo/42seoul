

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
