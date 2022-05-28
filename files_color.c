#include "libft.h"
#include <stdlib.h>
#include "types.h"

char	if_correct_format(char *path)
{
	int	dot_pos;
	int	index;

	index = 0;
	dot_pos = -1;
	while (path[index])
	{
		if (path[index] == '.')
			dot_pos = index;
		index++;
	}
	if (dot_pos != -1 && (index - dot_pos) != 4)
		return (0);
	if (path[dot_pos + 1] == 'x' && path[dot_pos + 2] == 'p'
		&& path[dot_pos + 3] == 'm')
		return (1);
	return (0);
}

static const char	*free_splited_line(char **splited_line, const char *ret_str)
{
	char	**tmp;

	tmp = splited_line;
	while (*splited_line)
	{
		free(*splited_line);
		splited_line++;
	}
	free(tmp);
	return (ret_str);
}

static char	basic_format_check(char *line)
{
	int	count;
	int	is_num;

	is_num = 0;
	count = 0;
	while (*line)
	{
		if (*line == ',')
		{
			count++;
			if (!is_num)
				return (1);
			is_num = 0;
		}
		else if (*line >= '0' && *line <= '9')
			is_num++;
		else if (*line != ' ')
			return (1);
		line++;
	}
	if (is_num && count == 2)
		return (0);
	return (1);
}

const char	*color(char *line, t_map *map, char ch)
{
	char	**rgb;
	int		color[3];
	int		i;

	if (basic_format_check(line + 1))
		return ("File .cub error: Color format error");
	rgb = ft_split(line + 1, ',');
	i = 0;
	if (!rgb)
		return ("Cannt save color data");
	while (rgb[i] && i < 3)
	{
		color[i] = ft_atoi(rgb[i]);
		if (color[i] < 0 || color[i] > 255)
			return (free_splited_line(rgb,
					"File .cub error: Color must be in range 0-255"));
		i++;
	}
	if (ch == 'f' && map->files->floor == -1)
		map->files->floor = (color[0] << 16) + (color[1] << 8) + color[2];
	else if (ch == 'c' && map->files->ceiling == -1)
		map->files->ceiling = (color[0] << 16) + (color[1] << 8) + color[2];
	else
		return ("File .cub error: Duplicate color config line");
	return (free_splited_line(rgb, 0));
}
