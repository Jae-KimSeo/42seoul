

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
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
