

#include "libft.h"

char	*ft_strdup(const char *s1)
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
