#include "printf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>


int main()
{
    
    char *ptr;
    
    ptr = "abcd";
    ft_printf("%--99.174%%-152p%---41.22i" ,(void*)13623062879853167239lu,-83457563);
    ft_printf("%--9.p\n", (void *)123412lu);
    
    printf("%--99.174%%-152p%---41.22i" ,(void*)13623062879853167239lu,-83457563);
    printf("%--9.p\n",  (void *)123412lu);
    //printf("%s%s", "heell", "world");
    
 //   ft_printf("%5.c", 'a');
    /*
    ft_printf("%d\n", 0);
    ft_printf("%010d\n", 1235);
    printf("%d\n", 0);
    printf("%010d\n", 1235);
   */
    /*
    int        a = -4;
    int        b = 0;
    char    c = 'a';
    int        d = 2147483647;
    int        e = -2147483648;
    int        f = 42;
    int        g = 25;
    int        h = 4200;
    int        i = 8;
    int        j = -12;
    int        k = 123456789;
    int        l = 0;
    int        m = -12345678;
    char    *n = "abcdefghijklmnop";
    char    *o = "-a";
    char    *p = "-12";
    char    *q = "0";
    char    *r = "%%";
    char    *s = "-2147483648";
    char    *t = "0x12345678";
    char    *u = "-0";
    printf(" --- Return : %d\n", printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c, e, d)); //T5
    printf(" --- Return : %d\n", printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c, e, d)); //T6
    
    ft_printf(" --- Return : %d\n", printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c, e, d)); //T5
    printf("\n");
    ft_printf(" --- Return : %d\n", printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c, e, d)); //T6
    
    printf(" --- Return : %d\n", ft_printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d)); //T7
    printf(" --- Return : %d\n", ft_printf("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c, e, d)); //T8

    ft_printf(" --- Return : %d\n", ft_printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d)); //T7
    ft_printf(" --- Return : %d\n", ft_printf("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c, e, d)); //T8
    */
    return 0;
  
}
 /*
int    specifier(const char *fmt, va_list ap, int *pos)
{
    t_options    opt;
    int          cnt;

    opt = init_option();
    *pos = check_option(fmt, (*pos) + 1, &opt, ap);
    cnt = print_by_type(opt, ap);
    return (cnt);
}
*/
     
/*
t_options               init_option(void)
 {
     t_options ret;

     ret.minus = 0;
     ret.zero = 0;
     ret.width = 0;
     ret.precision = -1;
     ret.type = 0;
     return (ret);
 }

static int              except_case(t_options *set)
{
    if (set->precision < 0)
        set->precision = -1;
    if (set->zero == 1 && !(set->type == 'd' || set->type == 'i' || set->type == 'u' || \
    set->type == 'x' || set->type == 'X'))
        return (1);
    if (set->zero && set->minus && set->type != '%')
        return (1);
    return (0);
}
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
    {
        str = ft_itoa_base(va_arg(arg, long long), 16);
        char *padd;
        padd = ft_strdup("0x");
        ft_strlcat(padd, str, ft_strlen(str) + 3);
        return (padd);
    }
    return (str);
}

static char             *case_word(t_options set, va_list arg)
{
    char *str;
    char c;
    
    str= NULL;
    c = '\0';
    if (set.type == 's')
        str = ft_strdup(va_arg(arg, char *));
    if (set.type == 'c')
    {
        c = va_arg(arg, int); // 다양한 자료형에 대한 처리
        str = ft_strdup(&c);
    }
    if (set.type == '%')
    {
        c = '%';
        str = ft_strdup(&c);
    }
    return (str);
}
 
void                main_process(t_options set, va_list arg)
{
    char *str;
    
    str = NULL;
    if (set.type == 'd' || set.type == 'i' || set.type == 'u' || \
        set.type == 'x' || set.type == 'X' || set.type == 'p')
    {
        if (set.precision != -1 && set.zero)
            set.zero = 0;
        str = case_integer(set, arg);
    }
    if (set.type == 's' || set.type == 'c' || set.type == '%')
        str = case_word(set, arg);
    if (str)
    {
    str = check_precision(str, set);
    str = check_width(str, set);
    ft_putstr_fd(str, 1);
    str = NULL;
    }
    free(str);
}
void ft_printf(char* format,...)
{
    char *traverse;
    t_options set;
    va_list arg;
 
    va_start(arg, format);
    traverse = format;
    while (*traverse)
    {
        while (*traverse != '%' && *traverse)
        {
            ft_putchar_fd(*traverse, 1);
            traverse++;
        }
        if (!*traverse)
            break ;
        traverse++;
        set = init_option();
        traverse = parcing_str(traverse, &set, arg);
        if (except_case(&set))
            return ;
        if (set.type == 'd' || set.type == 'i' || set.type == 'u' || set.type == 'x' || set.type == 'X' || set.type == 's' || set.type == 'c' || set.type == 'p' || set.type == '%')
            main_process(set, arg);
       //printf("\n%d, %d, %d, %d, %d\n", set.zero, set.minus, set.width, set.precision, set.type);
    }
    va_end(arg);
    printf("\n");
}
 */

