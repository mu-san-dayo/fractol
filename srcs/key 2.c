#include "fractol.h"

int	key_press(int key, t_data *info)
{
	if (key == KEYCODE_ESC)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	if (key == KEYCODE_RIGHT)
		return (0);
	return (0);
}
