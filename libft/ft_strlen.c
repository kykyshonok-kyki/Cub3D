#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (s == 0)
		return (0);
	count = 0;
	while (s[count] != 0)
		count++;
	return (count);
}
