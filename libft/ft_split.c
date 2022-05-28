#include "libft.h"

static char	ft_split_free(char **res, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}

static char	ft_split_el(char **res, char *s, char c, size_t snum)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	while (s[index] != c && s[index] != 0)
		index++;
	res[snum] = malloc((index + 1) * sizeof(char));
	if (!res[snum])
		return (ft_split_free(res, snum));
	while (i < index)
		res[snum][i++] = *s++;
	res[snum][i] = 0;
	if (c)
		while (*s == c)
			s++;
	if (*s != 0)
	{
		if (!(ft_split_el(res, s, c, snum + 1)))
			return (0);
	}
	else
		res[snum + 1] = 0;
	return (1);
}

static char	**ft_split_zero(void)
{
	char	**res;

	res = malloc(sizeof(char *));
	if (!res)
		return (0);
	res[0] = 0;
	return (res);
}

static size_t	ft_strcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	if (c)
		while (s[i] == c)
			i++;
	if (s[i] != 0)
		count++;
	while (s[i] != 0)
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	count;
	size_t	i;

	if (s == NULL)
		return (ft_split_zero());
	count = ft_strcount(s, c);
	i = 0;
	if (count == 1)
		return (ft_split_zero());
	if (c)
		while (*s == c)
			s++;
	res = malloc(count * sizeof(char *));
	if (!res)
		return (0);
	if (!(ft_split_el(res, (char *)s, c, 0)))
		return (0);
	return (res);
}
