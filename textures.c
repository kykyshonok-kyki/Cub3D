#include "mlx.h"
#include "types.h"

static void	get_addr(void *mlx, void *win, t_files *files)
{
	files->north->addr = mlx_get_data_addr(files->north->img,
			&files->north->bits_per_pixel, &files->north->line_length,
			&files->north->endian);
	files->south->addr = mlx_get_data_addr(files->south->img,
			&files->south->bits_per_pixel, &files->south->line_length,
			&files->south->endian);
	files->east->addr = mlx_get_data_addr(files->east->img,
			&files->east->bits_per_pixel, &files->east->line_length,
			&files->east->endian);
	files->west->addr = mlx_get_data_addr(files->west->img,
			&files->west->bits_per_pixel, &files->west->line_length,
			&files->west->endian);
	files->sprite->addr = mlx_get_data_addr(files->sprite->img,
			&files->sprite->bits_per_pixel, &files->sprite->line_length,
			&files->sprite->endian);
	if (!files->north->addr)
		error("Failed to save xpm texture");
	if (!files->south->addr)
		error("Failed to save xpm texture");
	if (!files->east->addr)
		error("Failed to save xpm texture");
	if (!files->west->addr)
		error("Failed to save xpm texture");
	if (!files->sprite->addr)
		error("Failed to save xpm texture");
}

void	def_textures(void *mlx, void *win, t_files *files)
{
	files->north->img = mlx_xpm_file_to_image(mlx, files->north->path,
			&files->north->width, &files->north->height);
	files->south->img = mlx_xpm_file_to_image(mlx, files->south->path,
			&files->south->width, &files->south->height);
	files->west->img = mlx_xpm_file_to_image(mlx, files->west->path,
			&files->west->width, &files->west->height);
	files->east->img = mlx_xpm_file_to_image(mlx, files->east->path,
			&files->east->width, &files->east->height);
	files->sprite->img = mlx_xpm_file_to_image(mlx, files->sprite->path,
			&files->sprite->width, &files->sprite->height);
	if (!files->north->img)
		error("Failed to save xpm texture");
	if (!files->south->img)
		error("Failed to save xpm texture");
	if (!files->west->img)
		error("Failed to save xpm texture");
	if (!files->east->img)
		error("Failed to save xpm texture");
	if (!files->sprite->img)
		error("Failed to save xpm texture");
	get_addr(mlx, win, files);
	free_paths(files);
}
