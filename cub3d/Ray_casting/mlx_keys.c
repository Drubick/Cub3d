/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:24:13 by rgirondo          #+#    #+#             */
/*   Updated: 2022/05/13 18:24:13 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	deal_keys(int key, t_info *info, t_list *file)
{
	printf("%i\n", key);
	key_on(key, info);
	if (key == 0)
		deal_key_0(info);
	if (key == 124)
		info->player_direction -= info->pi / 18;
	if (key == 123)
		info->player_direction += info->pi / 18;
	if (key == 1)
		deal_key_1(info);
	if (key == 2)
		deal_key_2(info);
	if (key == 13)
		deal_key_13(info);
	if (key == 53)
		close_window(info, file);
	if (info->player_direction > (2 * info->pi))
		info->player_direction = 0;
	if (info->player_direction < 0)
		info->player_direction = (2 * info->pi);
	return (0);
}

void	deal_key_13(t_info *info)
{
	if (info->map[(int)(info->player_position_y)]
			[(int)(info->player_position_x
			+ (cos(info->player_direction) * 0.13))] == '0')
				info->player_position_x += (cos(info->player_direction) * 0.13);
	if (info->map[(int)(info->player_position_y
			- (sin(info->player_direction) * 0.3))]
			[(int)(info->player_position_x)] == '0')
				info->player_position_y -= (sin(info->player_direction) * 0.13);
}

void	deal_key_2(t_info *info)
{
	if (info->map[(int)(info->player_position_y)]
			[(int)(info->player_position_x
			+ (cos(info->player_direction - 0.5 * M_PI)  * 0.13))] == '0')
				info->player_position_x += (cos(info->player_direction - 0.5 * M_PI) * 0.13);
	if (info->map[(int)(info->player_position_y
			- (sin(info->player_direction - 0.5 * M_PI) * 0.3))]
			[(int)(info->player_position_x)] == '0')
				info->player_position_y -= (sin(info->player_direction - 0.5 * M_PI) * 0.13);
}

void	deal_key_0(t_info *info)
{
	if (info->map[(int)(info->player_position_y)]
			[(int)(info->player_position_x
			+ (cos(info->player_direction + 0.5 * M_PI)  * 0.13))] == '0')
				info->player_position_x += (cos(info->player_direction + 0.5 * M_PI) * 0.13);
	if (info->map[(int)(info->player_position_y
			- (sin(info->player_direction + 0.5 * M_PI) * 0.3))]
			[(int)(info->player_position_x)] == '0')
				info->player_position_y -= (sin(info->player_direction + 0.5 * M_PI) * 0.13);
}


void	deal_key_1(t_info *info)
{
	if (info->map[(int)(info->player_position_y)]
		[(int)(info->player_position_x
		- (cos(info->player_direction) * 0.13))] == '0')
			info->player_position_x -= (cos(info->player_direction) * 0.13);
	if (info->map[(int)(info->player_position_y
			+ (sin(info->player_direction) * 0.13))]
		[(int)(info->player_position_x)] == '0')
		info->player_position_y += (sin(info->player_direction) * 0.13);
}

int	key_off(int key, t_info *info)
{
	if (key == 0)
		info->key_0 = 0;
	if (key == 1)
		info->key_1 = 0;
	if (key == 2)
		info->key_2 = 0;
	if (key == 13)
		info->key_13 = 0;
	return (0);
}

void	key_on(int key, t_info *info)
{
	if (key == 0)
		info->key_0 = 1;
	if (key == 1)
		info->key_1 = 1;
	if (key == 2)
		info->key_2 = 1;
	if (key == 13)
		info->key_13 = 1;
}
