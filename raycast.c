#include "types.h"
#include "window_image.h"
#include "raycast_utils.h"
#include <math.h>
#include "mlx.h"
#include "screenshot.h"
#include "raycast_steps.h"
#include "sprite.h"
#include "steps.h"

static void	add_line_dir(t_data w_img, t_files *files, t_draw_line *dl_info)
{
	if (dl_info->hit == 'N')
		add_line(w_img, *files->north, dl_info);
	else if (dl_info->hit == 'S')
		add_line(w_img, *files->south, dl_info);
	else if (dl_info->hit == 'E')
		add_line(w_img, *files->east, dl_info);
	else
		add_line(w_img, *files->west, dl_info);
}

static void	define(t_draw_line *dl_info, t_files *files, double *cur_ang)
{
	dl_info->line = 0;
	dl_info->sprite_dist = 0;
	dl_info->sprite_line = 0;
	dl_info->hit = 0;
	dl_info->ceiling = files->ceiling;
	dl_info->floor = files->floor;
	*cur_ang = atan(((int)(files->size_x / 2) - dl_info->line)
			/ files->plane_dist);
}

static void	find_hit(t_params *params, t_draw_line *dl_info,
		t_steps *steps, double cur_ang)
{
	char	passed;

	passed = 0;
	def_struct(steps, params->player, params->player.angle + cur_ang);
	while (!dl_info->hit && passed < 3)
	{
		start_step(steps, &passed, params->player.angle + cur_ang);
		dl_info->hit = ifhit(params->player, steps->cur, params->map,
				params->player.angle + cur_ang);
		if (dl_info->hit == 2)
			add_sprite_info(dl_info, params->player.angle + cur_ang,
				params, steps->cur);
	}
	while (!dl_info->hit)
	{
		step(steps, params->player.angle + cur_ang);
		dl_info->hit = ifhit(params->player, steps->cur, params->map,
				params->player.angle + cur_ang);
		if (dl_info->hit == 2)
			add_sprite_info(dl_info, params->player.angle + cur_ang,
				params, steps->cur);
	}
}

void	raycast(t_params *params)
{
	double		cur_ang;
	t_steps		steps;
	t_draw_line	dl_info;

	define(&dl_info, params->map.files, &cur_ang);
	while (dl_info.line < params->map.files->size_x)
	{
		find_hit(params, &dl_info, &steps, cur_ang);
		dl_info.wall_line = take_wall_line(dl_info.hit, steps.cur);
		dl_info.field = (params->w_img.height - (int)floor(params->w_img.height
					/ (1.25 * cos(cur_ang) * steps.len))) / 2;
		add_line_dir(params->w_img, params->map.files, &dl_info);
		add_sprites(params->w_img, *params->map.files->sprite, &dl_info);
		dl_info.hit = 0;
		dl_info.line++;
		cur_ang = atan(((int)(params->map.files->size_x / 2) - dl_info.line)
				/ params->map.files->plane_dist);
	}
	if (!params->screenshot)
		mlx_put_image_to_window(params->mlx, params->window,
			params->w_img.img, 0, 0);
	else
		make_screen(params);
}
