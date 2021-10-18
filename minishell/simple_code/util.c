size_t			ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}



char	*ft_strchr(const char *s, int c)
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

static char		*erase_deli(char *ptr, char c)
{
	if (!*ptr)
		return (NULL);
	while (*ptr == c)
		ptr++;
	return (ptr);
}

static size_t	get_count(char const *s, char c)
{
	size_t		ret;
	char		*ptr;

	ret = 0;
	if (*s == '\0')
		return (0);
	if (c == 0)
		return (1);
	ptr = (char*)s;
	ptr = erase_deli(ptr, c);
	while (*ptr)
	{
		ret++;
		if (!(ptr = ft_strchr(ptr, c)))
			return (ret);
		ptr = erase_deli(ptr, c);
	}
	return (ret);
}

static void		allocate_part(char **ret, char const *s, char c, size_t count)
{
	char		*ptr_forward;
	char		*ptr;
	char		*part;
	size_t		i;

	i = 0;
	ptr = (char *)s;
	while (i < count)
	{
		ptr = erase_deli(ptr, c);
		if (!(ptr_forward = ft_strchr(ptr, c)))
			part = ft_strdup(ptr);
		else
			part = ft_substr(s, ptr - s, ptr_forward - ptr);
		if (part == NULL)
		{
			while (i)
				free(ret[--i]);
			ret = NULL;
			free(ret);
		}
		ret[i++] = part;
		ptr = ptr_forward;
	}
	ret[i] = 0;
}

char			*ft_strdup(const char *s1)
{
	char		*ptr;
	char		*ret;
	size_t		len;

	len = ft_strlen(s1);
	ptr = malloc(sizeof(char) * (len + 1));
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
char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	count;
	int				i;

	count = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*(s + count))
	{
		if (count == start)
		{
			ft_strlcpy(ret, s + count, len + 1);
			break ;
		}
		count++;
	}
	return (ret);
}


char			**ft_split(char const *s, char c)
{
	size_t		count;
	char		**ret;

	if (s == NULL)
		return (NULL);
	count = get_count(s, c);
	if (!(ret = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	ret[count] = 0;
	if (count == 0)
		return (ret);
	allocate_part(ret, s, c, count);
	return (ret);
}