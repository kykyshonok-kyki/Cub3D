#ifndef STEPS_H
# define STEPS_H

# include "types.h"
# include "steps.h"

typedef struct s_steps
{
	double		max_len_h;
	double		max_len_v;
	double		vert;
	double		hor;
	double		len_v;
	double		len_h;
	double		len;
	t_pos		cur;
	t_pos		next_v;
	t_pos		next_h;
}				t_steps;

void	def_struct(t_steps *steps, t_player player, double angle);

#endif
