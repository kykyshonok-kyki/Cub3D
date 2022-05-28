#include "types.h"
#include "files.h"
#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"
#include "parser_subfuncs.h"
#include "errno.h"
#include "parser_utils.h"

static const char	*save_line(int i, t_map *map, t_player *player, char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == '1' || line[j] == '0' || line[j] == '2')
			player->walls[i * map->width + j] = line[j];
		else if (line[j] == ' ')
			player->walls[i * map->width + j] = '0';
		else if (!(fill_player(player, i * map->width + j, map->width,
					line[j])))
		{
			free(player->walls);
			return ("File .cub error: Unallowed character on map");
		}
		j++;
	}
	while (j < map->width)
		player->walls[i * map->width + j++] = '0';
	return (0);
}

static const char	*map_to_mas(t_list **lstmap, t_map map, t_player *player)
{
	t_list		*temp;
	int			i;
	const char	*err_str;

	player->walls = malloc(map.height * map.width);
	if (!player->walls)
		return ("Cannt save map data");
	temp = *lstmap;
	i = 0;
	while (temp)
	{
		err_str = save_line(i, &map, player, (char *)temp->content);
		if (err_str)
			return (err_str);
		i++;
		temp = temp->next;
	}
	ft_lstclear(lstmap, free);
	*lstmap = 0;
	return (is_valid_map(*player, map.width - 1, map.height - 1));
}

static const char	*work_with_line(char *line, t_list **lstmap, t_map *map,
		t_player *player)
{
	const char	*err_str;

	err_str = 0;
	if (*lstmap == 0 && !(*line == ' ' || *line == '1'
			|| *line == '0' || *line == '2'))
	{
		if (*line)
			err_str = map_files(line, map);
		if (err_str)
			return (err_str);
		free(line);
		line = 0;
	}
	else
	{
		if (*lstmap == 0)
			if (!is_all_elems(*map))
				return ("File .cub error: There are not all elements");
		err_str = map_line(line, map, lstmap);
		if (err_str)
			return (err_str);
	}
	return (0);
}

static void	rf_work(int fd, t_list **lstmap, t_map *map, t_player *player)
{
	int			res;
	char		*line;
	const char	*err_str;

	res = get_next_line(fd, &line);
	while (res != -1 && (res || *line))
	{
		err_str = work_with_line(line, lstmap, map, player);
		if (err_str)
		{
			close(fd);
			f_error(err_str, lstmap, line, map->files);
		}
		res = get_next_line(fd, &line);
	}
	if (line)
	{
		free(line);
		line = 0;
	}
	close(fd);
	if (res == -1)
		f_error("Cannt read .cub file", lstmap, 0, map->files);
}

void	read_file(char *file, t_map *map, t_player *player)
{
	int			fd;
	int			res;
	char		*line;
	t_list		*lstmap;
	const char	*err_str;

	map->width = 0;
	map->height = 0;
	lstmap = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Cann't open .cub file");
	rf_work(fd, &lstmap, map, player);
	err_str = map_to_mas(&lstmap, *map, player);
	if (err_str)
		f_error(err_str, &lstmap, 0, map->files);
}
