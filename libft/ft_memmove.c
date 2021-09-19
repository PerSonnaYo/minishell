/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:30:05 by mdude             #+#    #+#             */
/*   Updated: 2020/10/29 13:30:09 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*source;
	unsigned char	*res;

	source = (unsigned char *)src;
	res = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	if (res < source)
		ft_memcpy(dst, src, len);
	else
	{
		while (len > 0)
		{
			res[len - 1] = source[len - 1];
			len--;
		}
	}
	return (res);
}
