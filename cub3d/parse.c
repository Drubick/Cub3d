#include "cub3d.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


//error code 1 = wrong number of files while starting the program
//error code 2 = file cant be oppened
//error code 3 = wrong file format
int parse(t_info *info, char**argv, char argc)
{
    t_list file;
    if(argc != 2)
        info->parse = 1;
    info->parse = file_scan(&file, argv[1], info);

    return(info->parse);
}


int file_scan(t_list *file_list, char *file, t_info *info)
{
    int     file_descriptor;
    int     control_line;
    char    *buffer;
    int     i;

    i = 5;
    file_descriptor = open(file, O_RDONLY);
    if (file_descriptor == -1)
        return(2);
    control_line = get_next_line(file_descriptor, &buffer);
    while(control_line == 1)
    {
        control_line = get_next_line(file_descriptor, &buffer);
	    ft_lstadd_back(file_list, ft_lstnew(buffer));
    }
    info_to_array(info, file_list);

    return(0);
}

void info_to_array(t_info *info, t_list *file_list)
{
    	int	j;

	j = 0;
	info->file = ft_calloc(ft_lstsize(file_list) + 1, sizeof(char *));
	while (file_list)
	{
		info->file[j] = ((char *)file_list->content);
		file_list = file_list->next;
		j++;
	}
	info->file[j] = NULL;
}
