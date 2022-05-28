#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start] != 0)
		start++;
	if (s1[start] == 0)
		return (ft_calloc(1, 1));
	end = start;
	while (s1[end] != 0)
		end++;
	end--;
	while (ft_strchr(set, s1[end]))
		end--;
	res = ft_substr(s1, start, end - start + 1);
	if (res)
		return (res);
	return (NULL);
}
