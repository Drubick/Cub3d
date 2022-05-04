#include "cub3d.h"

void	free_memory(t_info *info)
{
	if (info->mlx_int)
		free (info->mlx_int);
	if (info->screen)
		free (info->screen);
	if (info->image)
		free (info->image);
	if (info->img_data)
		free (info->img_data);
	if (info->map)
		free (info->map);
	if (info->file)
		free (info->file);
	if (info->array_spaces)
		free (info->array_spaces);
	free_textures(info);
}

void	free_textures(t_info *info)
{
	if (info->N_texture_path)
		free (info->N_texture_path);
	if (info->S_texture_path)
		free (info->S_texture_path);
	if (info->E_texture_path)
		free (info->E_texture_path);
	if (info->W_texture_path)
		free (info->W_texture_path);
}

int	load_images(t_info *info)
{
	int	p;
	int	j;

	info->images_E = mlx_xpm_file_to_image(info->mlx_int,
			info->E_texture_path, &p, &j);
	info->images_W = mlx_xpm_file_to_image(info->mlx_int,
			info->W_texture_path, &p, &j);
	info->images_S = mlx_xpm_file_to_image(info->mlx_int,
			info->S_texture_path, &p, &j);
	info->images_N = mlx_xpm_file_to_image(info->mlx_int,
			info->N_texture_path, &p, &j);
	if (info->images_E && info->images_W
		&& info->images_N
		&& info->images_S)
		return (1);
	return (0);
}