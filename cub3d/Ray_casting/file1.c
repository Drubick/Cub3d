/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:42:08 by rgirondo          #+#    #+#             */
/*   Updated: 2022/05/13 17:42:08 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*canvas_f(t_info *info, char *img_data)
{
	int	x;
	int	y;

	y = info->res_Y / 2;
	while (y < info->res_Y)
	{
		x = 0;
		while (x < (info->res_X * 4))
		{
			img_data[(y * info->res_X * 4) + x] = info->F_color[2];
			x++;
			img_data[(y * info->res_X * 4) + x] = info->F_color[1];
			x++;
			img_data[(y * info->res_X * 4) + x] = info->F_color[0];
			x = x + 2;
		}
		y++;
	}
	return (0);
}

void	*canvas_c(t_info *info, char *img_data)
{
	int	x;
	int	y;

	y = 0;
	while (y < (info->res_Y / 2))
	{
		x = 0;
		while (x < (info->res_X * 4))
		{
			img_data[(y * info->res_X * 4) + x] = info->C_color[2];
			x++;
			img_data[(y * info->res_X * 4) + x] = info->C_color[1];
			x++;
			img_data[(y * info->res_X * 4) + x] = info->C_color[0];
			x = x + 2;
		}
		y++;
	}
	return (0);
}
