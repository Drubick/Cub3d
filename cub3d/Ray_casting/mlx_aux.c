#include "cub3d.h"

int	create_img(t_info *info)
{
	int			bpp;
	int			size_line;
	int			endian;
	
	if(info->image != 0)
		mlx_destroy_image(info->mlx_int, info->image);
	mlx_clear_window(info->mlx_int, info->screen);
	info->image = mlx_new_image(info->mlx_int, resolution_X, resolution_Y);	
	info->img_data = mlx_get_data_addr(info->image, &bpp, &size_line, &endian);
	return(1);
}

int	draw_vertical(t_info *info, int x, int dist)
{
	int i;
	char *pixel_addr;

	pixel_addr = info->img_data + (x * 4);
	if (dist > resolution_Y || dist <= 0)
		dist = resolution_Y - 1;
	i = dist;
	pixel_addr = pixel_addr + ((((resolution_Y - i) / 2) * ((resolution_X) * 4)));
	while(i > 0)
	{
		draw_pixel(pixel_addr, R, G, B);
		i--;
		pixel_addr += (resolution_X * 4);
		if (!pixel_addr)
			break;
	}
	return(1);
}