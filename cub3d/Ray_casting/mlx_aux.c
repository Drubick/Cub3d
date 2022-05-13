/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgirondo <rgirondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:42:17 by rgirondo          #+#    #+#             */
/*   Updated: 2022/05/13 17:42:17 by rgirondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_img(t_info *info)
{
	int			bpp;
	int			size_line;
	int			endian;

	mlx_clear_window(info->mlx_int, info->screen);
	info->image = mlx_new_image(info->mlx_int, info->res_x,
			info->res_y);
	info->img_data = mlx_get_data_addr(info->image, &bpp, &size_line, &endian);
	return (1);
}

void	*px_ad(void *image, int x, int y, int width)
{
	return (image + (y * width + x) * 4);
}

int	draw_vertical(t_info *info, int x, int dist)
{
	int		i;
	char	*px;
	char	*px2;
	float	y_ratio;

	px = NULL;
	px2 = NULL;
	y_ratio = 0;
	i = info->res_y / 2 - 1;
	while (i && i > info->res_y / 2 - dist / 2)
	{
		y_ratio = (info->res_y / 2 - i) / (float)dist;
		px = get_image_pixel_addr(info, -y_ratio);
		px2 = px_ad(info->img_data, x, i, info->res_x);
		draw_pixel(px2, px[2], px[1], px[0]);
		px = get_image_pixel_addr(info, y_ratio);
		px2 = px_ad(info->img_data, x, info->res_y - i - 1, info->res_x);
		draw_pixel(px2, px[2], px[1], px[0]);
		i--;
	}
	return (1);
}

char	*get_image_pixel_addr(t_info *info, float y_ratio)
{
	t_image		*img_pointer;
	int			y;
	int			x;

	y_ratio += 0.5;
	img_pointer = NULL;
	if (info->colision_dir == 4)
		img_pointer = &info->images_n;
	else if (info->colision_dir == 3)
		img_pointer = &info->images_w;
	else if (info->colision_dir == 2)
		img_pointer = &info->images_s;
	else
		img_pointer = &info->images_e;
	x = img_pointer->width * info->shortest_collision;
	y = img_pointer->height * y_ratio;
	if (y < 1)
		y = 1;
	return (px_ad(img_pointer->img_data, x - 1, y, img_pointer->width));
}
