#include "cub3d.h"

int	map_check_player(int y, int x, t_info *info)
{
	info->player++;
	info->player_position_x = x + 0.1;
	info->player_position_y = y - info->file_map_first_line + 0.1;
	info->player_direction_char = info->array_spaces[y][x];
	transform_direction_radian(info->player_direction_char, info);
	info->array_spaces[y][x] = '0';
	if (x == 0)
		return (1);
	if (!ft_strchr("01NSWE", info->array_spaces[y - 1][x]) ||
		!ft_strchr("01NSWE", info->array_spaces[y + 1][x]) ||
		!ft_strchr("01NSWE", info->array_spaces[y][x + 1]) ||
		!ft_strchr("01NSWE", info->array_spaces[y][x - 1]))
		return (1);
	else
		return (0);
}

void	transform_direction_radian(char direction, t_info *info)
{
	if (direction == 'N')
		info->player_direction = M_PI / 2;
	else if (direction == 'S')
		info->player_direction = M_PI * 1.5;
	else if (direction == 'E')
		info->player_direction = 0;
	else if (direction == 'W')
		info->player_direction = M_PI;
}

int	map_check_space(t_info *info, int y, int x)
{
	if (x == 0)
		return (0);
	if (y == (info->file_last_line - 1))
		return (0);
	if (!ft_strchr(" 1\n", info->array_spaces[y - 1][x]) ||
		!ft_strchr(" 1\n", info->array_spaces[y + 1][x]) ||
		!ft_strchr(" 1\n", info->array_spaces[y][x + 1]) ||
		!ft_strchr(" 1\n", info->array_spaces[y][x - 1]))
		return (1);
	else
		return (0);
}

void	map_saving(int y, t_info *info)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	info->map = ft_calloc((info->file_last_line - y + 1), sizeof(char *));
	while (j < (info->file_last_line - y))
	{
		info->map[j] = ft_calloc((info->longest_line), sizeof(char));
		j++;
	}

	j = 0;
	while (info->file[j + y])
	{
		while (info->array_spaces[j + y][i])
		{
			info->map[j][i] = info->array_spaces[j + y][i];
			i++;
		}
		i = 0;
		j++;
	}

}
