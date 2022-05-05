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

void load_image_aux(t_image *image, char *path, void * mlx_int)
{
	int			bpp;
	int			size_line;
	int			endian;

	image->image = mlx_xpm_file_to_image(mlx_int, path, &image->width, &image->height);
	image->img_data = mlx_get_data_addr(image->image, &bpp, &size_line, &endian);
}

int	load_images(t_info *info)
{
	load_image_aux(&info->images_E, info->E_texture_path, info->mlx_int);
	load_image_aux(&info->images_W, info->W_texture_path, info->mlx_int);
	load_image_aux(&info->images_S, info->S_texture_path, info->mlx_int);
	load_image_aux(&info->images_N, info->N_texture_path, info->mlx_int);
	if (info->images_E.image && info->images_W.image
		&& info->images_N.image
		&& info->images_S.image)
		return (1);
	return (0);
}