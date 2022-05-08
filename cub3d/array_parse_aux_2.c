#include "cub3d.h"

int	save_rgb_c(t_info *info, char aux[3], int rgb)
{
	info->C_color[rgb] = ft_atoi(aux);
	if (info->C_color[rgb] < 0 || info->C_color[rgb] > 255)
		return (1);
	return (0);
}

int	save_rgb_f(t_info *info, char aux[3], int rgb)
{
    info->F_color[rgb] = ft_atoi(aux);
	if (info->F_color[rgb] < 0 || info->F_color[rgb] > 255)
		return (1);
	return (0);

}

int	separate_rgb(char *texture, t_info *info, int rgb)
{
	int	i;
	int	j;
	char aux[4];
    int x;

	aux[3] = '\0';
	i = 0;
	j = 0;
    x = 0;
	while (texture[i] && x <= 2)
	{
		while (texture[i] != ',' && texture[i] && texture[i != ' '])
		{
			aux[j] = texture[i];
			j++;
			i++;
		}
		aux[j] = '\0';
		j = 0;
		i++;
		if (rgb == 1)
		{
			if (save_rgb_c(info, aux, x))
				return (1);
		}
		else
		{
			if (save_rgb_f(info, aux, x))
				return (1);
		}
        x++;
	}
	if (x != 3)
		return(1);
	return(0);
}
