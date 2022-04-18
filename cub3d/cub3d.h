#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
#include <stdio.h>
# define PI 3.141592
# define ESC_KEY			65307
# define ARROW_LEFT_KEY		65361
# define ARROW_RIGHT_KEY	65363

typedef struct s_info
{
    int x;
    int y;
    //player
    int player_position_x;
    int player_position_y;
    char player_direction;
    int parse;
    //map
    int longest_line;
    char **map;
    char **file;
    char **array_spaces;
    t_list file_aux;
    int file_last_line;
    int file_map_first_line;
//textures
    char *N_texture_path;
    char *S_texture_path;
    char *E_texture_path;
    char *W_texture_path;
    char *F_color;
    char *C_color;
}       t_info;


//MAP FUNCTIONS
int map_scan(t_info *info);
int parse(t_info *info, char**argv, char argc);
int file_scan(t_list **file_list, char *file, t_info *info);
void info_to_array(t_info *info, t_list *file_list);
void info_to_array_aux(t_info *info);
int     fill_with_spaces(t_info *info);
void    get_longest_line(t_info *info);
//checks if the file is good
int arry_parse(t_info *info);
//checks textures
int texture_check_save(char *texture, int y, t_info *info);
int texture_S(char* texture, t_info *info);
int texture_N(char* texture, t_info *info);
int texture_W(char* texture, t_info *info);
int texture_E(char* texture, t_info *info);
int texture_F(char* texture, t_info *info);
int texture_C(char* texture, t_info *info);
//checks the map
int map_check(char **map, int y, t_info *info);
int map_check_0(char **map, int y, int x);
int map_check_player(char **map, int y, int x, t_info *info);
int map_check_space(char **map, int y, int x);
//memory
void    initialize_textures(t_info *info);


#endif