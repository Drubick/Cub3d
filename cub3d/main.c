
#include "cub3d.h"

void	error_manager(int conditional, t_info *info)
{
	if (conditional)
		printf("Invalid map format\n");
	free_memory(info);
	exit (1);
}

void	render_map(t_info *info)
{
	int	screen_w;
	int	screen_h;

	screen_w = info->resolution_X * 32;
	screen_h = info->resolution_Y * 32;
	info->mlx_int = mlx_init();
	info->screen = mlx_new_window(info->mlx_int, screen_w,
			screen_h, "so_long");
	if (!load_images(info))
		error_manager(2, info);
	listen_events(info);
	mlx_loop(info->mlx_int);
}

void	listen_events(t_info *info)
{
	mlx_key_hook(info->screen, *deal_keys, info);
	mlx_hook(info->screen, 17, (1L << 8), close_window, info);
}

int	close_window(t_info *info)
{
	mlx_destroy_image(info->mlx_int, info->E_texture_path);
	mlx_destroy_image(info->mlx_int, info->N_texture_path);
	mlx_destroy_image(info->mlx_int, info->S_texture_path);
	mlx_destroy_image(info->mlx_int, info->W_texture_path);
	mlx_destroy_window(info->mlx_int, info->screen);
	free_memory(info);
	exit(0);
	return (0);
}


int	main(int argc, char **argv)
{
	t_info	info;
	int		returnal;

	returnal = 0;
	if (argc != 2)
	{
		printf("Invalid amount of arguments\n");
		return (1);
	}


	initialize_info(&info);
	if ((parse(&info, argv, argc)) != 0)
		error_manager(1, &info);
	render_map(&info);

	return(returnal);
	/*		
	info.F_color[0] = 220;
	info.F_color[1] = 100;
	info.F_color[2] = 0;
	info.F_color[3] = '\0';
	info.C_color[0] = 0;
	info.C_color[1] = 30;
	info.C_color[2] = 225;
	info.C_color[3] = '\0';
	info.mlx_int = mlx_init();
	info.screen = mlx_new_window(info.mlx_int, info.resolution_X,
			info.resolution_Y, "screen");
	
	
	
	mlx_hook(info.screen, 2, 1L << 0, deal_keys, &info);
	mlx_loop(info.mlx_int);
	*/
}

void	initialize_info(t_info *info)
{
	ft_memset(info, 0, sizeof(info));
	initialize_ray(info);
}

void	initialize_ray(t_info *info)
{
	info->pi = M_PI;
	info->one_rad = M_PI / 180;
	info->fov = 180;
	info->image = 0;
	info->ray_dir = 0;
	info->resolution_X = 1920;
	info->resolution_Y = 1080;
}
