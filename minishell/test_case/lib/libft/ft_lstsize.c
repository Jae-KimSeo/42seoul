
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ptr;

	if (lst == NULL)
		return (0);
	i = 1;
	ptr = lst;
	while (ptr->next)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
