#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

# include "types.h"

const char	*map_line(char *line, t_map *map, t_list **lstmap);
char		fill_player(t_player *player, int index, int width, char ch);
const char	*map_files(char *line, t_map *map);

#endif
