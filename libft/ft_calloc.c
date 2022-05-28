#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;

	i = 0;
	res = malloc(count * size);
	if (res)
	{
		while (i < count * size)
		{
			*(char *)(res + i) = 0;
			i++;
		}
		return (res);
	}
	return (NULL);
}
