
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ret;
	size_t			len;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	*(ret + len) = '\0';
	while (i < len)
	{
		*(ret + i) = f(i, *(s + i));
		i++;
	}
	return (ret);
}
