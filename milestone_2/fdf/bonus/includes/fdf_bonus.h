/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:34:50 by candriam          #+#    #+#             */
/*   Updated: 2024/07/31 13:11:06 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# define TITLE "FdF_BONUS"
# define WIN_WIDTH 920.0
# define WIDTH 950.0
# define WIN_HEIGHT 680.0
# define HEIGHT 710.0
# define MAX_ZOOM 42
# define MIN_ZOOM 4.2
# define ALTITUDE_STEP 0.1
# define ZOOM_FACTOR 1.05
# define DEFAULT_HEIGHT_FACTOR 1.0
# define DEFAULT_ANGLE_X 0.523599
# define DEFAULT_ANGLE_Y 0.523599
# define TRANS_FACTOR_X 1
# define TRANS_FACTOR_Y 1
# define ROT 0.01
# define LONG 1
# define LAT 0
# define MARGIN 100
# define READ 500000
# define SIZED 1

# define ESC 65307
# define CTRL_L 65507
# define CTRL_R 65508
# define SHIFT_L 65505
# define SHIFT_R 65506

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define K_SUM 65451
# define K_MIN 65453

# define K_A 97
# define K_B 98
# define K_C 99
# define K_D 100
# define K_E 101
# define K_F 102
# define K_G 103
# define K_H 104
# define K_I 105
# define K_J 106
# define K_K 107
# define K_L 108
# define K_M 109
# define K_N 110
# define K_O 111
# define K_P 112
# define K_Q 113
# define K_R 114
# define K_S 115
# define K_T 116
# define K_U 117
# define K_V 118
# define K_W 119
# define K_X 120
# define K_Y 121
# define K_Z 122

# define LOW_COLOR 0x0000FF
# define HIGH_COLOR 0xFF0000
# define BLACK 0x000000
# define DARK 0x151515
# define DEFAULT 0xEF8633
# define OFF_WHITE 0xF3F4F2
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define BOTTOM_COLOR 0x1B8EFA
# define TOP_COLOR 0xCD5C5C
# define GROUND_COLOR 0xF4A460

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <stdio.h>
# include "../../minilibx-linux/mlx.h"
# include "../includes/get_next_line.h"
# include "../includes/libft.h"
# include "../includes/libft.h"
# include "../includes/libftprintf.h"

typedef struct s_dot
{
	int		color;
	int		hexa_color;
	int		is_paint;
	float	pol[2];
	float	ax[3];
}				t_dot;

typedef struct s_color
{
	int	start_color;
	int	end_color;
	int	s_red;
	int	s_green;
	int	s_blue;
	int	e_red;
	int	e_green;
	int	e_blue;
	int	n_red;
	int	n_green;
	int	n_blue;
	int	topco;
	int	botco;
	int	backco;
	int	groundco;
}				t_color;

typedef struct s_bg_map
{
	void	*img;
	char	*buffer;
	int		bpix;
	int		lines;
	int		endi;
}				t_bg_map;

typedef struct s_set
{
	void	*mlx;
	void	*win;
}				t_set;

typedef struct s_mouse
{
	int		start_drag[2];
	int		is_leftmouse;
	int		is_rightmouse;
	int		leftmouse;
	int		rightmouse;
	t_dot	bef_leftmouse;
	t_dot	bef_rightmouse;
}				t_mouse;

typedef struct s_key
{
	int	leftctrl;
	int	rightctrl;
	int	leftshift;
	int	rightshift;
}				t_key;

typedef struct s_map
{
	char	**lines;
	char	*mem;
	int		min_z;
	int		min_x;
	int		min_y;
	int		length;
	int		height;
	int		is_lines;
	int		is_dots;
	int		is_suplines;
	int		is_geom;
	int		is_shad;
	int		translation[2];
	int		pos;
	float	prop;
	float	render;
	float	height_factor;
	float	brange;
	float	scale;
	float	divide_z;
	float	angle[3];
	float	rad;
	float	alt;
	float	zoom;
	double	perf;
	t_dot	lim;
	t_dot	from;
	t_dot	*dots;
	t_color	colors;
}				t_map;

typedef struct s_fdf
{
	int			pixels;
	int			length;
	int			height;
	int			first_line_len;
	int			is_first_line;
	int			pos;
	int			delta_x;
	int			delta_y;
	char		*stash;
	char		*buf;
	char		*maps;
	char		*line;
	char		**splits;
	char		**sub;
	char		*last;
	t_dot		discr;
	t_dot		pix;
	t_color		color;
	t_set		set;
	t_key		key;
	t_mouse		mouse;
	t_map		map;
	t_bg_map	bg_map;
}				t_fdf;

	/* algo_fdf.c */

void	set_paint_status(t_dot *dots, int length);
void	create_wireframe(t_dot *dot, t_fdf *fdf, int density, int line);
void	render_wireframe(t_fdf *fdf, t_dot *wire);
int		is_valid_pix(t_dot pix);
int		draw_line(t_fdf *fdf, t_dot start, t_dot end);

	/* clean_utils.c */

void	free_double_pointer(void **str);
void	free_str_array(char **str);
void	clean_resources(t_fdf *fdf);
void	clean_fdf_struct(t_fdf *fdf);
int		check_invalid_dots(t_fdf *fdf, int index);

	/* colors_utils.c */

void	set_background_color(t_fdf *fdf, int bg_color);
int		round_to_nearest(double value);
int		interpolate_color(int start_co, int end_co, int length, int pix);
int		convert_color(t_fdf *fdf, int color);

	/* colors_utils_1.c */

void	apply_color(t_map *map);
void	assign_color(int max_h, int min_h, t_dot *dot, t_color colors);
void	initialize_color(t_map *map);
int		parse_hexaco(char *line);
int		is_valid_point(char *value);

	/* disp_set_utils.c */

void	initialize_matrix(float matrix[3][3]);
void	divide_z_coordinate(t_dot *dots, float divisor, int nbr_of_dots);
void	apply_new_z(t_dot *dots, int length, float range);
void	terminate_with_error(char *str);
int		exit_program(t_fdf *fdf);

	/* display_set.c */

void	screen_coordinates(t_fdf *fdf, t_dot *projected_dots);
void	copy_map(t_dot *from, t_dot *to, int length);
void	transform_points(t_fdf *fdf, t_dot *proj);
void	apply_scale(t_dot *dots, int scale, int length);
void	apply_translation(t_dot *dots, t_dot translation, int length);

	/* draw_utils.c */

void	set_color(char *buff, int endian, int color, int transparency);
void	draw_dot_aux(t_fdf *fdf, t_dot pixel, t_dot dot, int offset);
void	draw_dot(t_fdf *fdf, t_dot dot, int radius);
void	draw_painted_dots(t_fdf *fdf, t_dot *dots);
int		put_pix(t_fdf *fdf, t_dot pix);

	/* drawing.c & drawing_utility.c*/

void	drawing(t_fdf *fdf, t_dot *proj, int fit);
void	extract_dots(t_fdf *fdf);
int		draw_fdf(t_fdf *fdf, int sized);
int		import_map(t_fdf *fdf, char *filepath);
int		import_dots(char *line, t_fdf *fdf, int line_nbr);

	/* extras_utils.c */

int		ft_strcmp(const char *s1, const char *s2);
int		puterror(char *msg);
int		is_fdf_extension(const char *filename);
int		ft_isxdigit(int c);
int		ft_htoi(const char *str);

	/* keys_tools.c */

void	handle_tools_one(int keycode, t_fdf *fdf);
void	handle_tools_two(int keycode, t_fdf *fdf);
void	handle_tools_three(int keycode, t_fdf *fdf);
int		key_press(int keycode, t_fdf *fdf);
int		key_release(int keycode, t_fdf *fdf);

	/* keys_utils.c */

void	update_angle(float *angle, float value);
void	handle_angle_control(int keycode, t_fdf *fdf);
void	control_colorscheme(int keycode, t_map *map);
int		handle_altitude(int keycode, t_fdf *fdf);

	/* main.c */

void	initialize_map(t_map *map, int sum);
void	handle_map_alloc(t_fdf *fdf);
int		count_substr(const char *str, char delimiter);
int		count_dots(t_fdf *fdf, const char *filename);
int		main(int argc, char **argv);

	/* main_utils.c */

void	initialize_main(t_fdf *fdf);
void	free_variables(t_fdf *fdf);
void	setup_hooks(t_fdf *fdf);
int		initialize_check(t_fdf *fdf, int ac, char *filename);
int		file_exists(const char *filename);

	/* main_utils_1.c */

void	initialize_mlx_utils(t_fdf *fdf);
void	initialize_mlx(t_fdf *fdf);
void	initialize_variables(t_fdf *fdf);
int		check_drawing(t_fdf *fdf);
int		import_map_check(t_fdf *fdf, char *filepath);

	/* map_info.c */

void	map_size(t_map *map);
char	*read_file(int fd, t_fdf *fdf);
int		check_limits(t_dot *dots, int length);

	/* matrix_utils.c */

void	ortho_projection(t_dot *dots, t_dot *proj, int length);
void	rotate_around_x(t_dot *dots, t_dot *proj, float angle, int length);
void	rotate_around_y(t_dot *dots, t_dot *proj, float angle, int length);
void	rotate_around_z(t_dot *dots, t_dot*proj, float angle, int length);
t_dot	multiply_matrix(float mat[3][3], t_dot dot);

	/* mouse_utils.c */

int		mouse_move(int x, int y, t_fdf *fdf);
int		mouse_drag(int x, int y, t_fdf *fdf);
int		mouse_press(int mousecode, int x, int y, t_fdf *fdf);
int		mouse_release(int mousecode, int x, int y, t_fdf *fdf);

	/* transformation.c */

void	set_isometric_view(t_map *map);
void	set_top_view(t_map *map);
void	set_profil_view(t_map *map);
void	set_sphere_view(t_map *map, t_dot *dots);
void	set_polar(t_map *map);

#endif
