#ifndef WINDOW_IMAGE_H
# define WINDOW_IMAGE_H

# include "types.h"

t_data	create_img(void *mlx, t_files files);
void	add_line(t_data w_img, t_data wall, t_draw_line *dl_info);
void	add_sprites(t_data w_img, t_data sprite, t_draw_line *dl_info);

#endif
