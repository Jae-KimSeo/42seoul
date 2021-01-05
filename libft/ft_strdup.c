/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 02:02:06 by jae-kim           #+#    #+#             */
/*   Updated: 2021/01/02 02:06:04 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char *ft_strdup(const char *s1)
{
	char *ptr;
    char *ret;
	size_t len;

	len = ft_strlen(s1);
	ptr = malloc(len + 1);
    if (ptr == NULL)
        return (NULL);
    ret = ptr;
	while (*s1)
	{
		*ptr = *s1;
		ptr++;
		s1++;
	}
	*ptr = '\0';
	return (ret);
}
