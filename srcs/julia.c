/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:40:45 by ymukobar          #+#    #+#             */
/*   Updated: 2021/10/28 03:56:54 by mukobaray        ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_data *info)
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
			info->z_im = info->min_im + y * info->d_im;
			info->z_re = info->max_re - x * info->d_re;
			my_mlx_pixel_put(&info->img, x, y, set_color(info));
			x++;
		}
		y++;
	}
}

int	main_loop_julia(t_data *info)
{
	//if (info->shift == 1)
	//	update_c(info);
	draw_julia(info);
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
	return (0);
}
