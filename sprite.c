#include <math.h>
#include "types.h"
#include "raycast_utils.h"
#include "libft.h"
#include "window_image.h"

static t_pos	find_cpos(double angle, t_pos hit)
{
	if (!(hit.x - (int)hit.x))
	{
		if (angle < M_PI_2 || angle > 3 * M_PI_2)
		{
			hit.x += 0.5;
			hit.y = floor(hit.y) + 0.5;
		}
		else
		{
			hit.x -= 0.5;
			hit.y = floor(hit.y) + 0.5;
		}
	}
	else if ((angle >= 0 && angle <= M_PI) || angle >= 2 * M_PI)
	{
		hit.x = floor(hit.x) + 0.5;
		hit.y -= 0.5;
	}
	else
	{
		hit.x = floor(hit.x) + 0.5;
		hit.y += 0.5;
	}
	return (hit);
}

static double	pif(double a, double b)
{
	return (sqrt(a * a + b * b));
}

static double	stand_dir(t_pos hit, t_pos center,
		t_player player, double angle)
{
	double	cang;
	t_pos	sline;
	double	cline_pos;
	double	sang;

	sang = player.angle + M_PI_2;
	cang = atan2(player.y - center.y, center.x - player.x);
	sline.x = (-hit.y + center.y + center.x * tan(sang)
			   - hit.x * tan(angle)) / (tan(sang) - tan(angle));
	sline.y = hit.y + (hit.x - sline.x) * tan(angle);
	if (comp_angles(angle, cang))
		cline_pos = -pif(center.x - sline.x, center.y - sline.y);
	else
		cline_pos = pif(center.x - sline.x, center.y - sline.y);
	return (cline_pos);
}

static void	lstadd_err_check(t_list **lst, double value,
							 t_params *params, t_draw_line *dl_info)
{
	double	*p_value;
	t_list	*new_lst;

	p_value = malloc(sizeof(double *));
	if (!p_value)
	{
		ft_lstclear(&(dl_info->sprite_dist), free);
		ft_lstclear(&(dl_info->sprite_line), free);
		error("Cannt save data for a new frame");
	}
	*p_value = value;
	new_lst = ft_lstnew(p_value);
	if (!new_lst)
	{
		ft_lstclear(&(dl_info->sprite_dist), free);
		ft_lstclear(&(dl_info->sprite_line), free);
		error("Cannt save data for a new frame");
	}
	ft_lstadd_front(lst, new_lst);
}

void	add_sprite_info(t_draw_line *dl_info, double angle,
							t_params *params, t_pos hit)
{
	t_pos	center;
	double	cline_pos;
	double	c_dist;
	double	cang;

	center = find_cpos(angle, hit);
	cang = atan2(params->player.y - center.y, center.x - params->player.x);
	c_dist = pif(center.x - params->player.x, center.y - params->player.y);
	if (angle == M_PI_2 || angle == M_PI_2 * 3 || angle == -M_PI_2)
		cline_pos = cos(params->player.angle + M_PI_2) * (center.x - hit.x);
	else if (params->player.angle == 0 || params->player.angle == M_PI
		|| params->player.angle == 2 * M_PI)
		cline_pos = tan(angle) * (center.x - params->player.x)
			+ center.y - params->player.y;
	else
		cline_pos = stand_dir(hit, center, params->player, angle);
	cline_pos += 0.5;
	if (cline_pos >= 0 && cline_pos <= 1)
	{
		c_dist = pif(center.x - params->player.x, center.y - params->player.y);
		lstadd_err_check(&(dl_info->sprite_dist), c_dist * cos(cang
				- params->player.angle), params, dl_info);
		lstadd_err_check(&(dl_info->sprite_line), cline_pos, params, dl_info);
	}
	dl_info->hit = 0;
}
