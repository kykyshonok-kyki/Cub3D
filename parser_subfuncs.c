#include "types.h"

char	is_all_elems(t_map map)
{
	if (!map.files->size_x || !map.files->south || !map.files->north
		|| !map.files->west || !map.files->east || !map.files->sprite
		|| !map.files->floor || !map.files->ceiling)
		return (0);
	return (1);
}
