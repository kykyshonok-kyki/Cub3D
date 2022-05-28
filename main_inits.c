#include "mlx.h"
#include <errno.h>
#include "types.h"
#include "window_image.h"

void	files_init(t_files *files, t_inits *inits)
{
	files->size_x = 0;
	files->size_y = 0;
	files->plane_dist = 0;
	inits->north.path = 0;
	inits->south.path = 0;
	inits->west.path = 0;
	inits->east.path = 0;
	inits->sprite.path = 0;
	files->north = &inits->north;
	files->south = &inits->south;
	files->west = &inits->west;
	files->east = &inits->east;
	files->sprite = &inits->sprite;
	files->floor = -1;
	files->ceiling = -1;
}

void	params_init(t_params *params, t_files *files, char *arg2)
{
	if (arg2)
	{
		if (!ft_strncmp(arg2, "--save", 7))
			params->screenshot = 1;
		else
			error("Only --save allowed as second argument");
	}
	else
		params->screenshot = 0;
	params->mlx = mlx_init();
	if (!params->mlx)
		error("Cannt init mlx");
	errno = 0;
	params->window = mlx_new_window(params->mlx, files->size_x,
			files->size_y, "Cub 3D");
	if (!params->window)
		error("Cannt init window");
	errno = 0;
	params->w_img = create_img(params->mlx, *files);
}
