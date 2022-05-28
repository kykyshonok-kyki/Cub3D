#ifndef RAYCAST_UTILS_H
# define RAYCAST_UTILS_H

# include "types.h"

char	ifhit(t_player player, t_pos point, t_map map, double angle);
double	take_wall_line(char side, t_pos hit);
char	comp_angles(double angle, double cang);

#endif
