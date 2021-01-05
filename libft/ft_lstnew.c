/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toispre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:05:15 by toispre           #+#    #+#             */
/*   Updated: 2021/01/04 20:12:13 by toispre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *ret;

	if (!(ret = malloc(sizeof(t_list))))
			return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}
