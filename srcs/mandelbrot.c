/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:40:50 by ymukobar          #+#    #+#             */
/*   Updated: 2021/10/12 21:40:50 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main_loop_man(t_data *info)
{
	update_c(info);
	draw_mandelbrot(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	return (0);
}

/*
 *
 * color = hsv2rgb2hex((iteration) % 360,
 * ((double)iteration) / info->iter,
 * ((double)iteration) / info->iter);
 *
 */
unsigned int	set_color(t_data *info)
{
	int		iteration;
	int		color;
	double	tmp;

	iteration = 0;
	while (info->z_re * info->z_re + info->z_im * info->z_im <= 4
		&& iteration < info->iter)
	{
		tmp = info->z_re * info->z_re - info->z_im * info->z_im + info->c_re;
		info->z_im = 2 * info->z_re * info->z_im + info->c_im;
		info->z_re = tmp;
		iteration++;
	}
	if (iteration == info->iter)
		color = rgb2hex(0, 0, 0);
	else
		color = (iteration * info->color);
	return (color);
}

void	draw_mandelbrot(t_data *info)
{
	int	x;
	int	y;

	info->d_re = (info->max_re - info->min_re) / (WIDTH - 1);
	info->d_im = (info->max_im - info->min_im) / (HEIGHT - 1);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			info->c_im = info->min_im + y * info->d_im;
			info->c_re = info->min_re + x * info->d_re;
			info->z_re = 0;
			info->z_im = 0;
			my_mlx_pixel_put(&info->img, x, y, set_color(info));
			x++;
		}
		y++;
	}
}
