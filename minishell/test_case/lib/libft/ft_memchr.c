
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (i < (int)n)
	{
		if ((unsigned char)*((char *)s + i) == (unsigned char)c)
			return (ptr);
		else
			ptr++;
		i++;
	}
	return (NULL);
}
