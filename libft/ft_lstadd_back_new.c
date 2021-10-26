/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:42:36 by ymukobar          #+#    #+#             */
/*   Updated: 2021/10/12 21:42:37 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_back_new(t_list **lst, void *content)
{
	t_list	*new_list;

	new_list = ft_lstnew(content);
	if (!new_list)
		return (NULL);
	ft_lstadd_back(lst, new_list);
	return (*lst);
}
