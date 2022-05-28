#include "libft.h"

static int	ft_itoa_rank(int n)
{
	int	rank;

	rank = 1;
	while (n / 10 != 0)
	{
		rank++;
		n = n / 10;
	}
	return (rank);
}

char	*ft_itoa(int n)
{
	unsigned char	rank;
	char			*res;

	rank = ft_itoa_rank(n);
	if (n >= 0)
		rank--;
	res = malloc(rank + 2);
	if (!res)
		return (0);
	*(res + rank + 1) = 0;
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	while (n != 0)
	{
		if (n < 0)
			*(res + rank) = '0' - n % 10;
		else
			*(res + rank) = '0' + n % 10;
		n = n / 10;
		rank--;
	}
	return (res);
}
