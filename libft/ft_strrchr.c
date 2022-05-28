#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;

	res = 0;
	while (*s != 0)
	{
		if (*s == c)
			res = (char *)s;
		s++;
	}
	if (res)
		return ((char *)res);
	else if (c == 0)
		return ((char *)s);
	else
		return (NULL);
}
