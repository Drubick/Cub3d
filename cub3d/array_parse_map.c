#include "cub3d.h"
#include <unistd.h>

int	map_check(int y, t_info *info)
{
	int	x;
	int	error;

	x = 0;
	error = 0;
	y += 1;
	info->file_map_first_line = y;
	while (info->array_spaces[y] && y <= info->file_last_line)
	{
		while (info->array_spaces[y][x])
		{
			error = map_check_aux(info, y, x, error);
			if (error == 1)
			{
				printf("first line = %i\n", info->file_map_first_line);
				printf("x = %i\n", x);
				printf("y = %i\n", y);
				return (error);
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (info->player < 1 || info->player == 0)
		return (1);
	return (0);
}

int	map_check_aux(t_info *info, int y, int x, int error)
{
	if (y == info->file_last_line || y == info->file_map_first_line)
	{
		if (info->array_spaces[y][x] != '1' &&
			info->array_spaces[y][x] != ' ' &&
			info->array_spaces[y][x] != '\n')
			return (1);
	}
	
	if (!ft_strchr(" SE10WN\n", info->array_spaces[y][x]))
		return (1);
	
	else if (info->array_spaces[y][x] != '\n' &&
		y != info->file_last_line && error == 0 &&
		y != info->file_map_first_line)
	{
		
		if (info->array_spaces[y][x] == '0')
			error = map_check_0(info, y, x);
		else if (ft_strchr("SEWN", info->array_spaces[y][x]))
			error = map_check_player(y, x, info);
		else if (info->array_spaces[y][x] == ' ')
			error = map_check_space(info, y, x);
	}
	return (error);
}
