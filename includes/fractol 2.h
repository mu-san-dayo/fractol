#ifndef FRACTOL_H
# define FRACTOL_H

# if __APPLE__
#  include "../minilibx_mms_20200219/mlx.h"
# elif __linux__
#  include "../minilibx-linux/mlx.h"
# endif

# include "../libft/libft.h"
# include "vector_utils.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <float.h>

# if __APPLE__
#  define KEYCODE_DEL	51
#  define KEYCODE_ESC	53
#  define KEYCODE_LEFT	123
#  define KEYCODE_RIGHT	124
#  define KEYCODE_UP	126
#  define KEYCODE_DOWN	125
#  define KEYCODE_FN	63
#  define KEYCODE_HOME	116
#  define KEYCODE_END	121
#  define KEYCODE_PAGE_UP	115
#  define KEYCODE_PAGE_DOWN	119
#  define HOOK_NUM			17
# elif __linux__
#  define KEYCODE_ESC		0xff1b
#  define KEYCODE_LEFT		0xff51
#  define KEYCODE_RIGHT		0xff53
#  define HOOK_NUM			33
# endif

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			r_x;
	int			r_y;
	double		z_re;
	double		z_im;
	double		c_re;
	double		c_im;
	double		d_re;
	double		d_im;
	double		min_re;
	double		min_im;
	double		max_re;
	double		max_im;
}				t_data;


int	return_error(char *str);
int	exit_error(char *str);
int	key_press(int key, t_data *info);
int	exit_window(t_data *info);
int	rgb_to_color(int r, int g, int b);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
unsigned int	get_color_from_img(t_img img, int x, int y);

void	draw_image(t_data *info);
int	main_loop(t_data *world);
int	window_settings(t_data *info);
int	window_settings(t_data *info);
int	screen_settings(t_data *info, int check);

int	i_min(int a, int b);
int	i_max(int a, int b);
double	f_sqr(double x);

#endif