#include "cub3d.h"

void	get_longest_line(t_info *info)
{
	int	i;
	int	j;

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

int	fill_with_spaces(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	get_longest_line(info);
	info->array_spaces = malloc((info->file_last_line + 1) * sizeof(char *));
	while (j <= info->file_last_line)
	{
		info->array_spaces[j] = malloc((info->longest_line + 2) * sizeof(char));
		j++;
	}
	j = 0;
	while (info->file[j])
	{
		fill_with_spaces_aux(info, &i, &j);
		i = 0;
		j++;
	}
	info->array_spaces[j] = NULL;
	return (0);
}

void	fill_with_spaces_aux(t_info *info, int *i, int *j)
{
	while (info->file[*j][*i])
	{
		info->array_spaces[*j][*i] = info->file[*j][*i];
		*i += 1;
	}
	while (*i < (info->longest_line))
	{
		if (*i < 2)
			info->array_spaces[*j][*i] = ' ';
		else
		{
			info->array_spaces[*j][*i - 1] = ' ';
		}
			*i += 1;
	}
	info->array_spaces[*j][*i - 2] = '\n';
	info->array_spaces[*j][*i - 1] = '\0';
}

void	info_to_array_aux(t_info *info)
{
	int	i;
	int	j;

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
}
