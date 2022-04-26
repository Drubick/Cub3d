#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
#include <math.h>
#include <unistd.h>
#include <stdio.h>
//#include <mlx.h>
#include <stdio.h>
# define PI 3.141592
# define ESC_KEY			65307
# define ARROW_LEFT_KEY		65361
# define ARROW_RIGHT_KEY	65363

typedef struct s_info
{
	//ray casting
	double	pi;
	double 	one_rad;
	double	ray_dir;
	int		fov;
	//mlx
	void	*mlx_int;
	void	*screen;
	void	*image;
	int		key_a;
	int		key_s;
	int		key_d;
	int		key_w;
	int		key_esc;
	char	*img_data;
	int		x;
	int		y;
	//player
	int 	player_position_x;
	int 	player_position_y;
	char	player_direction;
	int		parse;
	//map
	int		longest_line;
	char	**map;
	char	**file;
	char	**array_spaces;
	t_list file_aux;
	int file_last_line;
	int file_map_first_line;
	//textures
	char *N_texture_path;
	char *S_texture_path;
	char *E_texture_path;
	char *W_texture_path;
	char *F_color;
	char *C_color;
}       t_info;


//MAP FUNCTIONS
int 	map_scan(t_info *info);
int 	parse(t_info *info, char**argv, char argc);
int 	file_scan(t_list **file_list, char *file, t_info *info);
void 	info_to_array(t_info *info, t_list *file_list);
void	info_to_array_aux(t_info *info);
int     fill_with_spaces(t_info *info);
void    get_longest_line(t_info *info);
void    map_saving(int y, t_info *info);
//checks if the file is good
int 	arry_parse(t_info *info);
//checks textures
int 	texture_check_save(char *texture, int y, t_info *info);
int 	texture_S(char* texture, t_info *info);
int 	texture_N(char* texture, t_info *info);
int 	texture_W(char* texture, t_info *info);
int 	texture_E(char* texture, t_info *info);
int 	texture_F(char* texture, t_info *info);
int 	texture_C(char* texture, t_info *info);

//checks the map
int 	map_check(int y, t_info *info);
int 	map_check_0( t_info *info, int y, int x);
int 	map_check_player(int y, int x, t_info *info);
int 	map_check_space( t_info *info, int y, int x);
//memory
void	initialize_info(t_info *info);
void    initialize_textures(t_info *info);
void    initialize_ray(t_info *info);

//ray casting
void	*canvas(char *img_data, int R, int G, int B, int i, int j);
void	*wall(char *img_data, int R, int G, int B, int i, int j);
void	draw_wall(double nbr_ray, double dist, t_info *info);
int		deal_key_press(int key, t_info *info);
int		deal_key_release(int key, t_info *info);
int		deal_keys(int key, t_info *info);
char	**ft_cut_map(char *map);
char	*ft_strldup(const char *s, int i);
int		drawray_3D(t_info *info);
int		calc_dist(double ray_x, double ray_y, t_info *info);
int		draw_vertical(t_info *info, int x, int dist);
int		create_img(t_info *info);
int		draw_pixel(char *img_addr, int r, int g, int b);


#endif