#include "cub3d.h"
#include <unistd.h>

int map_check(int y, t_info *info)
{
    int x;
    int error;
    x = 0;
    error = 0;
    y += 1;
    info->file_map_first_line = y;
    //info->file_last_line--;
    while(info->array_spaces[y] && y<= info->file_last_line)
    {
        while(info->array_spaces[y][x])
        {
           // printf("%c", info->array_spaces[y][x]);
            if(y == info->file_last_line || y == info->file_map_first_line)
            {
                if(info->array_spaces[y][x] != '1' && info->array_spaces[y][x] != ' ' && info->array_spaces[y][x] != '\n') 
                    return(1);
            }
            else if(info->array_spaces[y][x] != 'N' && info->array_spaces[y][x] != 'S' && info->array_spaces[y][x] != 'E' && info->array_spaces[y][x] != 'W' &&
                info->array_spaces[y][x] != '0' && info->array_spaces[y][x] != '1' && info->array_spaces[y][x] != ' ' && info->array_spaces[y][x] != '\n')
                    return(1);
            else if(info->array_spaces[y][x] != '\n' && y != info->file_last_line && error == 0 && y != info->file_map_first_line)
            {
                if (info->array_spaces[y][x] == '0')
                    error = map_check_0(info, y, x);
                else if (info->array_spaces[y][x] == 'N' || info->array_spaces[y][x] == 'S' || info->array_spaces[y][x] == 'E' || info->array_spaces[y][x] == 'W')
                    error = map_check_player(y, x, info);
                else if (info->array_spaces[y][x] == ' ')
                    error = map_check_space(info, y, x);
            }
            x++;
        }
        x = 0;
        y++;
    }
    printf("el error es = %i\n", error);
    return (error);
}

int map_check_0( t_info *info, int y, int x)
{
     return(0);
    if(info->array_spaces[y -1][x] == ' ' || info->array_spaces[y + 1][x] == ' ' || info->array_spaces[y][x + 1] == ' ' || info->array_spaces[y][x - 1] == ' ' ||
        info->array_spaces[y -1][x] == '\n' || info->array_spaces[y + 1][x] == '\n' || info->array_spaces[y][x + 1] == '\n' || info->array_spaces[y][x - 1] == '\n')

        return(1);
    else
        return(0);
    
}
int map_check_player(int y, int x, t_info *info)
{
    info->player_position_x = x;
    info->player_position_y = y;
    info->player_direction = info->array_spaces[y][x];
    info->array_spaces[y][x] = '0';

     if(info->array_spaces[y -1][x] == ' ' || info->array_spaces[y + 1][x] == ' ' || info->array_spaces[y][x + 1] == ' ' || info->array_spaces[y][x - 1] == ' ' ||
         info->array_spaces[y -1][x] == '\n' || info->array_spaces[y + 1][x] == '\n' || info->array_spaces[y][x + 1] == '\n' || info->array_spaces[y][x - 1] == '\n')
        return(1);
    else
        return(0);
}

int map_check_space( t_info *info, int y, int x)
{
   // printf("3\n");
    if(x == 0)
        return(0);
    if(y == (info->file_last_line - 1) )
        return(0);
    if(!ft_strchr(" 1\n", info->array_spaces[y -1][x])||
     !ft_strchr(" 1\n", info->array_spaces[y + 1][x]) ||
      !ft_strchr(" 1\n", info->array_spaces[y][x + 1]) || 
         !ft_strchr(" 1\n", info->array_spaces[y][x - 1]))
        return(1);
    else
        return(0);  
}

void    map_saving(int y, t_info *info)
{
    int j;
    int i;

    i = 0;
    j = 0;

    info->map = malloc((info->file_last_line - y) * sizeof(char *));
    while(j < (info->file_last_line - y - 1))
    {
        info->map[j] = malloc((info->longest_line + 2) * sizeof(char));
        j++;
    }
    info->map[j] = '\0';
    j = 0;
    while(info->file[j + y + 1])
    {
        while(info->array_spaces[j + y][i])
        {
            info->map[j][i] = info->array_spaces[j + y + 1][i];
            i++;
        }
        printf("%s", info->map[j]);
        i = 0;
        j++;
    }
}