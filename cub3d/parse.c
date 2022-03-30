#include "cub3d.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


//error code 1 = wrong number of files while starting the program
//error code 2 = file cant be oppened
//error code 3 = wrong file format
int parse(t_info *info, char**argv, char argc)
{
    if(argc != 2)
        info->parse = 1;
    else if ((info->parse = file_scan(info, argv[1]) != 0));

    return(info->parse);
}


int file_scan(t_info *info, char *file)
{
    int     file_descriptor;
    int     control_line;
    char    *buffer;

    file_descriptor = open(file, O_RDONLY);
    if (file_descriptor == -1)
        return(2);
    control_line = get_next_line(file_descriptor, &buffer);
    
    

}
int map_scan(t_info *info)
{

}