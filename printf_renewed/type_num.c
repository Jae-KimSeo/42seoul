#include "printf.h"

static int              except_case_num(t_options *set)
{
    if (set->zero && set->minus)
        set->zero = 0;
    if (set->precision < 0)
        set->precision = -1;
    if (set->zero && set->precision != -1)
        set->zero = 0;
    
    return (0);
}

static char             *case_unsigned(char *str, t_options set, va_list arg)
{
    unsigned int        i;
    size_t              j;
    
    i = va_arg(arg, unsigned int);
    if (i == 0 && set.precision == 0)
        return (ft_strdup(""));
    j = 0;
    if ((int)i < 0)
        i = 4294967296 + (int)i;
    if (set.type == 'u')
        str = ft_itoa(i);
    else
        str = ft_itoa_base(i, 16);
    if (set.type == 'X')
        while (str[j])
        {
            str[j] = ft_toupper(str[j]);
            j++;
        }
    return (str);
}


int                     type_num(t_options *set, va_list arg)
{
    char *str;
    int ret;
    int i;
    
    str = NULL;
    ret = 0;
    if (except_case_num(set))
        return (-1);
    if (set->type == 'u' || set->type == 'x' || set->type == 'X')
        str = case_unsigned(str, *set, arg);
    else
    {
        i = va_arg(arg, int);
        if (i == 0 && set->precision == 0)
           str = ft_strdup("");
        else
            str = ft_itoa(i);
    }
    str = check_precision(str, *set);
    str = check_width(str, *set);
    ret = ft_strlen(str);
    ft_putstr_fd(str, 1);
    str = NULL;
    free(str);
    return (ret);
}
