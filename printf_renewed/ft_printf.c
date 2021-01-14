#include "printf.h"

static t_options            init_option(void)
{
    t_options ret;

    ret.minus = 0;
    ret.zero = 0;
    ret.width = 0;
    ret.precision = -1;
    ret.type = 0;
    return (ret);
}

static int                 print_one_set(t_options *set, va_list arg)
{
    int temp_len;
    
    if (set->type == 'd' || set->type == 'i' || set->type == 'u' || \
        set->type == 'u' || set->type == 'x' || set->type == 'X')
        temp_len = type_num(set, arg);
    else if (set->type == 's')
        temp_len = type_str(set, arg);
    else if (set->type == 'c' || set->type == '%')
        temp_len = type_char(set, arg);
    else if (set->type == 'p')
        temp_len = type_ptr(set, arg);
    else
        temp_len = -1;
    
    return (temp_len);
}

int                ft_printf(char* format,...)
{
    char *traverse;
    t_options set;
    va_list arg;
    int sum_len;
    int temp_len;
 
    traverse = format;
    va_start(arg, format);
    sum_len = 0;
    while (*traverse)
    {
        while (*traverse != '%' && *traverse)
        {
            ft_putchar_fd(*traverse, 1);
            sum_len++;
            traverse++;
        }
        if (!*traverse)
            break ;
        traverse++;
        set = init_option();
        traverse = parcing_str(traverse, &set, arg);
  //      printf("\n%d, %d, %d, %d, %d\n", set.zero, set.minus, set.width, set.precision, set.type);
        temp_len = print_one_set(&set, arg);
        if (temp_len != -1)
            sum_len += temp_len;
        else
            return (0);
    }
    va_end(arg);
    return (sum_len);
}

        
        // 여기부터
        /*
        if (except_case(&set))
            return (0);
        if (set.type)
            sum_len += main_process(set, arg);
        
        if (set.type == 'd' || set.type == 'u' || \
            set.type == 'u' || set.type == 'x' || set.type == 'X')
            sum_len += type_num(set, arg);
        else if (set.type == 's')
            sum_len += type_str(set, arg);
        else if (set.type == 'c' || set.type == '%')
            sum_len += type_char(set, arg);
        else if (set.type == 'p')
            sum_len += type_ptr(set, arg);
         */
        // 여기를 type별로 
       //printf("\n%d, %d, %d, %d, %d\n", set.zero, set.minus, set.width, set.precision, set.type);

/*
static int          except_case(t_options *set)
{
    if (!(set->type == 'd' || set->type == 'i' || set->type == 'u' || \
        set->type == 'x' || set->type == 'X' || set->type == 's' || \
        set->type == 'c' || set->type == 'p' || set->type == '%'))
        return (1); // undeclared type일 경우
    // undeclared option 처리 l 이나 h 같은게 아닐 경우
    if (set->zero && set->minus && set->type != '%') // '%' 제외하고는 flag 0,1 같이 올 수 없다.
        return (1);
    if (set->precision < 0) // precision 이 음수면 -1이 되어야함
        set->precision = -1;
    if (set->zero)
    {
        if (!(set->type == 'd' || set->type == 'i' || set->type == 'u' || \
              set->type == 'x' || set->type == 'X' || set->type == 'p' || set->type == '%'))
            return (1); // num과 % 제외 0 flag는 error
        else if (set->precision != -1 && set->type != '%')
            set->zero = 0; // precision이 존재하는 num 또는 %에서 0 flag는 빈칸으로 적용 // %케이스 아님 오히려 precision 있어도 항상  제로패딩
    }
    if (set->zero && set->minus && set->type != '%') // '%' 제외하고는 flag 0,1 같이 올 수 없다.
        return (1);
    else if (set->zero && set->minus)
    {
        *set = init_option();
        set->type = '%';
    }
    return (0);
}
 */
