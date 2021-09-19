/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <mdude@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:01:14 by mdude             #+#    #+#             */
/*   Updated: 2020/11/01 14:53:43 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*res;
	unsigned char	sign;

	i = 0;
	if (!src && !dst)
		return (NULL);
	sign = (unsigned char)c;
	source = (unsigned char *)src;
	res = (unsigned char *)dst;
	while (i < n)
	{
		res[i] = source[i];
		if (res[i] == sign)
			return (res + i + 1);
		i++;
	}
	return (NULL);
}
