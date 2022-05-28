#include "types.h"
#include <math.h>

double	take_wall_line(char side, t_pos hit)
{
	if (side == 'N')
		return (1 - (hit.x - floor(hit.x)));
	else if (side == 'S')
		return (hit.x - floor(hit.x));
	else if (side == 'W')
		return (hit.y - floor(hit.y));
	else
		return (1 - (hit.y - floor(hit.y)));
}

char	comp_angles(double angle, double cang)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (cang < 0)
		cang += 2 * M_PI;
	if (angle > M_PI_2 * 3 && cang < M_PI_2)
		angle -= 2 * M_PI;
	if (angle < M_PI_2 && cang > M_PI_2 * 3)
		angle += 2 * M_PI;
	if (angle > cang)
		return (1);
	return (0);
}

static char	direction(char is_x, double angle)
{
	if (is_x && angle != M_PI_2 && angle != M_PI_2 * 3)
	{
		if (angle < M_PI_2 || angle > 3 * M_PI_2)
			return ('W');
		else
			return ('E');
	}
	else if ((angle >= 0 && angle <= M_PI) || angle >= 2 * M_PI)
		return ('S');
	else
		return ('N');
}

char	ifhit(t_player player, t_pos point, t_map map, double angle)
{
	char	*walls;
	char	map_ch;
	char	is_x;
	char	dir;

	walls = player.walls;
	if (point.x - (int)point.x)
		is_x = 0;
	else
		is_x = 1;
	dir = direction(is_x, angle);
	if (dir == 'W')
		map_ch = walls[(int)floor(point.y) * map.width + (int)point.x];
	else if (dir == 'E')
		map_ch = walls[(int)floor(point.y) * map.width + (int)(point.x - 1)];
	else if (dir == 'S')
		map_ch = walls[map.width * (int)(point.y - 1) + (int)floor(point.x)];
	else
		map_ch = walls[(int)point.y * map.width + (int)floor(point.x)];
	if (map_ch == '1')
		return (dir);
	else if (map_ch == '2')
		return (2);
	else
		return (0);
}
