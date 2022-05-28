#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = dstlen;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	while (i < (dstsize - 1) && (i - dstlen) < srclen)
	{
		dst[i] = src[i - dstlen];
		i++;
	}
	if (dstsize)
		dst[i] = 0;
	return (dstlen + srclen);
}
