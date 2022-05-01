
#include "cub3d.h"

void    error_manager(int conditional)
{
    conditional++;
}


int main(int argc, char **argv)
{
    t_info info;
    initialize_info(&info);

    if((parse(&info, argv, argc)) != 0)
        error_manager(info.parse);
    //A cambiar
    
	info.F_color[0] = 220;
	info.F_color[1] = 100;
	info.F_color[2] = 0;
	info.F_color[3] = '\0';

	info.C_color[0] = 0;
	info.C_color[1] = 30;
	info.C_color[2] = 225;
	info.C_color[3] = '\0';
	info.mlx_int = mlx_init();
	info.screen = mlx_new_window(info.mlx_int, info.resolution_X, info.resolution_Y, "screen");
	//move(&info);
	mlx_hook(info.screen, 2, 1L<<0, deal_keys, &info);
	mlx_loop(info.mlx_int);
	
}

void	initialize_info(t_info *info)
{
	ft_memset(info, 0, sizeof(info));
	//initialize_textures(info);
	initialize_ray(info);
}


 void	initialize_ray(t_info *info)
 {
	info->player_position_x = 39.3;
	info->player_position_y = 4;
	info->pi = M_PI;
	info->one_rad = M_PI / 180;
	info->fov = 180;
	info->image = 0;
	info->ray_dir = 0;
	info->resolution_X = 1920;
	info->resolution_Y = 1080;
 }