#include "printf.h"

static char             *case_unsigned(char *str, t_options set, va_list arg)
{
    unsigned int        i;
    size_t              j;
    
    i = va_arg(arg, unsigned int);
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

static char             *case_integer(t_options set, va_list arg)
{
    char *str;
    
    str = NULL;
    if (set.type == 'u' || set.type == 'x' || set.type == 'X')
        str = case_unsigned(str, set, arg);
    else if (set.type == 'd' || set.type == 'i')
        str = ft_itoa(va_arg(arg, int));
    else if (set.type == 'p')
        str = ft_itoa_base(va_arg(arg, long long), 16);
    return (str);
}

static char             *case_word(t_options set, va_list arg)
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
    if (set.type == 'c')
    {
        c = va_arg(arg, int); // 다양한 자료형에 대한 처리
        str = ft_strdup(&c);
        printf("check %s\n", str);
        if (c == 0)
            write(1, &c, 1);
    }
    if (set.type == '%')
    {
        c = '%';
        str = ft_strdup(&c);
    }
    return (str);
}

static int             case_char(t_options set, va_list arg)
{
    char c;
    char *str;
    int len;
    
    c = va_arg(arg, int); // 다양한 자료형에 대한 처리
    set.width--;
    str = ft_strdup("");
    str = check_width(str, set);
    if (set.minus == 1)
    {
        write(1, &c, 1);
        ft_putstr_fd(str, 1);
    }
    else
    {
        ft_putstr_fd(str, 1);
        write(1, &c, 1);
    }
    len = ft_strlen(str) + 1;
    str = NULL;
    free(str);
    return (len);
}

int                    main_process(t_options set, va_list arg)
{
    char *str;
    int ret;
    
    str = NULL;
    ret = 0;
    if (set.type == 'd' || set.type == 'i' || set.type == 'u' || \
        set.type == 'x' || set.type == 'X' || set.type == 'p')
        str = case_integer(set, arg);
    if (set.type == 's' ||  set.type == '%')
        str = case_word(set, arg);
    if (set.type == 'c')
        return (case_char(set, arg));
    str = check_precision(str, set);
    str = check_width(str, set);
    ret = ft_strlen(str);
    ft_putstr_fd(str, 1);

    str = NULL;
    free(str);
    return (ret);
}

// 여기서 malloc protection은 어떨때 해주어야 될까 // 메모리 leak 체크해보기 // strlcat 등으로 합쳤을때 malloc
