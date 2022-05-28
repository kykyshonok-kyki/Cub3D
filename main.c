#include "types.h"
#include "window_image.h"
#include "control.h"
#include "raycast.h"
#include "parser.h"
#include "mlx.h"
#include <stdlib.h>
#include <errno.h>
#include "textures.h"
#include "main_inits.h"
#include "libft.h"
#include "stdio.h"

void	free_paths(t_files *files)
{
	if (files->north->path)
	{
		free(files->north->path);
		files->north->path = 0;
	}
	if (files->south->path)
	{
		free(files->south->path);
		files->south->path = 0;
	}
	if (files->west->path)
	{
		free(files->west->path);
		files->west->path = 0;
	}
	if (files->east->path)
	{
		free(files->east->path);
		files->east->path = 0;
	}
	if (files->sprite->path)
	{
		free(files->sprite->path);
		files->sprite->path = 0;
	}
}

void	error(const char *str)
{
	write(1, "Error\n", 6);
	if (errno)
		perror(str);
	else
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	exit(EXIT_FAILURE);
}

static char	check_format(char *path)
{
	char	is_format;
	size_t	len;

	len = ft_strlen(path);
	is_format = 0;
	if (len > 4)
	{
		len -= 4;
		if (!(path[len] == '.' && path[len + 1] == 'c' && path[len + 2] == 'u'
				&& path[len + 3] == 'b'))
			is_format = 1;
	}
	else
		is_format = 1;
	return (is_format);
}

static char	*take_arg2(int argv, char **argc, t_files files)
{
	if (argv < 2)
		error("No arguments");
	else if (argv > 3)
		error("Too many arguments");
	else if (check_format(argc[1]))
		error("Only .cub file available as config file");
	else if (argv == 3)
		return (argc[2]);
	return (0);
}

int	main(int argv, char **argc)
{
	t_params	params;
	t_files		files;
	t_inits		inits;
	char		*arg2;

	errno = 0;
	arg2 = 0;
	files_init(&files, &inits);
	arg2 = take_arg2(argv, argc, files);
	params.player.x = 0;
	params.player.y = 0;
	params.map.files = &files;
	read_file(argc[1], &params.map, &params.player);
	params_init(&params, &files, arg2);
	mlx_hook(params.window, 17, 0, cub_close, &params);
	mlx_key_hook(params.window, key_pressed, &params);
	def_textures(params.mlx, params.window, &files);
	raycast(&params);
	mlx_loop(params.mlx);
	return (0);
}
