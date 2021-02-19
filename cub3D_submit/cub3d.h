/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jae-kim <jae-kim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:44:53 by jae-kim           #+#    #+#             */
/*   Updated: 2021/02/19 15:25:37 by jae-kim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

# include "mlx/mlx.h"
# include "key_macros.h"
# include "libft/libft.h"

# include <math.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>

# define X_EVENT_KEY_PRESS    2
# define X_EVENT_KEY_RELEASE  3
# define X_EVENT_KEY_EXIT    17

# define MAX_WIDTH 2880
# define MAX_HEIGHT 1440
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define TILE_SIZE 5

extern int			g_width;
extern int			g_height;

typedef struct		s_input_opt
{
	int				resolution[2];
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*spr;
	int				floor[3];
	int				ceil[3];
	int				count_map_height;
	int				count_map_width;
	char			*map_str;
	int				count_sprite;
}					t_input_opt;

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				img_width;
	int				img_height;
}					t_img;

typedef struct		s_info
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	void			*mlx;
	void			*win;
	int				key_a;
	int				key_w;
	int				key_s;
	int				key_d;
	int				key_ar_l;
	int				key_ar_r;
	int				key_esc;
	t_img			img;
	int				**buf;
	int				**texture;
	double			move_speed;
	double			rot_speed;
	int				**map;
	int				map_height;
	int				map_width;
	char			*south_tex;
	char			*north_tex;
	char			*west_tex;
	char			*east_tex;
	char			*spr_tex;
	int				floor_rgb;
	int				ceil_rgb;
	double			*z_buffer;
	int				num_sprites;
}					t_info;

typedef struct		s_ray
{
	float			ray_dir_x0;
	float			ray_dir_y0;
	float			ray_dir_x1;
	float			ray_dir_y1;
}					t_ray;

typedef struct		s_wall_ray
{
	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				hit;
	int				side;
	int				front;
	int				right;
	int				step_x;
	int				step_y;
	int				map_x;
	int				map_y;
	double			perp_wall_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_num;
	double			wall_x;
	double			step;
}					t_wall_ray;

typedef struct		s_pair
{
	double			first;
	int				second;
}					t_pair;

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				texture;
}					t_sprite;

typedef struct		s_sprite_ray
{
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				v_move_screen;
	int				sprite_height;
	int				draw_start_y;
	int				draw_end_y;
	int				sprite_width;
	int				draw_start_x;
	int				draw_end_x;
}					t_sprite_ray;

# pragma pack(push, 1)

typedef struct		s_bitmapfileheader
{
	unsigned char	bf_type1;
	unsigned char	bf_type2;
	unsigned int	bf_size;
	unsigned short	bf_reserved1;
	unsigned short	bf_reserved2;
	unsigned int	bf_off_bits;
}					t_bitmapfileheader;

typedef struct		s_bitmapinfoheader
{
	unsigned int	bi_size;
	int				bi_width;
	int				bi_height;
	unsigned short	bi_planes;
	unsigned short	bi_bit_count;
	unsigned int	bi_compression;
	unsigned int	bi_size_image;
	int				bi_x_pels_per_meter;
	int				bi_y_pels_per_meter;
	unsigned int	bi_cir_used;
	unsigned int	bi_cir_important;
}					t_bitmapinfoheader;

# pragma pack(pop)

struct s_sprite		*g_sprite;

void				cub_init(t_info *info, char *input_file);
void				get_map(t_input_opt *option, char *input_file);
void				set_map(t_info *info, t_input_opt *option, char**ptr);
void				draw_minimap(t_info *info);
void				draw_line(t_info *info, double *x, double *y);
void				floor_casting(t_info *info);
void				wall_casting(t_info *info);
void				set_wall_distance(t_wall_ray *w_ray, t_info *info);
void				dda_algorithm(t_wall_ray *w_ray, t_info *info);
void				screen_casting(t_info *info);
void				sprite_casting(t_info *info);
void				sort_order(t_pair *orders, int amount);
void				sort_sprites(int *order, double *dist, int amount);
void				load_texture(t_info *info);
void				key_update_1(t_info *info);
void				key_update_2(t_info *info);
void				key_update_3(t_info *info);
int					key_press(int key, t_info *info);
int					key_release(int key, t_info *info);
int					close_window(t_info *info);
void				save_bmp(t_info *info);
void				screen_shot(t_info *info);
int					get_next_line(int fd, char **line);
void				array_free(int **two_di_array, int idx);
void				fence_error_check(t_info info, t_input_opt option);
void				map_content_error(void);
void				input_error_check(int argc);
void				parcing_error(void);
void				input_error(void);
void				input_color_error_check(char **ptr);
void				input_view_error_check(char **ptr);
void				option_error_check(t_input_opt *option);

#endif
