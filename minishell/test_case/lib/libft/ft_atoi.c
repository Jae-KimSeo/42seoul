
#include "libft.h"

long	long	ft_atoi(const char *str)
{
	long long	sum;
	int			sign;
	int			count;

	sum = 0;
	count = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' \
			|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = (-1) * sign;
	while (*str >= 48 && *str <= 57)
	{
		sum = sum * 10 + *str++ - 48;
		count++;
	}
	sum *= sign;
	if (sign == 1 && count > 20)
		return (-1);
	if (sign == -1 && count > 20)
		return (0);
	return (sum);
}
