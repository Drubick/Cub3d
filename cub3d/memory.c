#include "cub3d.h"
#include <fcntl.h>
void	free_memory(t_info *info, t_list *file)
{
	(void)file;
	if (info->mlx_int)
		free (info->mlx_int);
	if (info->image)
		free (info->image);
	if (info->img_data)
		free (info->img_data);
	if (info->map)
		free_map(info);
	if (info->file)
		free_file(info);
	if (info->array_spaces)
		free_array_spaces(info);

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


int load_image_aux(t_image *image, char *path, void * mlx_int)
{
	int			bpp;
	int			size_line;
	int			endian;

	image->image = mlx_xpm_file_to_image(mlx_int, path, &image->width, &image->height);
	if (!image->image)
		return (1);
	image->img_data = mlx_get_data_addr(image->image, &bpp, &size_line, &endian);
	return (0);
}

int	load_images(t_info *info)
{
	if(load_image_aux(&info->images_E, info->E_texture_path, info->mlx_int)
		|| load_image_aux(&info->images_W, info->W_texture_path, info->mlx_int)
		|| load_image_aux(&info->images_S, info->S_texture_path, info->mlx_int)
		|| load_image_aux(&info->images_N, info->N_texture_path, info->mlx_int))
		return(1);
	if (!info->images_E.image && !info->images_W.image
		&& !info->images_N.image
		&& !info->images_S.image)
		return (1);
	return (0);
}

void	free_file(t_info *info)
{
	int	i;

	i = 0;
	while (info->file[i])
	{
		free(info->file[i]);
		i++;
	}
	free(info->file[i]);
	free(info->file);
}

void	free_map(t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i])
	{
		free(info->map[i]);
		i++;
	}
	free(info->map[i]);
	free(info->map);
}

void	free_array_spaces(t_info *info)
{
	int	i;

	i = 0;
	while (info->array_spaces[i])
	{
		free(info->array_spaces[i]);
		i++;
	}
	free(info->array_spaces[i]);
	free(info->array_spaces);
}

