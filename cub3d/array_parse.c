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
		map_saving(y, info);
	else
		return (1);
	return (0);
}

int	texture_check_save(char *texture, int y, t_info *info)
{
	int	returnal;
	returnal = 1;

	while (texture[y] == ' ')
		y++;
	if (texture[y] == 'N')
		returnal = texture_n(texture, info);
	else if (texture[y] == 'S')
		returnal = texture_s(texture, info);
	else if (texture[y] == 'W')
		returnal = texture_w(texture, info);
	else if (texture[y] == 'E')
		returnal = texture_e(texture, info);
	else if (texture[y] == 'F')
		returnal = texture_f(texture, info);
	else if (texture[y] == 'C')
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
	info->N_texture_path[x-4] = '\0';
	info->is_n_texture++;
	if (info->is_n_texture > 1)
		return(1);
	if (info->is_n_texture && info->is_s_texture && info->is_e_texture && info->is_w_texture
		&& info->is_f_color && info->is_c_color)
		return(2);
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
	info->S_texture_path[x-4] = '\0';
	info->is_s_texture++;
	if (info->is_s_texture > 1)
		return(1);
	if (info->is_n_texture && info->is_s_texture && info->is_e_texture && info->is_w_texture
		&& info->is_f_color && info->is_c_color)
		return(2);
	return (0);
}
