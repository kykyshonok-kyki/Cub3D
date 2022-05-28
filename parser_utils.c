#include "files_color.h"
#include "files.h"
#include "types.h"
#include <math.h>
#include <fcntl.h>

char	fill_player(t_player *player, int index, int width, char ch)
{
	player->walls[index] = '0';
	if (ch == 'E')
		player->angle = 0;
	else if (ch == 'N')
		player->angle = M_PI_2;
	else if (ch == 'W')
		player->angle = M_PI;
	else if (ch == 'S')
		player->angle = 3 * M_PI_2;
	else
		return (0);
	if (player->x != 0)
		error("File .cub error: Only 1 player allowed on the map");
	player->x = index % width + 0.5;
	player->y = index / width + 0.5;
	return (1);
}

const char	*map_line(char *line, t_map *map, t_list **lstmap)
{
	int		cur_len;
	t_list	*new;

	cur_len = ft_strlen(line);
	if (cur_len > map->width)
		map->width = cur_len;
	new = ft_lstnew(line);
	if (!new)
		return ("Cannt save line of map");
	map->height++;
	ft_lstadd_back(lstmap, new);
	return (0);
}

static char	open_check(char *line)
{
	int	fd;

	fd = open(line, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

static const char	*texture(char *line, t_map *map, char ch)
{
	t_data	*texture;

	while (*line == ' ')
		line++;
	if (!if_correct_format(line))
		return ("File .cub error: Texture file format is incorrect");
	if (open_check(line))
		return ("Cannt open texture file");
	if (ch == 'N' && !map->files->north->path)
		texture = map->files->north;
	else if (ch == 'S' && !map->files->south->path)
		texture = map->files->south;
	else if (ch == 'W' && !map->files->west->path)
		texture = map->files->west;
	else if (ch == 'E' && !map->files->east->path)
		texture = map->files->east;
	else if (ch == 's' && !map->files->sprite->path)
		texture = map->files->sprite;
	else
		return ("File .cub error: Duplicate texture config line");
	texture->path = ft_strdup(line);
	if (!texture->path)
		return ("Cannt save texture path");
	return (0);
}

const char	*map_files(char *line, t_map *map)
{
	int	fd;

	if (*line == 'R' && *(line + 1) == ' ')
		return (resolution((line + 2), map));
	else if (*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
		return (texture((line + 2), map, 'N'));
	else if (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
		return (texture((line + 2), map, 'S'));
	else if (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
		return (texture((line + 2), map, 'W'));
	else if (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
		return (texture((line + 2), map, 'E'));
	else if (*line == 'S' && *(line + 1) == ' ')
		return (texture((line + 2), map, 's'));
	else if (*line == 'F' && *(line + 1) == ' ')
		return (color(line, map, 'f'));
	else if (*line == 'C' && *(line + 1) == ' ')
		return (color(line, map, 'c'));
	else
		return ("File .cub error: Unknown type identifier");
	return (0);
}
