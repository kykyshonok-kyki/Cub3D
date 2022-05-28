#include "libft.h"

void	ft_putstr_fd(char *s, int fd, int len)
{
	if (len == -1)
		write(fd, s, ft_strlen(s));
	else
		write(fd, s, len);
}
