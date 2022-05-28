#ifndef FILES_H
# define FILES_H

# include "types.h"
# include "libft.h"

void		f_error(const char *err_str, t_list **lstmap, char *line,
				t_files *files);
const char	*resolution(char *line, t_map *map);
const char	*is_valid_map(t_player player, int width, int height);

#endif
