#include "libft.h"

int	ft_numlen(long int num, int not)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	if (num < 0)
		i++;
	while (num)
	{
		num = num / not;
		i++;
	}
	return (i);
}
