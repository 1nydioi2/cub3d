/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jutocche <jutocche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:28:18 by jutocche          #+#    #+#             */
/*   Updated: 2025/11/13 19:36:54 by nilamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_WIDTH	1000
# define WIN_HEIGHT	1000

# define KEY_ESCAPE	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_UP		65362
# define KEY_DOWN	65364

# define PI 		3.14159265

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "mlx/mlx.h"
# include "externals.h"


typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		width;
	int		height;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_map
{
	int			present;
	int			line_start;
	int			line_end;
	int			is_delimited;
	int			height;
	char		**map;
}				t_map;

typedef struct	s_color
{
	int			present;
	int			line;
	int			index_rgb;
	char		**rgb_color;
	int			*value_color;
}				t_color;

typedef struct	s_texture
{
	int			present;
	int			line;
	int			index_path;
	char		*path_textures;
}				t_texture;

typedef struct	s_file
{
	int			fd;
	char		*filename;
	int			line_len;
	int			line_count;
	char		**cub_copy;
	int			total_elements;
}				t_file;

typedef	struct	s_plr
{
	float		plr_x;
	float		plr_y;
	float		plr_dx;
	float		plr_dy;
	float		plr_a;
}				t_plr;

typedef struct	s_data
{
	
	t_img	img_plr;
	t_img	img_eraser;
	t_img	img_wall;
	t_img	img_ground;
	t_img	img_line;
}				t_data;

typedef struct	s_cub
{
	t_data		_data
	t_file		file;
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_color		floor;
	t_color		ceiling;
	t_map		map;
	void		*mlx;
	void		*win;
}				t_cub;

// 0_cub3d.c
int				main(int argc, char **argv);

// 0_free_cub_and_close.c
void			free_cub_and_close(t_cub *cub);
void			free_cub_filename(t_cub *cub);
void free_cub_copy(t_cub *cub);
void free_textures_map(t_cub *cub);
void free_rgb_color_floor(t_cub *cub);
void free_rgb_color_ceiling(t_cub *cub);
void free_value_color(t_cub *cub);
void free_cub_map(t_cub *cub);
void cleanup_mlx(t_cub *cub);

// 1_is_name_file_correct.c
bool			is_name_file_correct(int argc, char *argv);
bool			is_file_argument(char *argv);
bool			is_number_argument_correct(int argc);
bool			is_file_extension_cub_correct(char *file);

// 2_first_opening_file.c
bool			first_opening_file(t_cub *cub, char *file);
bool			is_opening_file_possible(t_cub *cub);

// 3_is_cub_file_readable.c
bool			is_cub_file_readable(t_cub *cub);
int				line_len_and_line_count(t_cub *cub);
bool			is_line(t_cub *cub, char *line);
int				count_i(char *line);
bool			is_allocation_cub_copy_success(t_cub *cub);

// 4_fill_map.c
void			fill_cub_copy(t_cub *cub);
int				fill_cub_copy_utils(t_cub *cub, int i, int j, char *line);

// 5_is_data_cub_file_valid.c
bool			init_mlx(t_cub *cub);
bool			is_data_cub_file_valid(t_cub *cub);
void			init_integers_structs_texture_color_and_map(t_cub *cub);

// 6_is_all_elements_presents.c
bool			is_all_elements_presents(t_cub *cub);
int				check_all_elements(t_cub *cub, int i, int j, int result);
int				check_all_elements_utils(t_cub *cub, int i, int j);
int				is_end_of_line(t_cub *cub, int i, int j);

// 7_check_wall_textures.c
int				check_wall_textures(t_cub *cub, int i, int j);
int				check_north(t_cub *cub, int i, int j);
int				check_south(t_cub *cub, int i, int j);
int				check_west(t_cub *cub, int i, int j);
int				check_east(t_cub *cub, int i, int j);

// 8_check_floor_ceiling_and_map.c
int				check_floor_ceiling_and_map(t_cub *cub, int i, int j);
int				check_floor(t_cub *cub, int i, int j);
int				check_ceiling(t_cub *cub, int i, int j);
int				check_is_map(t_cub *cub, int i, int j);
int				is_invalid_element(t_cub *cub, int i, int j);

// 9_error_message_check.c
void			error_start_position(char c);
void			error_map_unclosed();
void			error_number_element(char *element);
void			error_invalid_element(void);
void			error_missing_map(t_cub *cub);

// 10_is_wall_textures_valid.c
bool			is_wall_textures_valid(t_cub *cub);

// 11_textures_north_valid.c
bool			textures_north_valid(t_cub *cub);
int				path_textures_north(t_cub *cub);
bool			is_file_extension_xpm_correct(char *line);
bool			is_path_readable_north(t_cub *cub);
bool			verify_textures_with_mlx(t_cub *cub, char *path, char *path_name);

// 12_textures_SO_valid.c
bool			textures_south_valid(t_cub *cub);
int				path_textures_south(t_cub *cub);
bool			is_path_readable_south(t_cub *cub);

// 13_textures_WE_valid.c
bool			textures_west_valid(t_cub *cub);
int				path_textures_west(t_cub *cub);
bool			is_path_readable_west(t_cub *cub);

// 14_textures_EA_valid.c
bool			textures_east_valid(t_cub *cub);
int				path_textures_east(t_cub *cub);
bool			is_path_readable_east(t_cub *cub);

// 15_error_message_textures.c
void			error_empty_path(char *path);
void			error_extension_path(char *path);
void			error_no_readable_path(char *path);

// 16_is_floor_or_ceiling_valid.c
bool			is_floor_or_ceiling_valid(t_cub *cub);
bool			is_rgb_floor_exist(t_cub *cub);
bool			is_rgb_settings_floor_valid(t_cub *cub);
bool			is_rgb_ceiling_exist(t_cub *cub);
bool			is_rgb_settings_ceiling_valid(t_cub *cub);

// 17_rgb_floor_split_and_atoi.c
int				split_and_atoi_rgb_floor(t_cub *cub);
int				split_cub_rgb_floor(t_cub *cub, char *rgb_setting);
int				count_color_rgb(char *rgb_setting);
char			*setting_to_color(char *setting, int *index);
int				atoi_color_rgb(char *str);

// 18_rgb_ceiling_split_and_atoi.c
int				split_and_atoi_rgb_ceiling(t_cub *cub);
int				split_cub_rgb_ceiling(t_cub *cub, char *rgb_setting);

// 19_error_message_rgb_color.c
void			error_number_colors(char *color);
void			error_setting_color_empty(char *color);
void			error_unreadable_color(char *color);
void			error_color_out_of_range(char *color);

// 20_is_map_valid.c
bool			is_map_valid(t_cub *cub);
bool			copy_map(t_cub *cub);
bool			is_correct_characters_in_map(t_cub *cub);

// 21_is_map_closed.c
bool			is_map_closed(t_cub *cub);
bool			check_space(t_cub *cub, int i, int j);
bool			is_character(char c);
bool			is_one_player_in_map(t_cub *cub);

// 22_error_message_map.c
void			error_wrong_character(char c);
void			error_count_player(int count);






// 40 
int start_cub(t_cub *cub);


#endif




