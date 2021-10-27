#include "interpreter.h"

void malloc_error_check(void *item)
{
    if (item == NULL)
    {
        printf("%s\n", strerror(12));
        exit(1);
    }
}

void	*ft_free_ret(void *target, void *ret)
{
	if (target != NULL)
		free(target);
	return (ret);
}
/*
void 	ft_print_token(t_list *tokens, int case)
{
	t_list *temp_print;

	temp_print = tokens;
	while (temp_print)
	{
		printf("%d token check_value : %s, type : %d\n", case, ((t_token *)tokens->content)->value, ((t_token *)tokens->content)->type);
		temp_print = temp_print->next;
	}
}
*/
char	*ft_strappendc(char *str, char c)
{
	int		len;
	char	*result;

	len = ft_strlen(str);
	if (!ft_malloc((void **)&result, sizeof(char *) * (len + 2)))
	{
		free(str);
		return (0);
	}
	ft_memmove(result, str, sizeof(char) * len);
	result[len] = c;
	free(str);
	return (result);
}

int	ft_malloc(void **dst, size_t size)
{
	*dst = ft_calloc(size, 1);
	if (*dst == NULL)
		return (0);
	return (1);
}

