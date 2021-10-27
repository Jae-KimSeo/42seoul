
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		len;

	len = 0;
	if (src == NULL)
		return (0);
	while ((len < dstsize - 1) && *src && (dstsize != 0))
	{
		*dst = *src;
		src++;
		dst++;
		len++;
	}
	if (dstsize != 0)
		*dst = '\0';
	while (*(src++))
		len++;
	return (len);
}
