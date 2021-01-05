#include <unistd.h>

void *ft_memset(void *b, int c, size_t len)
{
	size_t i = 0;
    unsigned char *a;
    
    a = b;
	while (i < len)
	{	
		a[i] = c;
		i++;
	}
	return (b);
}

