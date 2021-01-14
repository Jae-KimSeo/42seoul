#include "printf.h"

static char *padding_width(char *str, t_options set, char p, int len)
{
    char *padd;
    
    if (!(padd = (char *)malloc(sizeof(char) * (set.width - len + 1))))
        return (NULL);
    ft_memset(padd, p, set.width - len);
    padd[set.width - len] = '\0';
    if (set.minus != 1)
    {
        if (set.zero && str[0] == '-')
        {
            padd[0] = '-';
            str[0] = p;
        }
        str = ft_strjoin(padd, str);
    }
    else
        str = ft_strjoin(str, padd);
    padd = NULL;
    free(padd);
    return (str);
}

char *check_width(char *str, t_options set)
{
	int len;
	char p;
	
	len = ft_strlen(str);
    if (set.zero == 1)
		p = '0';
	else
		p = ' ';
	if (set.width > len)
		str = padding_width(str, set, p, len);
	return (str);
}
