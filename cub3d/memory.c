/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:08:23 by vnastase          #+#    #+#             */
/*   Updated: 2022/05/13 19:08:23 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>

void	free_memory(t_info *info, t_list *file)
{
	(void)file;
	if (info->mlx_int)
		free (info->mlx_int);
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

/*
a = image
fuc norminette
*/
int	load_image_aux(t_image *a, char *path, void *mlx_int)
{
	int			bpp;
	int			size_line;
	int			endian;

	a->image = mlx_xpm_file_to_image(mlx_int, path, &a->width, &a->height);
	if (!a->image)
		return (1);
	a->img_data = mlx_get_data_addr(a->image, &bpp, &size_line, &endian);
	return (0);
}
