#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		res = malloc(1);
		if (res)
			*res = 0;
		else
			return (NULL);
	}
	else
	{
		res = malloc(len + 1);
		if (!res)
			return (NULL);
		while (i < len && s[i] != 0)
		{
			res[i] = s[start + i];
			i++;
		}
		res[i] = 0;
	}
	return (res);
}
