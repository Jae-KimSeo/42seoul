

#include "libft.h"

static void	write_digit(int n, int fd, int div)
{
	char	c;

	c = n / div + 48;
	write(fd, &c, 1);
	if (div == 1)
		return ;
	n %= div;
	div /= 10;
	while (div != 1)
	{
		c = n % (div * 10) / div + 48;
		write(fd, &c, 1);
		div /= 10;
	}
	c = n % (div * 10) / div + 48;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	tmp;
	int	div;

	div = 1;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	tmp = n;
	while (tmp >= 10)
	{
		div *= 10;
		tmp /= 10;
	}
	write_digit(n, fd, div);
}
