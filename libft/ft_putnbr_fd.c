#include "libft.h"

static void	putnbr_rec(int n, int fd)
{
	if (n < 10)
		ft_putchar_fd('0' + n, fd);
	else
	{
		putnbr_rec(n / 10, fd);
		ft_putchar_fd('0' + (n % 10), fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 10 && n >= 0)
		ft_putchar_fd('0' + n, fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			if (n == -2147483648)
			{
				ft_putstr_fd("2147483648", fd, -1);
				return ;
			}
			else
				n = n * -1;
		}
		putnbr_rec(n, fd);
	}
}
