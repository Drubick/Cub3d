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