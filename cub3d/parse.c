#include "cub3d.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


//error code 1 = wrong number of files while starting the program
//error code 2 = file cant be oppened
//error code 3 = wrong file format
int parse(t_info *info, char**argv, char argc)
{
    t_list *file;
    if(argc != 2)
        info->parse = 1;
     file_scan(&file, argv[1], info);


    info->parse = arry_parse(info);
        return(info->parse);
}

//scans the file and saves it into a list
int file_scan(t_list **file_list, char *file, t_info *info)
{
    int     file_descriptor;
    int     control_line;
    char    *buffer;
    //char     jump[1];
    //jump[0] ='\n';
    buffer = NULL;
    *file_list = NULL;

    file_descriptor = open(file, O_RDONLY);
    if (file_descriptor == -1)
        return(2);
    control_line = get_next_line(file_descriptor, &buffer);
    while(control_line == 1)
    {
        ft_lstadd_back(file_list, ft_lstnew(buffer));
       // ft_lstadd_back(file_list, ft_lstnew(jump));
        control_line = get_next_line(file_descriptor, &buffer);
	    
    }
    info_to_array(info, *file_list);

    return(0);
}
//PORQUE PASAA ESTOOO
//transforms
void info_to_array(t_info *info, t_list *file_list)
{
    int	j;
  int i;

	j = 0;
	info->file = ft_calloc(ft_lstsize(file_list) + 1, sizeof(char *));
	while (file_list)
	{
		info->file[j] = ((char *)file_list->content);
		file_list = file_list->next;
		j++;
	}
    j = 0;
    i = 0;
    while(info->file[j])
    {
        while (info->file[j][i])
        {
            i++;
     
           
        }
               info->file[j][i] = '\n';
         printf("%s", info->file[j]);
        i = 0;
        j++;
    }
    
    
	info->file[j] = NULL;
}

