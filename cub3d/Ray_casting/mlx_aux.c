#include "cub3d.h"

int	create_img(t_info *info)
{
	int			bpp;
	int			size_line;
	int			endian;

	if (info->image != 0)
		mlx_destroy_image(info->mlx_int, info->image);
	mlx_clear_window(info->mlx_int, info->screen);
	info->image = mlx_new_image(info->mlx_int, info->resolution_X,
			info->resolution_Y);
	info->img_data = mlx_get_data_addr(info->image, &bpp, &size_line, &endian);
	return (1);
}

void *get_pixel_address(void *image, int x, int y, int width)
{
	return (image + (y * width + x) * 4);
}

int	draw_vertical(t_info *info, int x, int dist)
{
	int		i;;
	char	*img_pixel_addr;
	float	y_ratio;

	i = info->resolution_Y / 2 - 1;

	while (i && i > info->resolution_Y / 2 -  dist / 2)
	{
		y_ratio = 0.5 + (info->resolution_Y / 2 - i) / (float)dist; 
		img_pixel_addr = get_image_pixel_addr(info, y_ratio);
		draw_pixel(get_pixel_address(info->img_data, x, i, info->resolution_X), img_pixel_addr[2], img_pixel_addr[1], img_pixel_addr[0]);
		draw_pixel(get_pixel_address(info->img_data, x, info->resolution_Y - i - 1, info->resolution_X), img_pixel_addr[2], img_pixel_addr[1], img_pixel_addr[0]);
		i--;
	}
	
	return (1);
}

char *get_image_pixel_addr(t_info *info, float y_ratio)
{
	t_image 	*img_pointer;
	int			y;
	int			x;

	img_pointer = NULL;
	if (info->colision_dir == 1)
		img_pointer = &info->images_N;
	else if (info->colision_dir == 2)
		img_pointer = &info->images_W;
	else if (info->colision_dir == 3)
		img_pointer = &info->images_S;
	else
		img_pointer = &info->images_E;
	x = img_pointer->width * info->shortest_collision;
	y = img_pointer->height * y_ratio;
	return(get_pixel_address(img_pointer->img_data, x - 1, y, img_pointer->width));
}
