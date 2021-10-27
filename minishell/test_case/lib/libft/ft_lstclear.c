
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void
*))
{
	t_list	*ptr;

	if (del == 0)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		del((*lst)->content);
		(*lst)->next = NULL;
		free(*lst);
		(*lst) = ptr;
	}
	lst = NULL;
	free(lst);
}
