#include "libft.h"

void	ft_puthx_fd(size_t nbr, int fd, char isup)
{
	char	put;

	if (!(nbr / 16))
	{
		put = ft_itohx((int)nbr, isup);
		write(fd, &put, 1);
	}
	else
	{
		ft_puthx_fd(nbr / 16, fd, isup);
		put = ft_itohx((int)(nbr % 16), isup);
		write(fd, &put, 1);
	}
}
