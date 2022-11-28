/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eayyildi <ayyildiz_enes66@hotmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:01:49 by eayyildi          #+#    #+#             */
/*   Updated: 2022/10/24 14:07:05 by eayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstget_at(t_list *lst, int i)
{
	t_list	*target;
	int		j;

	j = 0;
	if (!lst)
		return (NULL);
	while (lst && j++ < i)
		lst = lst->next;
	target = lst;
	return (target);
}
