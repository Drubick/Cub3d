#include "cub3d.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*
error code 1 = wrong number of files while starting the program
//error code 2 = file cant be oppened
//error code 3 = wrong file format
*/
void	valid_map_file(char const *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (i < 5)
		return(1);
	if (ft_strncmp(&(argv[i - 4]), ".ber", 4))
		return(1);
}

int	parse(t_info *info, char**argv, char argc)
{
	t_list	*file;

	if (argc != 2)
		info->parse = 1;
	if (valid_map_file(argv))
		return(1);
	file_scan(&file, argv[1], info);
	info->parse = arry_parse(info);
	return (info->parse);
}
/*
//scans the file and saves it into a list
*/

int	file_scan(t_list **file_list, char *file, t_info *info)
{
	int		file_descriptor;
	int		control_line;
	char	*buffer;

	buffer = NULL;
	*file_list = NULL;
	control_line = 12;
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

void	info_to_array(t_info *info, t_list *file_list)
{
	int	j;
	int	i;

	j = 0;
	info->file = ft_calloc(ft_lstsize(file_list) + 1, sizeof(char *));
	while (file_list)
	{
		info->file[j] = ft_calloc(ft_strlen(file_list->content)
				+ 2, sizeof(char));
		i = 0;
		while (((char *)file_list->content)[i])
		{
			info->file[j][i] = ((char *)file_list->content)[i];
			i++;
		}
		info->file[j][i] = '\n';
		file_list = file_list->next;
		j++;
	}
	fill_with_spaces(info);
}
