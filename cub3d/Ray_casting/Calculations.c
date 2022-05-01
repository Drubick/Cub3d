#include "cub3d.h"

int vertical_coll(t_info *info)
{
	double ray_x;
	double ray_y;
	ray_x = info->player_position_x;
	ray_y = info->player_position_y;
	
	if (info->ray_dir < info->pi / 2 || info->ray_dir > info->pi * 1.5)
		ray_x = 1 + (int)ray_x;
	else
		ray_x = (int)(ray_x) - 0.00000000001;
	ray_y += (info->player_position_x - ray_x) * tan(info->ray_dir);
	printf("v = %f\n", ray_x);
	printf("v = %f\n", ray_y);
	while ((int)ray_y <= (info->file_last_line - info->file_map_first_line - 1) && (int)ray_x <= info->longest_line && (int)ray_y >= 0 && (int)ray_x >= 0)
	{
		if (info->map[(int)ray_y][(int)ray_x] == '1')
		{
			printf("v = \n");
			printf("vs = %f\n", ray_x);
			printf("vs = %f\n", ray_y);
			return (calc_dist(ray_x, ray_y, info));
		}
		if (info->ray_dir < info->pi / 2 || info->ray_dir > info->pi * 1.5)
			ray_x += 1;
		else
			ray_x -= 1.00000000001;
		if (info->ray_dir < info->pi / 2 || info->ray_dir > info->pi * 1.5)
			ray_y -= tan(info->ray_dir);
		else
			ray_y += tan(info->ray_dir);
	}
	return (-1);
}


int horizontal_coll(t_info *info)
{
	long double ray_x;
	long double ray_y;

	ray_x = info->player_position_x;
	ray_y = info->player_position_y;
	
	if (info->ray_dir > 0 && info->ray_dir < info->pi)
		ray_y =  (int)ray_y - 0.00000000001;
	else
		ray_y =  (int)ray_y + 1;
	ray_x += (info->player_position_y - ray_y) / (tan(info->ray_dir) + 0.00000000001);
	//necesito el tamaño del mapa para esta parte

	while ((int)ray_y <= (info->file_last_line - info->file_map_first_line - 1) && (int)ray_x <= info->longest_line && (int)ray_y >= 0 && (int)ray_x >= 0)
	{
		if (info->map[(int)ray_y][(int)ray_x] == '1')
		{
			printf("h = \n");
			printf("hs = %Lf\n", ray_x);
			printf("hs = %Lf\n", ray_y);
			return (calc_dist(ray_x, ray_y, info));
		}
		if (info->ray_dir > 0 && info->ray_dir < info->pi)
			ray_y -= 1.00000000001;
		else
			ray_y += 1;
		if (info->ray_dir > 0 && info->ray_dir < info->pi)
			ray_x += 1 / tan(info->ray_dir);
		else
			ray_x -= 1 / tan(info->ray_dir);
	}
	return (-1);
}

int	calc_dist(double ray_x, double ray_y, t_info *info)
{
	double	dist;
	double	seg_x;
	double	seg_y;
	int	i;
	double not_feye;
	
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
	//IMPORTANTE CAMBIARLO POR EL PATH
	return ((info->resolution_Y)/(dist));
}

void rgb_set_vertical(t_info *info)
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

void rgb_set_horizontal(t_info *info)
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
