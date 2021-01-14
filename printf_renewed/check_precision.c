#include "printf.h"

static char*            padding_precision(char *str, t_options set, int len)
{
    char                *padd;
    
    if (!(padd = (char *)malloc(sizeof(char) * (set.precision - len + 1))))
        return (NULL);
    ft_memset(padd, '0', set.precision - len);
    padd[set.precision - len] = '\0';
    if (str[0] == '-')
    {
        str[0] = '0';
        padd[0] = '-';
    }
    str = ft_strjoin(padd, str);
    padd = NULL;
    free(padd);
    return (str);
}

char    *check_precision(char *str, t_options set)
{
	int len;

    len = ft_strlen(str);
    if (set.type == 'd' || set.type == 'i' || set.type == 'u' || \
        set.type == 'x' || set.type == 'X' || set.type == 'p')
    {
        if (str[0] == '-')
            len--;
        if (set.precision > len)
            str = padding_precision(str, set, len);
    }
    if (set.type == 's')
        if (set.precision >= 0 && set.precision <= len)
            str[set.precision] = '\0';
	return (str);
}
// precision의 값에 따라 str이 변하는 경우를 처리.
