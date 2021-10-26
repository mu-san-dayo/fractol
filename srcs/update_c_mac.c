/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_c_mac.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:40:55 by ymukobar          #+#    #+#             */
/*   Updated: 2021/10/12 21:40:56 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_c(t_data *info)
{
	int		x;
	int		y;
	double	mouse_re;
	double	mouse_im;

	mlx_mouse_get_pos(info->win, &x, &y);
	if (!x && !y)
		return ;
	mouse_re = (double)x
		/ (WIDTH / (info->max_re - info->min_re)) + info->min_re;
	mouse_im = (double)y
		/ (HEIGHT / (info->max_im - info->min_im)) * -1 + info->max_im;
	info->c_re = mouse_re;
	info->c_im = mouse_im;
}

int	exit_window(t_data *info)
{
	if (info->mlx && info->win)
		mlx_destroy_window(info->mlx, info->win);
	exit(0);
}
