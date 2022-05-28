#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	if (s1)
	{
		while (*s1 != 0)
		{
			res[i++] = *s1;
			s1++;
		}
	}
	if (s2)
	{
		while (*s2 != 0)
		{
			res[i++] = *s2;
			s2++;
		}
	}
	res[i] = 0;
	return (res);
}
