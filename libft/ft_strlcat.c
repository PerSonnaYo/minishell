/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 14:28:06 by mdude             #+#    #+#             */
/*   Updated: 2020/10/29 14:31:49 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	dstlen;

	i = 0;
	k = ft_strlen(dst);
	dstlen = k;
	if (!dst)
		return (0);
	if (dstsize <= k)
		return (ft_strlen(src) + dstsize);
	while (k < dstsize - 1 && src[i] != '\0')
	{
		dst[k] = src[i];
		k++;
		i++;
	}
	dst[k] = '\0';
	return (ft_strlen(src) + dstlen);
}
