
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		*a;

	i = 0;
	a = b;
	while (i < len)
	{
		a[i] = c;
		i++;
	}
	return (b);
}
