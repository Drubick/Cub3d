#include "cub3d.h"

char		**ft_cut_map(char *map)
{
	char	**cut_map;	
	int	a;
	int	b;
	int	c;
	
	c = 0;
	b = 0;
	a = 0;
	cut_map = 0;
	while(map[a] != '\0')
	{
		if (map[a] == '\n' && map[a + 1] != '\0')
			b++;	
		a++;
	}
	b++;
	if(!(cut_map = (char**)malloc(sizeof(char*) * b)))
		return(0);
	a = 0;
	while(c != b)
	{
		if (map[a] == '\n' || map[a] == '\0')
		{
			cut_map[c] = ft_strldup(map, a - 1);
			map += a + 1;
			a = 0;
			c++;
		}
		a++;
	}
	return(cut_map);
}

char	*ft_strldup(const char *s, int i)
{
	char	*str;

	if (!(str = malloc(i + 2)))
		return (0);
	str[i + 1] = '\0';
	if (str != 0)
	{
		while (i >= 0)
		{
			str[i] = s[i];	
			i--;
		}
	}	
	return (str);
}

void	*canvas_f(t_info *info, char *img_data)
{
	int x;
	int y;

	y = info->resolution_Y/2;
	while (y < info->resolution_Y)
	{
		x = 0;
		while (x < (info->resolution_X * 4))
		{
			img_data[(y * info->resolution_X * 4) + x] = info->F_color[2];//blue
			x++;
			img_data[(y * info->resolution_X * 4) + x] = info->F_color[1];//green
			x++;
			img_data[(y * info->resolution_X * 4) + x] = info->F_color[0];//red
			x = x + 2;
		}
		y++;
	}
	return(0);
}

void	*canvas_c(t_info *info, char *img_data)
{
	int x;
	int y;

	y = 0;
	while (y < info->resolution_Y)
	{
		x = 0;
		while (x < (info->resolution_X * 4))
		{
			img_data[(y * info->resolution_X * 4) + x] = info->C_color[2];//blue
			x++;
			img_data[(y * info->resolution_X * 4) + x] = info->C_color[1];//green
			x++;
			img_data[(y * info->resolution_X * 4) + x] = info->C_color[0];//red
			x = x + 2;
		}
		y++;
	}
	return(0);
}

void	*wall(char *img_data, int R, int G, int B, int i, int j)
{
	int x;
	int y;

	x = 0;
	y = -1;
	while (++y < j)
	{
		x = 0;
		while (x < (i * 4))
		{
			img_data[y * (i * 4) + x] = B;//blue
			x++;
			img_data[y * (i * 4) + x] = G;//green
			x++;
			img_data[y * (i * 4) + x] = R;//red
			x++;
			img_data[y * (i * 4) + x] = 1;//T
			x++;
		}
	}
	return(0);
}