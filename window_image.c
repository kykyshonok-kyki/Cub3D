#include "types.h"
#include "libft.h"
#include "mlx.h"
#include <math.h>
#include "window_image_utils.h"

struct		s_linfo
{
	double	line;
	double	dist;
};

t_data	create_img(void *mlx, t_files files)
{
	t_data		w_img;

	w_img.img = mlx_new_image(mlx, files.size_x, files.size_y);
	if (!w_img.img)
		error("Cannt create an image");
	w_img.addr = mlx_get_data_addr(w_img.img, &w_img.bits_per_pixel,
			&w_img.line_length, &w_img.endian);
	w_img.width = files.size_x;
	w_img.height = files.size_y;
	return (w_img);
}

static void	take_sprite_line(t_data w_img, t_data sprite,
	struct s_linfo linfo, int img_line)
{
	int				i;
	int				height;
	int				start;
	int				s_height;
	unsigned int	*color;

	height = (int)floor(w_img.height / linfo.dist);
	start = (w_img.height - height) / 2;
	s_height = w_img.height - start * 2;
	if (start < 0)
		i = 0;
	else
		i = start;
	while (i < w_img.height && i - start < height)
	{
		color = get_addr(sprite, (int)((i - start) * ((double)sprite.height
						/ (double)s_height)), (int)(linfo.line * sprite.width));
		if (*color / 0x01000000 == 0)
			*(unsigned int *)(w_img.addr + i * w_img.line_length + img_line
					* (w_img.bits_per_pixel / 8)) = *color;
		i++;
	}
}

void	add_sprites(t_data w_img, t_data sprite, t_draw_line *dl_info)
{
	struct s_linfo	linfo;
	t_list			*dist;
	t_list			*line;

	dist = dl_info->sprite_dist;
	line = dl_info->sprite_line;
	while (dist)
	{
		linfo.dist = *(double *)dist->content;
		linfo.line = *(double *)line->content;
		take_sprite_line(w_img, sprite, linfo, dl_info->line);
		dist = dist->next;
		line = line->next;
	}
	ft_lstclear(&(dl_info->sprite_dist), free);
	ft_lstclear(&(dl_info->sprite_line), free);
}

void	add_line(t_data w_img, t_data wall, t_draw_line *dl_info)
{
	int				i;
	int				w_height;
	unsigned int	*addr;
	unsigned int	*addr2;

	w_height = w_img.height - dl_info->field * 2;
	i = 0;
	while (i < dl_info->field && dl_info->field >= 0)
	{
		addr = get_addr(w_img, i, dl_info->line);
		*addr = dl_info->ceiling;
		i++;
	}
	while ((dl_info->field >= 0 && i < w_height + dl_info->field)
		|| (dl_info->field < 0 && i < w_img.height))
	{
		addr = get_addr(w_img, i, dl_info->line);
		addr2 = get_addr(wall, (i - dl_info->field) * ((double)wall.height
					/ (double)w_height), dl_info->wall_line * wall.width);
		*addr = *addr2;
		i++;
	}
	while (i < w_img.height)
		*(unsigned int *)(w_img.addr + (i++) * w_img.line_length
				+ dl_info->line * (w_img.bits_per_pixel / 8)) = dl_info->floor;
}
