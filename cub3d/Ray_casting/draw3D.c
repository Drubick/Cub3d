#include "cub3d.h"

int	drawray_3D(t_info *info)
{
	int	nbr_ray;
	int dist;
	int dist2;	

	nbr_ray = 0;
	dist = 0;
	dist2 = 0;
	create_img(info);
	while(nbr_ray < resolution_X)
	{
		info->ray_dir = info->player_direction - atan(tan((M_PI / 2) / 2.0) * (2.0 * nbr_ray / resolution_X - 1.0));
		info->ray_dir = info->ray_dir < 0 ? (M_PI * 2) + info->ray_dir : info->ray_dir;
		info->ray_dir = info->ray_dir > (M_PI * 2) ? info->ray_dir - (M_PI * 2) : info->ray_dir;
		if (info->ray_dir == M_PI || info->ray_dir == 0 || info->ray_dir == (M_PI * 1.5) || info->ray_dir == (M_PI / 2))
			info->ray_dir += 0.0000001;
		dist = vertical_coll(info);
		dist2 = horizontal_coll(info);
		if ((dist < dist2 && dist2 > 0) || dist < 0)
			dist = dist2;
		draw_vertical(info, nbr_ray, dist);
		nbr_ray += 1;
	}
	mlx_put_image_to_window(info->mlx_int, info->screen, info->image, 0, 0);
	return(0);
}

int	draw_pixel(char *img_addr, int r, int g, int b)
{
	img_addr[0] = b;
	img_addr[1] = g;
	img_addr[2] = r;
	return (4);
}