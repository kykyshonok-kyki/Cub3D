#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;
	size_t	dstlen;

	i = 0;
	dstlen = 0;
	len = ft_strlen(src);
	if (!src || !dst)
		return (len);
	if (dstsize)
		dstlen = dstsize - 1;
	while ((src[i] != 0) && (i < dstlen))
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i] = 0;
	return (len);
}
