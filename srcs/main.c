/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:40:10 by ymukobar          #+#    #+#             */
/*   Updated: 2021/10/23 01:07:38 by mukobaray        ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_info(t_data *info, char *kinds)
{
	if (!ft_strncmp(kinds, "mandelbrot", 11))
		info->flag = MANDELBROT;
	else if (!ft_strncmp(kinds, "julia", 6))
		info->flag = JULIA;
	else if (!ft_strncmp(kinds, "burningship", 12))
		info->flag = BURNINGSHIP;
	else
		exit_error("Fractals do not exist\n\
Usage: ./fractol <name>\n\n\
List of available fractals:\n\
 * mandelbrot\n\
 * julia\n\
 * burningship\n");
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "fractol");
	if (!info->win)
		exit(1);
	info->img.img = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	if (!info->img.img)
		exit(1);
	info->img.addr = mlx_get_data_addr(info->img.img,
			&info->img.bits_per_pixel,
			&info->img.line_length, &info->img.endian);
	return ;
}

void	set_prms(t_data *info)
{
	info->color = 113513;
	info->iter = 100;
	info->max_re = 2.0;
	info->max_im = 2.0;
	info->min_re = -2.0;
	info->min_im = -2.0;
	info->c_re = 0.4;
	info->c_im = -0.325;
	info->shift = 1;
}

int	main(int argc, char *argv[])
{
	t_data	info;

	if (argc != 2)
		exit_error("Incorrect argments\n\
Usage: ./fractol <name>\n\n\
List of available fractals:\n\
 * mandelbrot\n\
 * julia\n\
 * burningship\n");
	init_info(&info, argv[1]);
	set_prms(&info);
	mlx_hook(info.win, HOOK_KEY, HOOK_KEY_MASK, key_press, &info);
	mlx_hook(info.win, HOOK_NUM, 1L << 17, exit_window, &info);
	mlx_mouse_hook(info.win, zoom, &info);
	if (info.flag == MANDELBROT)
		mlx_loop_hook(info.mlx, &main_loop_man, &info);
	else if (info.flag == JULIA)
		mlx_loop_hook(info.mlx, &main_loop_julia, &info);
	else if (info.flag == BURNINGSHIP)
		mlx_loop_hook(info.mlx, &main_loop_burn, &info);
	mlx_loop(info.mlx);
	return (0);
}
