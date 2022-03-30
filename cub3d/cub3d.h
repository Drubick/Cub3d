#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# define PI 3.141592
# define ESC_KEY			65307
# define ARROW_LEFT_KEY		65361
# define ARROW_RIGHT_KEY	65363

typedef struct s_info
{
    int x;
    int y;
    int char_position;
    int parse;
    char **map;
    char *file;
    t_list file_aux;
   // int error_code;
}       t_info;


//MAP FUNCTIONS
int map_scan(t_info *info);
int parse(t_info *info, char**argv, char argc);
int file_scan(t_list *file_aux, char *file, t_info *info)
#endif