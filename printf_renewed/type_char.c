#include "printf.h"

static int              except_case_char(t_options *set)
{
    if (set->type != '%' && set->zero)
        return (1);
    if (set->zero && set->minus && set->type == '%')
    {
        set->zero = 0;
        set->precision = -1;
        set->type = '%';
    }
    if (!(set->precision == -1 || set->precision == 0) && set->type == 'c')
        return (1);
    return (0);
}


int                     type_char(t_options *set, va_list arg)
{
    char c;
    char *str;
    int ret;
    
    if (except_case_char(set))
        return (-1);
    if (set->type == 'c')
        c = va_arg(arg, int); // 다양한 자료형에 대한 처리
    else
        c = '%';
    set->width--;
    str = ft_strdup("");
    str = check_width(str, *set);
    if (set->minus == 1)
    {
        write(1, &c, 1);
        ft_putstr_fd(str, 1);
    }
    else
    {
        ft_putstr_fd(str, 1);
        write(1, &c, 1);
    }
    ret = ft_strlen(str) + 1;
    str = NULL;
    free(str);
    return (ret);
}
