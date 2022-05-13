/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_parse_aux_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:13:03 by vnastase          #+#    #+#             */
/*   Updated: 2022/05/13 20:15:46 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	save_rgb_c(t_info *info, int rgb)
{
	info->c_color[rgb] = ft_atoi(info->aux);
	if (info->c_color[rgb] < 0 || info->c_color[rgb] > 255)
		return (1);
	return (0);
}

int	save_rgb_f(t_info *info, int rgb)
{
	info->f_color[rgb] = ft_atoi(info->aux);
	if (info->f_color[rgb] < 0 || info->f_color[rgb] > 255)
		return (1);
	return (0);
}

int	separate_rgb_aux(int rgb, int *x, t_info *info)
{
	if (info->j < 1)
		return(1);
	if (info->j < 3)
		info->aux[info->j] = '\0';
	if (rgb == 1)
	{
		if (save_rgb_c(info, *x))
			return (1);
			info->c_color[3] = 0;
	}
	else
	{
		if (save_rgb_f(info, *x))
			return (1);
		info->f_color[3] = 0;
	}
	info->j = 0;
	info->i++;
	return (0);
}

int	separate_rgb(char *texture, t_info *info, int rgb)
{
	int	x;

	info->aux[3] = '\0';
	info->i = 0;
	info->j = 0;
	x = 0;
	while (texture[info->i] && x <= 2)
	{
		while (texture[info->i] != ',' && texture[info->i]
			&& texture[info->i] != ' ' && texture[info->i] != '\n'
			&& texture[info->i])
		{
			if (!ft_isdigit(texture[info->i]))
				return (1);
			info->aux[info->j] = texture[info->i];
			info->j++;
			info->i++;
		}
		if (separate_rgb_aux(rgb, &x, info))
			return (1);
		x++;
	}
	if (x != 3)
		return (1);
	return (0);
}
