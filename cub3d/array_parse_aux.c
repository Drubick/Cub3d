#include "cub3d.h"

int	map_check_0(t_info *info, int y, int x)
{
	if (x == 0)
		return (1);
	if (!ft_strchr("01NSWE", info->array_spaces[y - 1][x]) ||
		!ft_strchr("01NSWE", info->array_spaces[y + 1][x]) ||
		!ft_strchr("01NSWE", info->array_spaces[y][x + 1]))
		return (1);
	else
		return (0);
}

int	texture_w(char *texture, t_info *info)
{
	int	x;

	x = 3;
	if (ft_strncmp("WE ", texture, 3) != 0)
		return (1);
	info->W_texture_path = ft_calloc((ft_strlen(texture) - 2), sizeof(char));
	while (texture[x])
	{
		info->W_texture_path[x - 3] = texture[x];
		x++;
	}
	return (0);
}

int	texture_e(char *texture, t_info *info)
{
	int	x;

	x = 3;
	if (ft_strncmp("EA ", texture, 3) != 0)
		return (1);
	info->E_texture_path = ft_calloc((ft_strlen(texture) - 2), sizeof(char));
	while (texture[x])
	{
		info->E_texture_path[x - 3] = texture[x];
		x++;
	}
	return (0);
}

int	texture_f(char *texture, t_info *info)
{
	int	x;

	x = 2;
	if (ft_strncmp("F ", texture, 2) != 0)
		return (1);
	while (texture[x])
	{
		info->F_color[x - 2] = texture[x];
		x++;
	}
	return (0);
}

int	texture_c(char *texture, t_info *info)
{
	int	x;

	x = 2;
	if (ft_strncmp("C ", texture, 2) != 0)
		return (1);
	while (texture[x])
	{
		info->C_color[x - 2] = texture[x];
		x++;
	}
	return (2);
}
