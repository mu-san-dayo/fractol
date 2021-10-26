/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_elem_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:41:38 by ymukobar          #+#    #+#             */
/*   Updated: 2021/10/12 21:41:39 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlst_elem_new(t_dlist **lst, void *elem)
{
	t_dlist	*new;

	new = ft_dlst_new(elem);
	if (new == NULL)
		return (NULL);
	return (ft_dlst_add_elem(lst, new));
}
