#ifndef TYPES_H
# define TYPES_H

# include "libft.h"

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	char			*path;
}					t_data;

typedef struct s_draw_line
{
	int				line;
	char			hit;
	int				field;
	double			wall_line;
	t_list			*sprite_dist;
	t_list			*sprite_line;
	int				floor;
	int				ceiling;
}					t_draw_line;

typedef struct s_player
{
	double			x;
	double			y;
	double			angle;
	char			*walls;
}					t_player;

typedef struct s_files
{
	unsigned int	size_x;
	unsigned int	size_y;
	double			plane_dist;
	t_data			*north;
	t_data			*south;
	t_data			*west;
	t_data			*east;
	t_data			*sprite;
	int				floor;
	int				ceiling;
}					t_files;

typedef struct s_map
{
	unsigned int	width;
	unsigned int	height;
	t_files			*files;
}					t_map;

typedef struct s_params
{
	t_player		player;
	void			*mlx;
	void			*window;
	t_map			map;
	t_data			w_img;
	char			screenshot;
}					t_params;

typedef struct s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct s_inits
{
	t_data			south;
	t_data			north;
	t_data			west;
	t_data			east;
	t_data			sprite;
}					t_inits;

void	error(const char *str);
void	free_paths(t_files *files);

#endif
