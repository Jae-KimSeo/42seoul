/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toispre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:30:18 by toispre           #+#    #+#             */
/*   Updated: 2021/01/04 20:35:51 by toispre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int i;
	t_list *ptr;

	if (lst == NULL)
		return (0);
	i = 1;
	ptr = lst;
	while(ptr->next)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
