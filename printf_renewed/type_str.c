#include "printf.h"

static int              except_case_str(t_options *set)
{
    if (set->zero && set->minus)
        set->zero = 0;
    if (set->precision < 0)
        set->precision = -1;
    return (0);
}

static char             *case_str(t_options set, va_list arg)
{
    char *str;
    char c;
    
    str= NULL;
    c = '\0';
    if (set.type == 's')
    {
        str = va_arg(arg, char *);
        if (str == NULL)
            str = ft_strdup("(null)");
        else
            str = ft_strdup(str);
    }
  
    return (str);
}

int                     type_str(t_options *set, va_list arg)
{
    char *str;
    int ret;
    
    str = NULL;
    ret = 0;
    if (except_case_str(set))
        return (-1);
    str = case_str(*set, arg);
    str = check_precision(str, *set);
    str = check_width(str, *set);
    ft_putstr_fd(str, 1);
    ret = ft_strlen(str);
    str = NULL;
    free(str);
    return (ret);
}
