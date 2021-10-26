/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:40:31 by ymukobar          #+#    #+#             */
/*   Updated: 2021/10/12 21:40:31 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	i_min(int a, int b)
{
	int	res;

	if (a < b)
		res = a;
	else
		res = b;
	return (res);
}

int	i_max(int a, int b)
{
	int	res;

	if (a > b)
		res = a;
	else
		res = b;
	return (res);
}

double	f_sqr(double x)
{
	return (x * x);
}

double	abs_double(double val)
{
	if (val < 0)
		return (-val);
	return (val);
}
