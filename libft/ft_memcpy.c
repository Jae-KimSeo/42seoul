#include <unistd.h>

void *ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t i = 0;
    
    if (dst == NULL && src == NULL)
        return (NULL);
		
	while (i < n)
	{
		*((char*)dst + i) = *((char*)src + i);
		i++;
	}
	return (dst);
}
