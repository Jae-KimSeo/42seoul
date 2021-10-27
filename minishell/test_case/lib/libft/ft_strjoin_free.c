
#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2, int check)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	if (check & 1)
		free((char *)s1);
	if (check & 2)
		free((char *)s2);
	return (result);
}
