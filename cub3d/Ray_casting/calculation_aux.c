/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:39:46 by rgirondo          #+#    #+#             */
/*   Updated: 2022/05/13 17:39:46 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	calc_dist(double ray_x, double ray_y, t_info *info)
{
	double	dist;
	double	seg_x;
	double	seg_y;
	int		i;
	double	not_feye;

	not_feye = info->player_direction - info->ray_dir;
	i = 0;
	seg_x = (ray_x - info->player_position_x);
	seg_y = (ray_y - info->player_position_y);
	dist = sqrt((seg_x * seg_x) + (seg_y * seg_y));
	if (not_feye < 0)
		not_feye += 2 * info->pi;
	if (not_feye > (2 * info->pi))
		not_feye -= 2 * info->pi;
	dist = dist * cos(not_feye);
	return ((info->res_y) / (dist));
}

void	vertical_coll_aux(t_info *info, double *ray_x, double *ray_y)
{
	if (info->ray_dir < info->pi / 2 || info->ray_dir > info->pi * 1.5)
		*ray_x += 1;
	else
		*ray_x -= 1.00000000001;
	if (info->ray_dir < info->pi / 2 || info->ray_dir > info->pi * 1.5)
		*ray_y -= tan(info->ray_dir);
	else
	*ray_y += tan(info->ray_dir);
}

void	horizontal_coll_aux(t_info *info, double *ray_x, double *ray_y)
{
	if (info->ray_dir > 0 && info->ray_dir < info->pi)
		*ray_y -= 1.00000000001;
	else
		*ray_y += 1;
	if (info->ray_dir > 0 && info->ray_dir < info->pi)
		*ray_x += 1 / tan(info->ray_dir);
	else
		*ray_x -= 1 / tan(info->ray_dir);
}

void	check_colission_zero_w(t_info *info)
{
	if (info->player_direction == M_PI)
			info->player_position_x += 0.00001;
	if (info->player_direction == 0)
			info->player_position_x -= 0.00001;
	if (info->player_direction == M_PI / 2)
			info->player_position_y += 0.00001;
	if (info->player_direction == M_PI * 1.5)
			info->player_position_y -= 0.00001;
}
