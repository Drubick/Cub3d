/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:07:16 by vnastase          #+#    #+#             */
/*   Updated: 2022/05/13 21:34:17 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_map(t_info *info, t_list *file)
{
	int	screen_w;
	int	screen_h;

	screen_w = info->res_x * 32;
	screen_h = info->res_y * 32;
	info->mlx_int = mlx_init();
	info->screen = mlx_new_window(info->mlx_int, info->res_x,
			info->res_y, "screen");
	if (load_images(info))
		error_manager(2, info, file);
	create_img(info);
	listen_events(info);
	mlx_loop_hook(info->mlx_int, drawray_3d, info);
	mlx_loop(info->mlx_int);
}

void	listen_events(t_info *info)
{
	mlx_hook(info->screen, 2, 1L << 0, deal_keys, info);
	mlx_hook(info->screen, 3, 1L << 1, key_off, info);
	mlx_hook(info->screen, 17, (1L << 8), close_window, info);
}

int	close_window(t_info *info, t_list *file)
{
	mlx_destroy_image(info->mlx_int, info->images_e.image);
	mlx_destroy_image(info->mlx_int, info->images_n.image);
	mlx_destroy_image(info->mlx_int, info->images_s.image);
	mlx_destroy_image(info->mlx_int, info->images_w.image);
	mlx_destroy_window(info->mlx_int, info->screen);
	free_memory(info, file);
	(void)file;
	exit(0);
	return (0);
}
