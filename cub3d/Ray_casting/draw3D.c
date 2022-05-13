/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:40:03 by rgirondo          #+#    #+#             */
/*   Updated: 2022/05/13 17:40:03 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	drawray_3d(t_info *info)
{	
	int	nbr_ray;
	int	dist;
	int	dist2;	

	nbr_ray = 0;
	dist = 0;
	dist2 = 0;
	mlx_clear_window(info->mlx_int, info->screen);
	canvas_c(info, info->img_data);
	canvas_f(info, info->img_data);
	while (nbr_ray < info->res_x)
	{
		info->ray_dir = info->player_direction
			- atan(tan(((info->fov * M_PI / 180) / 2) / 2.0)
				* (2.0 * nbr_ray / info->res_x - 1.0));
		draw3d_if(info);
		dist = vertical_coll(info);
		dist2 = horizontal_coll(info);
		identify_coll(info, nbr_ray++, dist, dist2);
	}
	mlx_put_image_to_window(info->mlx_int, info->screen, info->image, 0, 0);
	return (0);
}

int	draw_pixel(char *img_addr, int r, int g, int b)
{
	img_addr[0] = b;
	img_addr[1] = g;
	img_addr[2] = r;
	return (4);
}

void	draw3d_if(t_info *info)
{
	if (info->ray_dir < 0)
		info->ray_dir = (M_PI * 2) + info->ray_dir;
	if (info->ray_dir > (M_PI * 2))
		info->ray_dir = info->ray_dir - (M_PI * 2);
	if (info->ray_dir == M_PI || info->ray_dir == 0
		|| info->ray_dir == (M_PI * 1.5)
		|| info->ray_dir == (M_PI / 2))
		info->ray_dir += 0.0000001;
}

void	identify_coll(t_info *info, int nbr_ray, int dist, int dist2)
{
	if ((dist < dist2 && dist2 > 0) || dist < 0)
	{
		info->shortest_collision = info->ray_coll_x;
		if (dist != dist2)
			rgb_set_horizontal(info);
		draw_vertical(info, nbr_ray, dist2);
	}
	else
	{
		info->shortest_collision = info->ray_coll_y;
		if (dist != dist2)
			rgb_set_vertical(info);
		draw_vertical(info, nbr_ray, dist);
	}
}
