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
    if (argc != 2)
        info->parse = 1;
     file_scan(&file, argv[1], info);
    info->parse = arry_parse(info);
    return (info->parse);
}

//scans the file and saves it into a list
int file_scan(t_list **file_list, char *file, t_info *info)
{
    int     file_descriptor;
    int     control_line;
    char    *buffer;
    buffer = NULL;
    *file_list = NULL;
    file_descriptor = open(file, O_RDONLY);
    if (file_descriptor == -1)
        return (2);
    while (control_line != 0)
    {
        control_line = get_next_line(file_descriptor, &buffer);
        ft_lstadd_back(file_list, ft_lstnew(buffer));	    
    }
    info_to_array(info, *file_list);

    return (0);
}

void info_to_array(t_info *info, t_list *file_list)
{
    int	j;

	j = 0;
	info->file = ft_calloc(ft_lstsize(file_list) + 2, sizeof(char *));
	while (file_list)
	{
		info->file[j] = ((char *)file_list->content);
		file_list = file_list->next;
		j++;
	}
    j = 0;
    info_to_array_aux(info);
    fill_with_spaces(info);
}

void    get_longest_line(t_info *info)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (info->file[j])
    {
        while (info->file[j][i])
            i++;
        if (i > info->longest_line)
            info->longest_line = i;
        i = 0;
        j++;
    }
    info->file_last_line = j;
}

int    fill_with_spaces(t_info *info)
{
    int i;
    int j;

    i = 0;
    j = 0;
    get_longest_line(info);
    info->array_spaces = malloc((info->file_last_line) * sizeof(char *));
    while (j <= info->file_last_line)
    {
        info->array_spaces[j] = malloc((info->longest_line + 2) * sizeof(char));
        j++;
    }
    j = 0;
    while (info->file[j])
    {
            while (info->file[j][i])
            {
                info->array_spaces[j][i] = info->file[j][i];
                i++;
            }
            while (i < (info->longest_line))
            {
                if (i < 2)
                    info->array_spaces[j][i] = ' ';
                else
                {
                    info->array_spaces[j][i - 1] = ' ';
                }
                    i++;
            }
            info->array_spaces[j][i - 2] = '\n';
            info->array_spaces[j][i - 1] = '\0';
            printf("%s", info->file[j]);
            i = 0;
            j++;
    }
    info->array_spaces[j] = '\0';
    return (0);
}

void info_to_array_aux(t_info *info)
{

    int i;
    int j;

    i = 0;
    j = 0;
    while (info->file[j])
    {
       while (info->file[j][i])
            i++;
        info->file[j][i] = '\n';
        info->file[j][i + 1] = '\0';
        i = 0;
        j++;
    }
	info->file[j] = NULL;
}