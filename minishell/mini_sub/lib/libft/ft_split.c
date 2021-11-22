/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plee <plee@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:05:02 by plee              #+#    #+#             */
/*   Updated: 2021/11/19 17:05:04 by plee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	index;
	size_t	count;
	size_t	flag;

	index = 0;
	count = 0;
	flag = 0;
	while (s[index])
	{
		if (!flag && s[index] != c)
			flag = 1;
		if (flag && s[index] == c)
		{
			flag = 0;
			count++;
		}
		index++;
	}
	if (flag)
		count++;
	return (count);
}

static void	ft_allocate(char const *s, char **res, size_t head, size_t i)
{
	(*res) = (char *)malloc(sizeof(char) * (i - head + 1));
	ft_strlcpy(*res, s + head, i - head + 1);
}

static void	do_split(char const *s, char c, char **result)
{
	size_t	index;
	size_t	head;
	size_t	flag;

	index = 0;
	head = 0;
	flag = 0;
	while (s[index])
	{
		if (!flag && s[index] != c)
		{
			flag = 1;
			head = index;
		}
		if (flag && s[index] == c)
		{
			flag = 0;
			ft_allocate(s, result, head, index);
			result++;
		}
		index++;
	}
	if (flag)
		ft_allocate(s, result, head, index);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	wordcount;

	if (!s)
		return (0);
	wordcount = ft_wordcount(s, c);
	result = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!result)
		return (0);
	result[wordcount] = 0;
	do_split(s, c, result);
	return (result);
}
