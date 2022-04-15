
#include "cub3d.h"

void    error_manager(int conditional)
{
    conditional++;
}


int main(int argc, char **argv)
{
    t_info info;

    ft_memset(&info, 0, sizeof(info));
    initialize_textures(&info);
    if((parse(&info, argv, argc)) != 0)
        error_manager(info.parse);\
    printf("%s ", info.N_texture_path);
  //      printf("%s", info.E_texture_path);

  //  printf("%s", info.S_texture_path);

// printf("%s", info.W_texture_path);

    //printf("%s", info.F_color);
       // printf("%s", info.C_color);

}

void initialize_textures(t_info *info)
 {
    info->N_texture_path = ft_calloc(100, sizeof(char *));
    info->S_texture_path = ft_calloc(100, sizeof(char *));
    info->E_texture_path = ft_calloc(100, sizeof(char *));
    info->W_texture_path = ft_calloc(100, sizeof(char *));
    info->F_color = ft_calloc(100, sizeof(char *));
    info->C_color = ft_calloc(100, sizeof(char *));
 }