#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!needle)
		return ((char *)haystack);
	if (needle[0] == 0)
		return ((char *)haystack);
	if (!haystack)
		return (NULL);
	while (haystack[i] != 0 && i < len)
	{
		while (needle[j] != 0 && haystack[i + j] == needle[j] && i + j < len)
			j++;
		if (needle[j] == 0)
			return ((char *)(haystack + i));
		else
			j = 0;
		i++;
	}
	return (NULL);
}
