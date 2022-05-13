/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:12:54 by vnastase          #+#    #+#             */
/*   Updated: 2022/05/13 19:13:19 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_images(t_info *info)
{
	if (load_image_aux(&info->images_E, info->E_texture_path, info->mlx_int)
		|| load_image_aux(&info->images_W, info->W_texture_path, info->mlx_int)
		|| load_image_aux(&info->images_S, info->S_texture_path, info->mlx_int)
		|| load_image_aux(&info->images_N, info->N_texture_path, info->mlx_int))
		return (1);
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
