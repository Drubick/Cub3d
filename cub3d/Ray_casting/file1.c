#include "cub3d.h"

void	*canvas_f(t_info *info, char *img_data)
{
	int	x;
	int	y;

	y = info->resolution_Y / 2;
	while (y < info->resolution_Y)
	{
		x = 0;
		while (x < (info->resolution_X * 4))
		{
			img_data[(y * info->resolution_X * 4) + x] = info->F_color[2];
			x++;
			img_data[(y * info->resolution_X * 4) + x] = info->F_color[1];
			x++;
			img_data[(y * info->resolution_X * 4) + x] = info->F_color[0];
			x = x + 2;
		}
		y++;
	}
	return (0);
}

void	*canvas_c(t_info *info, char *img_data)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->resolution_Y)
	{
		x = 0;
		while (x < (info->resolution_X * 4))
		{
			img_data[(y * info->resolution_X * 4) + x] = info->C_color[2];
			x++;
			img_data[(y * info->resolution_X * 4) + x] = info->C_color[1];
			x++;
			img_data[(y * info->resolution_X * 4) + x] = info->C_color[0];
			x = x + 2;
		}
		y++;
	}
	return (0);
}
