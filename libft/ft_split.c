/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toispre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 19:02:11 by toispre           #+#    #+#             */
/*   Updated: 2021/01/04 21:31:56 by toispre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char *erase_deli(char *ptr, char c)
{
    if (!*ptr)
        return (NULL);
	while (*ptr == c)
		ptr++;
    
	return (ptr);
}
size_t get_count(char const *s, char c)
{
        size_t ret;
        char *ptr;

        ret = 0;
        if (*s == '\0')
            return (0);
        ptr = (char*)s;
        ptr = erase_deli(ptr, c);
        while (*ptr)
        {
            ret++;
            if(!(ptr = ft_strchr(ptr, c)))
               return (ret);
            ptr = erase_deli(ptr, c);
        }
        return (ret);
}
/*
size_t get_full_len(char *ptr, char c)
{
    size_t ret;
    
    ret = 0;
    while(*ptr)
        if (*(ptr++) != c)
            ret++;
    return (ret);
}
*/
char **allocate_part(char **ret, char const *s, char *ptr, char c, size_t count)
{
    char *ptr_forward;
    char *part;
    size_t i;
    
    i = 0;
    while (i < count)
    {
        ptr = erase_deli(ptr,c);
        if (!(ptr_forward = ft_strchr(ptr, c)))
            part = ft_strdup(ptr);
        else
            part = ft_substr(s, ptr - s, ptr_forward - ptr);
        if (part == NULL)
        {
            while (i)
                free(ret[--i]);
            return (NULL);
        }
        ret[i++] = part;
        ptr = ptr_forward;
    }
    ret[i] = 0;
    return (ret);
}

char **ft_split(char const *s, char c)
{
    char *ptr;
  //  size_t full_len;
    size_t count;
    char **ret;
   
    if (s == NULL)
        return (NULL);
    ptr = (char *)s;
    count = get_count(s, c);
  //  full_len = get_full_len(ptr, c);
    if(!(ret = (char**)malloc(sizeof(char*) * (count + 1))))
        return (NULL);
    ret = allocate_part(ret, s, ptr, c, count);
    return (ret);
}
/*
size_t get_len(char *s, char c)
{
    size_t ret;
    size_t i;

    i = 0;
    ret = 0;
    while (*(s + i) != c)
    {
        ret++;
        i++;
    }
    return (ret);
}
char *copy_part(char *s, char *part, size_t part_len)
{
    while (part_len--)
    {
        *(part) = *s;
        part++;
         s++;
    }
    *part = '\0';
    return (part);
}
 */
/*
char **ft_split(char const *s, char c)
{
    size_t full_len;
    size_t part_len;
    size_t count;
    size_t i;
    char **ret;
    char *part;
    char *ptr;

    i = 0;
    ptr = (char*)s;
    erase_deli(ptr, c);
    count = get_count(ptr, c);
    while (i < count)
    {
        part_len = get_len(ptr, c);
        full_len += part_len + 1;
        i++;
    }
    printf("count : %zu\n", count);
    
    if(!(ret = malloc(sizeof(char*) * full_len + 1)))
       return (NULL);
    *(ret + full_len) = NULL;
    i = 0;
    while (i < count)
    {
        part_len = get_len(ptr, c);
        if(!(part = malloc(sizeof(char*) * part_len + 1)))
           return (NULL);
        ptr = erase_deli(ptr, c);
        ret[i] = copy_part(ptr, part, part_len);
        ptr = ptr + part_len;
        free(part);
        i++;
    }
     
    return (ret);
}
*/
