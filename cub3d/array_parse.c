#include "cub3d.h"
#include <unistd.h>

int arry_parse(t_info *info)
{
    int y;
    int no_longer_textures;

    y = 0;
    no_longer_textures = 0;
    while(info->file[y])
    {
        printf("%s",info->file[y]);
        if (no_longer_textures == 0)
        {
            if ((texture_check_save(info->file[y], y, info) == 1))
               y = y + 0;
        }           
        else if ((map_check(info->file, y, info)) == 0)
               // map_saving(y, info);
            //else
            return(1);
        y++;
    }
    return(0);
}

int texture_check_save(char *texture, int y, t_info *info)
{
    int returnal;
    returnal = 0;

    if (y == 0)
        returnal = texture_N(texture, info);
    else if (y == 1)
        returnal = texture_S(texture, info);
    else if (y == 2)
        returnal = texture_W(texture, info);
    else if (y == 3)
        returnal = texture_E(texture, info);
    else if (y == 4)
        returnal = texture_F(texture, info);
    else if (y == 5)
        returnal = texture_C(texture, info);

    return (returnal);
}

int texture_N(char *texture, t_info *info)
{
    int x;

    x = 0;
    if(texture[x++] != 'N' && texture[x++] != 'O' && texture[x++] != ' ')
        return(1);
    while(texture[x])
    {
        info->N_texture_path[x-3] = texture[x];
        x++;
    }
        texture[x] = '\0';

    return (0);
}

int texture_S(char* texture, t_info *info)
{

    printf("%s", texture);
    int x;

    x = 0;
    if(texture[x++] != 'S' && texture[x++] != 'O' && texture[x++] != ' ')
        return(1);
    while(texture[x])
    {
        info->S_texture_path[x-3] = texture[x];
        x++;
    }
        texture[x] = '\0';

    return (0);
}

int texture_W(char* texture, t_info *info)
{
    int x;

    x = 0;
    if(texture[x++] != 'W' && texture[x++] != 'O' && texture[x++] != ' ')
        return(1);
    while(texture[x])
    {
        info->E_texture_path[x-3] = texture[x];
        x++;
    }
        texture[x] = '\0';

    return (0);
}

int texture_E(char* texture, t_info *info)
{
    int x;

    x = 0;
    if(texture[x++] != 'E' && texture[x++] != 'O' && texture[x++] != ' ')
        return(1);
    while(texture[x])
    {
        info->E_texture_path[x-3] = texture[x];
        x++;
    }
    texture[x] = '\0';
    return (0);
}


//revisar dependiendo como se usa el color
int texture_F(char* texture, t_info *info)
{
    int x;

    x = 0;
    if(texture[x++] != 'F' && texture[x++] != ' ')
        return(1);
    while(texture[x])
    {
        info->F_color[x-2] = texture[x];
        x++;
    }
        texture[x] = '\0';

    return (0);
}

//revisar dependiendo como se usa el color
int texture_C(char* texture, t_info *info)
{
    int x;

    x = 0;
    if(texture[x++] != 'C' && texture[x++] != ' ')
        return(1);
    while(texture[x])
    {
        info->C_color[x-2] = texture[x];
        x++;
    }
        texture[x] = '\0';

    return (2);
}