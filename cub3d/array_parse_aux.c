/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_parse_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:45:53 by vnastase          #+#    #+#             */
/*   Updated: 2022/05/13 21:33:14 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_check_0(t_info *info, int y, int x)
{
	if (x == 0)
		return (1);
	if (!ft_strchr("01NSWE", info->array_spaces[y - 1][x]) ||
		!ft_strchr("01NSWE", info->array_spaces[y + 1][x]) ||
		!ft_strchr("01NSWE", info->array_spaces[y][x + 1]) ||
		!ft_strchr("01NSWE", info->array_spaces[y][x - 1]))
		return (1);
	else
		return (0);
}

int	texture_w(char *texture, t_info *info)
{
	int		x;
	char	*aux;
	
	x = 3;
	if (ft_strncmp("WE ", texture, 3) != 0)
		return (1);
	if (!info->w_texture_path)
		info->w_texture_path = ft_calloc((ft_strlen(texture) - 2), sizeof(char));
	while (texture[x])
	{
		info->w_texture_path[x - 3] = texture[x];
		x++;
	}
	info->w_texture_path[x - 4] = '\0';
	info->is_w_texture++;
	aux = info->w_texture_path;
	info->w_texture_path = ft_strtrim(info->w_texture_path, " ");
	free(aux);
	if (info->is_w_texture > 1)
		return (1);
	if (info->is_n_texture && info->is_s_texture && info->is_e_texture
		&& info->is_w_texture && info->is_f_color && info->is_c_color)
		return (2);
	return (0);
}

int	texture_e(char *texture, t_info *info)
{
	int		x;
	char	*aux;

	aux = NULL;
	x = 3;
	if (ft_strncmp("EA ", texture, 3) != 0)
		return (1);
	if (!info->e_texture_path)
		info->e_texture_path = ft_calloc((ft_strlen(texture) - 2), sizeof(char));
	while (texture[x])
	{
		info->e_texture_path[x - 3] = texture[x];
		x++;
	}
	info->e_texture_path[x - 4] = '\0';
	aux = info->e_texture_path;
	info->e_texture_path = ft_strtrim(info->e_texture_path, " ");
	info->is_e_texture++;
	free(aux);
	if (info->is_e_texture > 1)
		return (1);
	if (info->is_n_texture && info->is_s_texture && info->is_e_texture
		&& info->is_w_texture && info->is_f_color && info->is_c_color)
		return (2);
	return (0);
}

int	texture_f(char *texture, t_info *info)
{
	if (ft_strncmp("F ", texture, 2) != 0)
		return (1);
	texture++;
	while(*texture == ' ')
		texture++;
	if (separate_rgb(texture, info, 2))
		return (1);
	info->is_f_color++;
	if (info->is_f_color > 1)
		return (1);
	if (info->is_n_texture && info->is_s_texture && info->is_e_texture
		&& info->is_w_texture && info->is_f_color && info->is_c_color)
		return (2);
	return (0);
}

int	texture_c(char *texture, t_info *info)
{
	if (ft_strncmp("C ", texture, 2) != 0)
		return (1);
	texture++;
	while(*texture == ' ')
		texture++;
	if (separate_rgb(texture, info, 1))
		return (1);
	info->is_c_color++;
	if (info->is_c_color > 1)
		return (1);
	if (info->is_n_texture && info->is_s_texture && info->is_e_texture
		&& info->is_w_texture && info->is_f_color && info->is_c_color)
		return (2);
	return (0);
}
