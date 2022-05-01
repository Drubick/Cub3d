#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
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
	int		R;
	int		G;
	int		B;
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
	int		resolution_X;
	int		resolution_Y;
	//player
	double 	player_position_x;
	double 	player_position_y;
	char	player_direction_char;
	double	player_direction;
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
	int F_color[4];
	int C_color[4];
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
void	fill_with_spaces_aux(t_info *info, int *i, int *j);
//checks if the file is good
int 	arry_parse(t_info *info);
//checks textures
int 	texture_check_save(char *texture, int y, t_info *info);
int 	texture_s(char* texture, t_info *info);
int 	texture_n(char* texture, t_info *info);
int 	texture_w(char* texture, t_info *info);
int 	texture_e(char* texture, t_info *info);
int 	texture_f(char* texture, t_info *info);
int 	texture_c(char* texture, t_info *info);

//checks the map
int 	map_check(int y, t_info *info);
int 	map_check_0( t_info *info, int y, int x);
int 	map_check_player(int y, int x, t_info *info);
int 	map_check_space( t_info *info, int y, int x);
int		map_check_aux(t_info *info, int y, int x, int error);
void    transform_direction_radian(char direction, t_info *info);
//memory
void	initialize_info(t_info *info);
void    initialize_textures(t_info *info);
void    initialize_ray(t_info *info);

//ray casting
void	*canvas_c(t_info *info, char *img_data);
void	*canvas_f(t_info *info, char *img_data);
void	*wall(char *img_data, int R, int G, int B, int i, int j);
void	draw_wall(double nbr_ray, double dist, t_info *info);
int		deal_key_press(int key, t_info *info);
int		deal_key_release(int key, t_info *info);
int		deal_keys(int key, t_info *info);
char	**ft_cut_map(char *map);
char	*ft_strldup(const char *s, int i);
int		drawray_3d(t_info *info);
int		calc_dist(double ray_x, double ray_y, t_info *info);
int		draw_vertical(t_info *info, int x, int dist);
int		create_img(t_info *info);
int		draw_pixel(char *img_addr, int r, int g, int b);
void 	rgb_set_vertical(t_info *info);
void 	rgb_set_horizontal(t_info *info);
int 	vertical_coll(t_info *info);
int 	horizontal_coll(t_info *info);
void    deal_key_13(t_info *info);
void    deal_key_1(t_info *info);
void	horizontal_coll_aux(t_info *info, double *ray_x, double *ray_y);
void	vertical_coll_aux(t_info *info, double *ray_x, double *ray_y);
#endif