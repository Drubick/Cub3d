#include "cub3d.h"

int	vertical_coll(t_info *info)
{
	double	ray_x;
	double	ray_y;

	ray_x = info->player_position_x;
	ray_y = info->player_position_y;
	if (info->ray_dir < info->pi / 2 || info->ray_dir > info->pi * 1.5)
		ray_x = 1 + (int)ray_x;
	else
		ray_x = (int)(ray_x) - 0.00000000001;
	ray_y += (info->player_position_x - ray_x) * tan(info->ray_dir);
	while ((int)ray_y <= (info->file_last_line - info->file_map_first_line - 1)
		&& (int)ray_x <= info->longest_line
		&& (int)ray_y >= 0 && (int)ray_x >= 0)
	{
		if (info->map[(int)ray_y][(int)ray_x] == '1')
			return (calc_dist(ray_x, ray_y, info));
		vertical_coll_aux(info, &ray_x, &ray_y);
	}
	return (-1);
}

int	horizontal_coll(t_info *info)
{
	double	ray_x;
	double	ray_y;

	ray_x = info->player_position_x;
	ray_y = info->player_position_y;
	if (info->ray_dir > 0 && info->ray_dir < info->pi)
		ray_y = (int)ray_y - 0.00000000001;
	else
		ray_y = (int)ray_y + 1;
	ray_x += (info->player_position_y - ray_y)
		/ (tan(info->ray_dir) + 0.00000000001);
	while ((int)ray_y <= (info->file_last_line - info->file_map_first_line - 1)
		&& (int)ray_x <= info->longest_line && (int)ray_y >= 0
		&& (int)ray_x >= 0)
	{
		if (info->map[(int)ray_y][(int)ray_x] == '1')
			return (calc_dist(ray_x, ray_y, info));
		horizontal_coll_aux(info, &ray_x, &ray_y);
	}
	return (-1);
}

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
	return ((info->resolution_Y) / (dist));
}

void	rgb_set_vertical(t_info *info)
{
	if (info->ray_dir > (M_PI / 2) && info->ray_dir < (M_PI * 1.5))
	{
		info->R = 252;
		info->G = 3;
		info->B = 3;
	}
	if (info->ray_dir < (M_PI / 2) || info->ray_dir > (M_PI * 1.5))
	{
		info->R = 252;
		info->G = 252;
		info->B = 3;
	}
}

void	rgb_set_horizontal(t_info *info)
{
	if (info->ray_dir < M_PI && info->ray_dir > 0)
	{
		info->R = 36;
		info->G = 252;
		info->B = 3;
	}
	else
	{
		info->R = 3;
		info->G = 252;
		info->B = 236;
	}
}
