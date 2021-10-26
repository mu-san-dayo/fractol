/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:40:18 by ymukobar          #+#    #+#             */
/*   Updated: 2021/10/12 22:49:02 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(int key, t_data *info)
{
	if (key == KEYCODE_RIGHT)
	{
		info->min_re += (info->max_re - info->min_re) * MOVE_STEP;
		info->max_re += (info->max_re - info->min_re) * MOVE_STEP;
	}
	else if (key == KEYCODE_LEFT)
	{
		info->min_re -= (info->max_re - info->min_re) * MOVE_STEP;
		info->max_re -= (info->max_re - info->min_re) * MOVE_STEP;
	}
	else if (key == KEYCODE_UP)
	{
		info->min_im -= (info->max_im - info->min_im) * MOVE_STEP;
		info->max_im -= (info->max_im - info->min_im) * MOVE_STEP;
	}
	else if (key == KEYCODE_DOWN)
	{
		info->min_im += (info->max_im - info->min_im) * MOVE_STEP;
		info->max_im += (info->max_im - info->min_im) * MOVE_STEP;
	}
}

void	change_color(t_data *info)
{
	static int	i = 0;

	if (i % 10 == 0)
		info->color = 35263;
	else if (i % 10 == 1)
		info->color = 8567435;
	else if (i % 10 == 2)
		info->color = 119105;
	else if (i % 10 == 3)
		info->color = rgb2hex(100, 20, 50);
	else if (i % 10 == 4)
		info->color = 29634;
	else if (i % 10 == 5)
		info->color = 9641;
	else if (i % 10 == 6)
		info->color = 762358;
	else if (i % 10 == 7)
		info->color = rgb2hex(200, 90, 10);
	else if (i % 10 == 8)
		info->color = 1139;
	else if (i % 10 == 9)
		info->color = 113513;
	i++;
	if (i == 11)
		i = 0;
}

int	key_press(int key, t_data *info)
{
	if (key == KEYCODE_ESC)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	if (key == KEYCODE_LEFT_SHIFT || key == KEYCODE_RIGHT_SHIFT)
	{
		if (info->shift == 0)
			info->shift = 1;
		else
			info->shift = 0;
	}
	if (key == KEYCODE_LEFT || key == KEYCODE_RIGHT
		|| key == KEYCODE_UP || key == KEYCODE_DOWN)
		move(key, info);
	if (key == KEYCODE_C)
		change_color(info);
	return (0);
}

void	interpolate_image(t_data *info)
{
	info->max_re = (info->m_re + (info->max_re - info->m_re)
			* info->interpolate);
	info->max_im = (info->m_im + (info->max_im - info->m_im)
			* info->interpolate);
	info->min_re = (info->m_re + (info->min_re - info->m_re)
			* info->interpolate);
	info->min_im = (info->m_im + (info->min_im - info->m_im)
			* info->interpolate);
}

int	zoom(int button, int x, int y, t_data *info)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		info->m_re = (double)x / (WIDTH / (info->max_re - info->min_re))
			+ info->min_re;
		info->m_im = (double)y / (HEIGHT / (info->max_im - info->min_im))
			* -1 + info->max_im;
		if (button == SCROLL_UP)
		{
			if (info->iter > 4)
				info->iter -= 4;
			info->interpolate = 1.2;
		}
		else if (button == SCROLL_DOWN)
		{
			info->iter += 4;
			info->interpolate = 0.8;
		}
		interpolate_image(info);
	}
	return (0);
}
