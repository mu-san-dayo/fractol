#include "fractol.h"

int	main_loop(t_data *info)
{
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	return (0);
}

int	window_settings(t_data *info)
{
	info->win = mlx_new_window(info->mlx, info->r_x, info->r_y, "fractol");
	if (!info->win)
		return (return_error("Failed to create window"));
	return (0);
}

int	screen_settings(t_data *info, int check)
{
	if (check && window_settings(info) == ERROR)
		return (ERROR);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	info;
	(void)argv;
	info.r_x = 100;
	info.r_y = 100;
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.r_x, info.r_y, "fractol");
	if (!info.win)
		exit(1);
	info.img.img = mlx_new_image(info.mlx,
			info.r_x, info.r_y);
	if (!info.img.img)
	info.img.addr = mlx_get_data_addr(info.img.img,
			&info.img.bits_per_pixel,
			&info.img.line_length, &info.img.endian);
		exit(1);
	if (argc != 2)
		exit_error("Incorrect argments");
	// if (screen_settings(&info, 1))
	// 	return (1);
	screen_settings(&info, 1);
	draw_image(&info);
	mlx_hook(info.win, 2, 1, key_press, &info);
	mlx_hook(info.win, HOOK_NUM, 1L << 17, exit_window, &info);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_loop(info.mlx);
	return (0);
}