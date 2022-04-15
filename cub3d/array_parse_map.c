#include "cub3d.h"
#include <unistd.h>

int map_check(char **map, int y, t_info *info)
{
    int x;
    int error;
    x = 0;
    error = 0;
    info->file_map_first_line = y;
    while(map[y][x])
    {
        while(map[y][x])
        {
            if(y == info->file_last_line || y == info->file_map_first_line)
                if(map[y][x] != '1' || map[y][x] != ' ')
                    return(1);
            if(map[y][x] != 'N' || map[y][x] != 'S' || map[y][x] != 'E' || map[y][x] != 'W' ||
                map[y][x] != '0' || map[y][x] != '1' || map[y][x] != ' ')
                    return(1);
            else
            {
                if (map[y][x] == '0')
                    error = map_check_0(map, y, x);
                else if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
                    error = map_check_player(map, y, x, info);
                else if (map[y][x] == ' ')
                    error = map_check_space(map, y, x);
            }
            x++;
        }
        x = 0;
        y++;
    }
    return (error);
}

int map_check_0(char **map, int y, int x)
{
    if(map[y -1][x] == ' ' || map[y + 1][x] == ' ' || map[y][x + 1] == ' ' || map[y][x - 1] == ' ' ||
        map[y -1][x] == '\n' || map[y + 1][x] == '\n' || map[y][x + 1] == '\n' || map[y][x - 1] == '\n')

        return(1);
    else
        return(0);
    
}
int map_check_player(char **map, int y, int x, t_info *info)
{
    info->player_position_x = x;
    info->player_position_y = y;
    info->player_direction = map[x][y];
    map[x][y] = '0';

     if(map[y -1][x] == ' ' || map[y + 1][x] == ' ' || map[y][x + 1] == ' ' || map[y][x - 1] == ' ' ||
         map[y -1][x] == '\n' || map[y + 1][x] == '\n' || map[y][x + 1] == '\n' || map[y][x - 1] == '\n')
        return(1);
    else
        return(0);
}

int map_check_space(char **map, int y, int x)
{
    if(map[y -1][x] != ' ' || map[y + 1][x] != ' ' || map[y][x + 1] != ' ' || map[y][x - 1] != ' '||
        map[y -1][x] != '1' || map[y + 1][x] != '1' || map[y][x + 1] != '1' || map[y][x - 1] != '1')
        return(1);
    else
        return(0);  
}
