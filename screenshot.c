#include "types.h"
#include "control.h"
#include "fcntl.h"
#include "libft.h"
#include <errno.h>

static void	bmp_put_nbr(int fd, unsigned int nbr, int len)
{
	write(fd, &nbr, len);
	if (errno)
		error("Cannt create .bmp file");
}

static void	put_header(int fd, t_data *w_img)
{
	write(fd, "BM", 2);
	bmp_put_nbr(fd, w_img->height * w_img->width * 4 + 58, 4);
	write(fd, "\0\0\0\0", 4);
	bmp_put_nbr(fd, 58, 4);
	bmp_put_nbr(fd, 40, 4);
	bmp_put_nbr(fd, w_img->width, 4);
	bmp_put_nbr(fd, w_img->height, 4);
	bmp_put_nbr(fd, 1, 2);
	bmp_put_nbr(fd, w_img->bits_per_pixel, 2);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 28);
	if (errno)
		error("Cannt create .bmp file");
}

void	make_screen(t_params *params)
{
	int		fd;
	int		i;
	int		j;
	char	*s_line;

	fd = open("screen.bmp", O_RDWR | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE);
	if (fd == -1)
		error("Cannt create .bmp file");
	put_header(fd, &params->w_img);
	i = params->w_img.height - 1;
	while (i >= 0)
	{
		s_line = params->w_img.addr + i * params->w_img.width * 4;
		write(fd, s_line, params->w_img.width * 4);
		i--;
	}
	close(fd);
	cub_close(params);
}
