/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnastase <vnastase@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:05:03 by vnastase          #+#    #+#             */
/*   Updated: 2022/05/13 19:07:04 by vnastase         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_manager(int conditional, t_info *info, t_list *file)
{
	if (conditional == 1)
		printf("Invalid map format\n");
	else if (conditional == 2)
		printf("Invalid textures\n");
	free_memory(info, file);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_list	file;
	int		returnal;

	returnal = 0;
	file.content = NULL;
	if (argc != 2)
	{
		printf("Invalid amount of arguments\n");
		return (1);
	}
	initialize_info(&info);
	if ((parse(&info, argv, argc, &file)) != 0)
		error_manager(1, &info, &file);
	render_map(&info, &file);
}

void	initialize_info(t_info *info)
{
	ft_memset(info, 0, sizeof(info));
	info->mlx_int = NULL;
	info->screen = NULL;
	info->image = NULL;
	info->img_data = NULL;
	info->map = NULL;
	info->file = NULL;
	info->array_spaces = NULL;
	info->N_texture_path = NULL;
	info->S_texture_path = NULL;
	info->E_texture_path = NULL;
	info->W_texture_path = NULL;
	initialize_ray(info);
}

void	initialize_ray(t_info *info)
{
	info->pi = M_PI;
	info->one_rad = M_PI / 180;
	info->fov = 180;
	info->image = 0;
	info->ray_dir = 0;
	info->res_X = 1920;
	info->res_Y = 1080;
}
