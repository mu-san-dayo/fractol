#include "fractol.h"

void	draw_image(t_data *info)
{
	int			y;
	int			x;

	y = 0;
	while (y < info->r_y)
	{
		x = -1;
		while (++x < info->r_x)
			my_mlx_pixel_put(&info->img, x, y, rgb_to_color(255, 0, 0));
		y++;
	}
}

