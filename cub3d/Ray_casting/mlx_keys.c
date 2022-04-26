#include "cub3d.h"

int		deal_keys(int key, t_info *info)
{
	mlx_clear_window(info->mlx_int, info->screen);
	if(key == 0)
		info->player_direction+= info->pi / 18;
	if(key == 1)
	{
		void    deal_key_1(t_info *info);
	}	
	if(key == 2)
		info->player_direction-= info->pi / 18;
	if(key == 13)
	{
		deal_key_13(info);
	}	
	if(key == 53)
		mlx_destroy_window(info->mlx_int, info->screen);
	if(info->player_direction> (2 * info->pi))
		info->player_direction= 0;
	if(info->player_direction< 0)
		info->player_direction= (2 * info->pi);
	drawray_3D(info);
	return (0);
}

void    deal_key_13(t_info *info)
{
	if(info->map[(int)(info->player_position_y)]
			[(int)(info->player_position_x + (cos(info->dir) / 10))] == '0')
			info->player_position_x += (cos(info->dir) / 10);
		if(info->map[(int)(info->player_position_y - (sin(info->dir) / 10))]
			[(int)(info->player_position_x)] == '0')
			info->player_position_y -= (sin(info->dir) / 10);
}

void    deal_key_1(t_info *info)
{
	if(info->map[(int)(info->player_position_y)]
		[(int)(info->player_position_x - (cos(info->dir) / 10))] == '0')
		info->player_position_x -= (cos(info->dir) / 10);
	if(info->map[(int)(info->player_position_y + (sin(info->dir) / 10))]
		[(int)(info->player_position_x)] == '0')
		info->player_position_y += (sin(info->dir) / 10);
}