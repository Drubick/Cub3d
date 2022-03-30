
#include "cub3d.h"

void    error_manager(int conditional)
{
    conditional++;
}


int main(int argc, char **argv)
{
    t_info info;

    if((parse(&info, argv, argc)) != 0)
        error_manager(info.parse);
}