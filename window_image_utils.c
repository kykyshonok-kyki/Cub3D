#include "types.h"

unsigned int	*get_addr(t_data img, int height, int width)
{
	unsigned int	*addr;

	addr = (unsigned int *)(img.addr + height * img.line_length
			+ width * (img.bits_per_pixel / 8));
	return (addr);
}
