/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:41:00 by ymukobar          #+#    #+#             */
/*   Updated: 2021/10/12 21:41:01 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rgb2hex(int r, int g, int b)
{
	r = i_max(0, i_min(r, 255));
	g = i_max(0, i_min(g, 255));
	b = i_max(0, i_min(b, 255));
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color_from_img(t_img img, int x, int y)
{
	return (*(unsigned int *)(img.addr
		+ (y * img.line_length + x * (img.bits_per_pixel / 8))));
}
