/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:43:56 by jae-kim           #+#    #+#             */
/*   Updated: 2021/01/04 23:26:39 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list *new_lst;
	t_list *temp;
	t_list *ret;

	if(!lst)
		return (NULL);
	temp = lst;
	if(!(new_lst = ft_lstnew(f(lst->content))))
		return (NULL);
	ret = new_lst;
	lst = lst->next;
	while(lst)
	{
		if(!(new_lst->next = ft_lstnew(f(lst->content))))
			return (NULL);
        new_lst = new_lst->next;
		lst = lst->next;
	}
	ft_lstclear(&temp, del);
	return (ret);
}
