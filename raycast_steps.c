#include "raycast_steps.h"
#include <math.h>
#include "steps.h"
#include "types.h"

static void	vertical_sstep(t_steps *steps, char *passed, double angle)
{
	if (*passed == 1)
		*passed = 3;
	else
		*passed = 2;
	steps->cur.x = steps->next_v.x;
	steps->cur.y = steps->next_v.y;
	if ((angle > M_PI_2 * 3 && angle < M_PI_2 * 5)
		|| (angle > -M_PI_2 && angle < M_PI_2))
		steps->next_v.x += 1;
	else
		steps->next_v.x += -1;
	steps->next_v.y += steps->vert;
	steps->len_h = steps->len_h - steps->len_v;
	steps->len += steps->len_v;
	steps->len_v = steps->max_len_v;
}

void	start_step(t_steps *steps, char *passed, double angle)
{
	if (steps->len_v < steps->len_h)
		vertical_sstep(steps, passed, angle);
	else
	{
		if (*passed == 2)
			*passed = 3;
		else
			*passed = 1;
		steps->cur.x = steps->next_h.x;
		steps->cur.y = steps->next_h.y;
		steps->next_h.x += steps->hor;
		if ((angle > M_PI && angle < M_PI * 2) || (angle > -M_PI && angle < 0))
			steps->next_h.y += 1;
		else
			steps->next_h.y += -1;
		steps->len_v = steps->len_v - steps->len_h;
		steps->len += steps->len_h;
		steps->len_h = steps->max_len_h;
	}
}

static void	vertical_step(t_steps *steps, double angle)
{
	steps->cur.x = steps->next_v.x;
	steps->cur.y = steps->next_v.y;
	if ((angle > M_PI_2 * 3 && angle < M_PI_2 * 5)
		|| (angle > -M_PI_2 && angle < M_PI_2))
		steps->next_v.x += 1;
	else
		steps->next_v.x += -1;
	steps->next_v.y += steps->vert;
	steps->len_h = steps->len_h - steps->len_v;
	steps->len += steps->len_v;
	steps->len_v = steps->max_len_v;
}

void	step(t_steps *steps, double angle)
{
	if (steps->len_v < steps->len_h)
		vertical_step(steps, angle);
	else
	{
		steps->cur.x = steps->next_h.x;
		steps->cur.y = steps->next_h.y;
		steps->next_h.x += steps->hor;
		if ((angle > M_PI && angle < M_PI * 2) || (angle > -M_PI && angle < 0))
			steps->next_h.y += 1;
		else
			steps->next_h.y += -1;
		steps->len_v = steps->len_v - steps->len_h;
		steps->len += steps->len_h;
		steps->len_h = steps->max_len_h;
	}
}
