/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:56:42 by vnastase          #+#    #+#             */
/*   Updated: 2022/05/13 18:56:42 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>

int	array_parse_loop(t_info *info, int y, int x)
{
	while (info->file[y])
	{
		if (info->file[y][x] == '1')
			break ;
		while (info->file[y][x] != 1 && info->file[y][x])
		{
			if (info->file[y][x] == '1')
				break ;
			if (!ft_strchr(" \n", info->file[y][x]))
				return (1);
			x++;
		}
		if (info->file[y][x] == '1')
			break ;
		x = 0;
		y++;
	}
	return (0);
}
/*
Parsea el array en busca de errores en la forma del archivo pasado
*/

int	arry_parse(t_info *info)
{
	int	y;
	int	x;
	int	no_longer_textures;

	x = 0;
	y = 0;
	no_longer_textures = 0;
	while (no_longer_textures == 0 || no_longer_textures == 1)
	{
		no_longer_textures = texture_check_save(info->file[y], info);
		if (no_longer_textures == 1)
			return (1);
		y++;
	}
	if (array_parse_loop(info, y, x))
		return (1);
	if (map_check(y, info) == 0)
		map_saving(y, info);
	else
		return (1);
	return (0);
}

int	texture_check_save(char *texture, t_info *info)
{
	int	returnal;

	returnal = 0;
	while (*texture == ' ')
		texture++;
	if (!ft_strchr(" NSWEFC\n", *texture))
		return (1);
	if (*texture == 'N')
		returnal = texture_n(texture, info);
	else if (*texture == 'S')
		returnal = texture_s(texture, info);
	else if (*texture == 'W')
		returnal = texture_w(texture, info);
	else if (*texture == 'E')
		returnal = texture_e(texture, info);
	else if (*texture == 'F')
		returnal = texture_f(texture, info);
	else if (*texture == 'C')
		returnal = texture_c(texture, info);
	return (returnal);
}

int	texture_n(char *texture, t_info *info)
{
	int	x;

	x = 3;
	if (ft_strncmp("NO ", texture, 3) != 0)
		return (1);
	info->n_texture_path = ft_calloc((ft_strlen(texture) - 2), sizeof(char));
	while (texture[x])
	{
		info->n_texture_path[x - 3] = texture[x];
		x++;
	}
	info->n_texture_path[x - 4] = '\0';
	info->is_n_texture++;
	if (info->is_n_texture > 1)
		return (1);
	if (info->is_n_texture && info->is_s_texture && info->is_e_texture
		&& info->is_w_texture && info->is_f_color && info->is_c_color)
		return (2);
	return (0);
}

int	texture_s(char *texture, t_info *info)
{
	int	x;

	x = 3;
	if (ft_strncmp("SO ", texture, 3) != 0)
		return (1);
	info->s_texture_path = ft_calloc((ft_strlen(texture) - 2), sizeof(char));
	while (texture[x])
	{
		info->s_texture_path[x - 3] = texture[x];
		x++;
	}
	info->s_texture_path[x - 4] = '\0';
	info->is_s_texture++;
	if (info->is_s_texture > 1)
		return (1);
	if (info->is_n_texture && info->is_s_texture && info->is_e_texture
		&& info->is_w_texture && info->is_f_color && info->is_c_color)
		return (2);
	return (0);
}
