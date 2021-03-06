/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_row_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:42:20 by ymukobar          #+#    #+#             */
/*   Updated: 2021/10/12 21:42:20 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_row_count(void **pstr)
{
	size_t	i;

	i = 0;
	while (pstr[i])
		i++;
	return (i);
}
