/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <mdude@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:23:24 by mdude             #+#    #+#             */
/*   Updated: 2020/11/01 14:41:01 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*res;

	i = 0;
	source = (unsigned char *)src;
	res = (unsigned char *)dst;
	if (!src && !dst)
		return (NULL);
	while (i < n)
	{
		*res++ = *source++;
		i++;
	}
	return (dst);
}
