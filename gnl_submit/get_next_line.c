/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 22:03:03 by jae-kim           #+#    #+#             */
/*   Updated: 2021/01/19 22:18:06 by toispre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char				*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == '\0')
		if ((char)c == '\0')
			return ((char *)s);
	return (NULL);
}

int						func_free(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		str[i] = NULL;
		free(str[i]);
		i++;
	}
	str = NULL;
	free(str);
	return (-1);
}

static char				**ft_split_line(char const *s)
{
	char				**ret;
	char				*ptr_enter;
	char				*ptr;

	ptr = (char *)s;
	if (s == NULL)
		return (NULL);
	if (!(ret = (char**)malloc(sizeof(char*) * (3))))
		return (NULL);
	ret[2] = 0;
	ptr_enter = ft_strchr(ptr, '\n');
	ret[0] = ft_substr(ptr, 0, ptr_enter - ptr);
	ret[1] = ft_substr(ptr, (int)(ptr_enter - ptr) + 1, \
			ft_strlen(ptr) - (ptr_enter - ptr) - 1);
	if (ret[0] == NULL || ret[1] == NULL)
		func_free(ret);
	return (ret);
}

size_t					buffer_store(char **backup, int fd)
{
	char				*buf;
	int					ret;
	char				*tmp;

	ret = BUFFER_SIZE;
	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_strchr(*backup, '\n') && (ret == BUFFER_SIZE))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			break ;
		buf[ret] = 0;
		if (*backup == NULL)
			*backup = ft_strdup(buf);
		else
		{
			tmp = *backup;
			*backup = ft_strjoin(*backup, buf);
			free(tmp);
		}
	}
	free(buf);
	return (ret);
}

int						get_next_line(int fd, char **line)
{
	static char			*backup;
	char				**split_ptr;
	int					i;
	char				*tmp;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if ((i = buffer_store(&backup, fd)) == -1)
		return (-1);
	if (i == BUFFER_SIZE || ft_strchr(backup, '\n'))
	{
		split_ptr = ft_split_line(backup);
		*line = split_ptr[0];
		tmp = backup;
		backup = split_ptr[1];
		free(tmp);
		free(split_ptr);
	}
	else
	{
		*line = backup;
		backup = 0;
		return (0);
	}
	return (1);
}
