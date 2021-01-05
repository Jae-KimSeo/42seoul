/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:37:48 by jae-kim           #+#    #+#             */
/*   Updated: 2020/12/26 11:38:02 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void *ft_memchr(const void *s, int c, size_t n)
{
	char *ptr = (char *)s;
	int i = 0;
    
	while (i < (int)n)
	{
		if ((unsigned char)*((char*)s + i) == (unsigned char)c)
        {
            return ptr;
        }
        else
            ptr++;
        i++;
	}
	return NULL;
}
