#include "cub3d.h"
#include <unistd.h>

/*
Parsea el array en busca de errores en la forma del archivo pasado
*/
int	arry_parse(t_info *info)
{
	
	int	y;
	int	no_longer_textures;

	y = 0;
	no_longer_textures = 0;
	while (no_longer_textures == 0 || no_longer_textures == 1)
	{
		no_longer_textures = texture_check_save(info->file[y], y, info);
		if (no_longer_textures == 1)
			return (1);
		y++;
	}
	if (map_check(y, info) == 0)
	{
		
		map_saving(y, info);
	}
	return (0);
}

int	texture_check_save(char *texture, int y, t_info *info)
{
	int	returnal;

	returnal = 0;
	if (y == 0)
		returnal = texture_n(texture, info);
	else if (y == 1)
		returnal = texture_s(texture, info);
	else if (y == 2)
		returnal = texture_w(texture, info);
	else if (y == 3)
		returnal = texture_e(texture, info);
	else if (y == 5)
		returnal = texture_f(texture, info);
	else if (y == 6)
		returnal = texture_c(texture, info);
	return (returnal);
}

int	texture_n(char *texture, t_info *info)
{
	int	x;

	x = 3;
	if (ft_strncmp("NO ", texture, 3) != 0)
		return (1);
	info->N_texture_path = ft_calloc((ft_strlen(texture) - 2), sizeof(char));
	while (texture[x])
	{
		info->N_texture_path[x - 3] = texture[x];
		x++;
	}
	return (0);
}

int	texture_s(char *texture, t_info *info)
{
	int	x;

	x = 3;
	if (ft_strncmp("SO ", texture, 3) != 0)
		return (1);
	info->S_texture_path = ft_calloc((ft_strlen(texture) - 2), sizeof(char));
	while (texture[x])
	{
		info->S_texture_path[x - 3] = texture[x];
		x++;
	}
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
