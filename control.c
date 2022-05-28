#include "types.h"
#include "raycast.h"
#include "mlx.h"
#include "math.h"
#include "stdlib.h"

int	cub_close(t_params *param)
{
	mlx_destroy_image(param->mlx, param->map.files->north->img);
	mlx_destroy_image(param->mlx, param->map.files->south->img);
	mlx_destroy_image(param->mlx, param->map.files->east->img);
	mlx_destroy_image(param->mlx, param->map.files->west->img);
	mlx_destroy_image(param->mlx, param->map.files->sprite->img);
	mlx_destroy_image(param->mlx, param->w_img.img);
	free(param->map.files->north->path);
	free(param->map.files->south->path);
	free(param->map.files->west->path);
	free(param->map.files->east->path);
	free(param->map.files->sprite->path);
	mlx_destroy_window(param->mlx, param->window);
	free(param->mlx);
	exit(EXIT_SUCCESS);
}

static void	move(int key, t_player *player)
{
	double	move_angle;

	if (key == 13)
		move_angle = M_PI_2;
	else if (key == 0)
		move_angle = M_PI;
	else if (key == 1)
		move_angle = -M_PI_2;
	else
		move_angle = 0;
	player->y += 0.5 * cos(player->angle + move_angle);
	player->x += 0.5 * sin(player->angle + move_angle);
}

int	key_pressed(int key, t_params *param)
{
	if (key == 13 || key == 0 || key == 1 || key == 2)
		move(key, &param->player);
	else if (key == 124)
		param->player.angle -= 0.1;
	else if (key == 123)
		param->player.angle += 0.1;
	if (param->player.angle < 0)
		param->player.angle += M_PI * 2;
	else if (param->player.angle > 2 * M_PI)
		param->player.angle -= M_PI * 2;
	if (key == 13 || key == 0 || key == 1 || key == 2 || key == 124
		|| key == 123)
		raycast(param);
	else if (key == 53)
		cub_close(param);
	return (0);
}
