
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
    /*
	info.mlx_int = mlx_init();
	info.screen = mlx_new_window(info.mlx_int, resolution_X, resolution_Y, "screen");
	//move(&info);
	info.map = ft_cut_map(
	   "111111111\n111111111\n11010000011\n11000000011\n11001100011\n11000000011\n11000000011\n11000000011\n111111111\n111111111");
	mlx_hook(info.screen, 2, 1L<<0, deal_keys, &info);
	//mlx_hook(info.screen, 3, 1L<<1, deal_key_release, &info);
	//mlx_loop_hook(info.mlx_int, drawray_3D, &info);
	mlx_loop(info.mlx_int);*/
    
}

void	initialize_info(t_info *info)
{
	ft_memset(info, 0, sizeof(info));
	initialize_textures(info);
	initialize_ray(info);
}

void	initialize_textures(t_info *info)
 {
    info->N_texture_path = ft_calloc(100, sizeof(char *));
    info->S_texture_path = ft_calloc(100, sizeof(char *));
    info->E_texture_path = ft_calloc(100, sizeof(char *));
    info->W_texture_path = ft_calloc(100, sizeof(char *));
    info->F_color = ft_calloc(100, sizeof(char *));
    info->C_color = ft_calloc(100, sizeof(char *));
 }

 void	initialize_ray(t_info *info)
 {
	info->player_position_x = 4;
	info->player_position_y = 4;
	info->pi = M_PI;
	info->one_rad = M_PI / 180;
	info->fov = 100;
	info->image = 0;
	info->ray_dir = 0;
 }