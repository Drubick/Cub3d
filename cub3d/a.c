void    get_longest_line(t_info *info)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while(info->file[j][i])
    {
        while(info->file[j][i])
            i++;
        if (i > info->longest_line)
            info->longest_line = i;
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


    info->array_spaces = malloc((info->file_last_line + 1) * sizeof(char *));
    while(j < info->file_last_line)
    {
        info->array_spaces[j] = malloc((info->longest_line + 2) * sizeof(char));
        j++;
    }
    while(info->file[j][i])
    {
        printf("a\n");
        while(info->file[j][i])
        {
            info->array_spaces[j][i] = info->file[j][i];
            printf("b\n");
            while(i < info->longest_line)
            {
                info->array_spaces[j][i - 2] = ' ';
                i++;
            }
            printf("%s", info->array_spaces[j]);
            i++;
        }
        i = 0;
        j++;
    }
    return(1);
}

void info_to_array_aux(t_info *info)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(info->file[j])
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
