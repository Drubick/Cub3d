
#include "cub3d.h"

void	error_manager(int conditional, t_info *info, t_list *file)
{
	if (conditional)
		printf("Invalid map format\n");
	free_memory(info, file);
	exit (1);
}

void	render_map(t_info *info, t_list *file)
{
	int	screen_w;
	int	screen_h;

	screen_w = info->resolution_X * 32;
	screen_h = info->resolution_Y * 32;
	info->mlx_int = mlx_init();
	info->screen = mlx_new_window(info->mlx_int, info->resolution_X,
			info->resolution_Y, "screen");
	if (!load_images(info))
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
	mlx_destroy_image(info->mlx_int, info->images_E.image);
	mlx_destroy_image(info->mlx_int, info->images_N.image);
	mlx_destroy_image(info->mlx_int, info->images_S.image);
	mlx_destroy_image(info->mlx_int, info->images_W.image);
	mlx_destroy_window(info->mlx_int, info->screen);
	free_memory(info, file);
	exit(0);
	return (0);
}

void	leaks()
{
	system("leaks cub_3d");
}

int	main(int argc, char **argv)
{
	atexit(leaks);
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
	info->resolution_X = 1920;
	info->resolution_Y = 1080;
}
