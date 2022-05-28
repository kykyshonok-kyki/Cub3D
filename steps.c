#include "types.h"
#include "steps.h"
#include <math.h>
#include "raycast_utils.h"

static void	standart_def(t_steps *steps, t_player player, double angle)
{
	if ((angle > M_PI_2 * 3 && angle < M_PI_2 * 5)
		|| (angle > -M_PI_2 && angle < M_PI_2))
		steps->vert = -tan(angle);
	else
		steps->vert = tan(angle);
	if ((angle > M_PI && angle < M_PI * 2) || (angle > -M_PI && angle < 0))
		steps->hor = -1 / tan(angle);
	else
		steps->hor = 1 / tan(angle);
	steps->next_v.y = player.y - ((steps->next_v.x - player.x)
			* tan(angle));
	steps->next_h.x = player.x - ((steps->next_h.y - player.y)
			/ tan(angle));
	steps->max_len_v = 1 / fabs(cos(angle));
	steps->max_len_h = 1 / fabs(sin(angle));
	if (steps->next_v.x - player.x > 0)
		steps->len_v = steps->max_len_v * (steps->next_v.x - player.x);
	else
		steps->len_v = steps->max_len_v * (player.x - steps->next_v.x);
	if (steps->next_h.y - player.y > 0)
		steps->len_h = steps->max_len_h * (steps->next_h.y - player.y);
	else
		steps->len_h = steps->max_len_h * (player.y - steps->next_h.y);
}

static void	hor_def(t_steps *steps, t_player player, double angle)
{
	steps->vert = 0;
	steps->hor = 999999999;
	steps->next_v.y = player.y;
	steps->next_h.x = 999999999;
	steps->max_len_v = 1 / fabs(cos(angle));
	steps->max_len_h = 999999999;
	if (steps->next_v.x - player.x > 0)
		steps->len_v = steps->max_len_v * (steps->next_v.x - player.x);
	else
		steps->len_v = steps->max_len_v * (player.x - steps->next_v.x);
	steps->len_h = 999999999;
}

static void	vert_def(t_steps *steps, t_player player, double angle)
{
	steps->vert = 999999999;
	steps->hor = 0;
	steps->next_v.y = 999999999;
	steps->next_h.x = player.x;
	steps->max_len_v = 999999999;
	steps->max_len_h = 1 / fabs(sin(angle));
	steps->len_v = 999999999;
	if (steps->next_h.y - player.y > 0)
		steps->len_h = steps->max_len_h * (steps->next_h.y - player.y);
	else
		steps->len_h = steps->max_len_h * (player.y - steps->next_h.y);
}

void	def_struct(t_steps *steps, t_player player, double angle)
{
	steps->len = 0;
	if ((angle > M_PI_2 * 3 && angle < M_PI_2 * 5)
		|| (angle > -M_PI_2 && angle < M_PI_2))
		steps->next_v.x = floor(player.x + 1);
	else
		steps->next_v.x = floor(player.x);
	if ((angle > M_PI && angle < M_PI * 2) || (angle > -M_PI && angle < 0))
		steps->next_h.y = floor(player.y + 1);
	else
		steps->next_h.y = floor(player.y);
	if (angle == M_PI_2 && angle == M_PI_2 * 3)
		vert_def(steps, player, angle);
	else if (angle == 0 || angle == M_PI || angle == M_PI * 2)
		hor_def(steps, player, angle);
	else
		standart_def(steps, player, angle);
}
