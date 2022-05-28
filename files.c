#include "libft.h"
#include "types.h"
#include "mlx.h"
#include <math.h>
#include "errno.h"

void	f_error(const char *err_str, t_list **lstmap, char *line,
	t_files *files)
{
	ft_lstclear(lstmap, free);
	*lstmap = 0;
	if (files->north->path)
		free(files->north->path);
	files->north->path = 0;
	if (files->south->path)
		free(files->south->path);
	files->south->path = 0;
	if (files->west->path)
		free(files->west->path);
	files->west->path = 0;
	if (files->east->path)
		free(files->east->path);
	files->east->path = 0;
	if (files->sprite->path)
		free(files->sprite->path);
	files->sprite->path = 0;
	if (line)
		free(line);
	line = 0;
	error(err_str);
}

static int	check_map(char *map, t_pos max, int x, int y)
{
	int	index;
	int	res;

	res = 0;
	index = y * (max.x + 1) + x;
	if (x == 0 || x == max.x || y == 0 || y == max.y)
		return (1);
	map[index] = 'c';
	if (map[index - 1] != '1' && map[index - 1] != 'c')
		res += check_map(map, max, x - 1, y);
	if (map[index + 1] != '1' && map[index + 1] != 'c')
		res += check_map(map, max, x + 1, y);
	if (map[index + (int)max.x + 1] != '1'
		&& map[index + (int)max.x + 1] != 'c')
		res += check_map(map, max, x, y + 1);
	if (map[index - (int)max.x - 1] != '1'
		&& map[index - (int)max.x - 1] != 'c')
		res += check_map(map, max, x, y - 1);
	return (res);
}

const char	*is_valid_map(t_player player, int width, int height)
{
	char	*map;
	t_pos	max;

	map = ft_strdup(player.walls);
	if (!map)
		return ("Cannt save map data");
	max.x = width;
	max.y = height;
	if (player.x == width || player.x == 0
		|| player.y == height || player.y == 0)
	{
		free(map);
		return ("File .cub error: Player is out of walls");
	}
	if (check_map(map, max, player.x, player.y))
	{
		free(map);
		return ("File .cub error: Player is out of walls");
	}
	free(map);
	return (0);
}

static void	check_max_size(t_files *files)
{
	int	max_x;
	int	max_y;

	mlx_get_screen_size(&max_x, &max_y);
	errno = 0;
	if (files->size_x > max_x)
		files->size_x = max_x;
	if (files->size_y > max_y)
		files->size_y = max_y;
}

const char	*resolution(char *line, t_map *map)
{
	t_pos	max;

	if (map->files->size_x != 0)
		return ("File .cub error: Duplicate resolution config line");
	map->files->size_x = ft_atoi(line);
	while (*line == ' ')
		line++;
	while (*line >= '0' && *line <= '9')
		line++;
	map->files->size_y = ft_atoi(line);
	while (*line == ' ')
		line++;
	while (*line >= '0' && *line <= '9')
		line++;
	while (*line == ' ')
		line++;
	if (*line || map->files->size_x == 0 || map->files->size_y == 0)
		return ("File .cub error: Resolution line is incorrect");
	check_max_size(map->files);
	if (map->files->size_x < 100 || map->files->size_y < 100)
		return ("File .cub error: Resolution x and y must be > 100 px");
	map->files->plane_dist = sqrt(pow((map->files->size_x) / tan(54.5
					* M_PI / 180), 2) - pow(map->files->size_x / 2.0, 2.0));
	return (0);
}
