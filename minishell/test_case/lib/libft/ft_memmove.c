
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*a;
	const char	*b;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	else if (dst < src)
		return (ft_memcpy(dst, src, len));
	a = dst + len - 1;
	b = src + len - 1;
	while (i < len)
	{
		*(a - i) = *(b - i);
		i++;
	}
	return (dst);
}
