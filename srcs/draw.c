/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:40:37 by ymukobar          #+#    #+#             */
/*   Updated: 2021/10/12 21:40:37 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	set_hsv_prms(t_hsv *hsv)
{
	if (hsv->s <= 0.0)
		return (1);
	hsv->hh = hsv->hh;
	if (hsv->hh >= 360.0)
		hsv->hh = 0.0;
	hsv->hh = hsv->h / 60.0;
	hsv->i = (long)hsv->hh;
	hsv->ff = hsv->hh - hsv->i;
	hsv->p = hsv->v * (1.0 - hsv->s);
	hsv->q = hsv->v * (1.0 - (hsv->s * hsv->ff));
	hsv->t = hsv->v * (1.0 - (hsv->s * (1.0 - hsv->ff)));
	return (0);
}

unsigned int	hsv2rgb2hex(double h, double s, double v)
{
	t_hsv	hsv;

	hsv.h = h;
	hsv.s = s;
	hsv.v = v;
	if (set_hsv_prms(&hsv) == 1)
		return (rgb2hex(0, 0, 0));
	if (hsv.i == 0)
		return (rgb2hex(hsv.v * 255, hsv.t * 255, hsv.p * 255));
	else if (hsv.i == 1)
		return (rgb2hex(hsv.q * 255, hsv.v * 255, hsv.p * 255));
	else if (hsv.i == 2)
		return (rgb2hex(hsv.p * 255, hsv.v * 255, hsv.t * 255));
	else if (hsv.i == 3)
		return (rgb2hex(hsv.p * 255, hsv.q * 255, hsv.v * 255));
	else if (hsv.i == 4)
		return (rgb2hex(hsv.t * 255, hsv.p * 255, hsv.v * 255));
	else if (hsv.i == 5)
		return (rgb2hex(hsv.v * 255, hsv.p * 255, hsv.q * 255));
	else
		return (rgb2hex(hsv.v * 255, hsv.p * 255, hsv.q * 255));
}
