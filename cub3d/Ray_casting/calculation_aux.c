#include "cub3d.h"

float	to_degree(float angle)
{
	return (angle * 180 / M_PI);
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
			info->player_position_x -=  0.00001;
	if (info->player_direction == M_PI / 2)
			info->player_position_y += 0.00001;
	if (info->player_direction == M_PI * 1.5)
			info->player_position_y -=  0.00001;
}

void	check_colission_zero_s(t_info *info)
{
	if ((info->player_position_x - (int)info->player_position_x) == 0 && (info->player_direction > M_PI / 2 && info->player_direction < M_PI * 1.5))
			info->player_position_x -= 0.2;
	if ((info->player_position_x - (int)info->player_position_x) == 0 && (info->player_direction < M_PI / 2 || info->player_direction > M_PI * 1.5))
			info->player_position_x += 0.2;
	if ((info->player_position_y - (int)info->player_position_y) == 0 && (info->player_direction > 0 && info->player_direction < M_PI))
			info->player_position_y += 0.2;
	if ((info->player_position_y - (int)info->player_position_y) == 0 && info->player_direction > M_PI)
			info->player_position_y -= 0.2;
}