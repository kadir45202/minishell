/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eayyildi <ayyildiz_enes66@hotmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 17:05:34 by eayyildi          #+#    #+#             */
/*   Updated: 2022/10/24 14:07:05 by eayyildi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (src == NULL && dest == NULL)
		return (NULL);
	i = 0;
	while (s && i < n)
	{
		if (src < dest)
			d[n - i - 1] = s[n - i - 1];
		else
			d[i] = s[i];
		i++;
	}
	return (dest);
}
