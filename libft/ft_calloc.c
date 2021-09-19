/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:49:46 by mdude             #+#    #+#             */
/*   Updated: 2020/11/01 12:48:29 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)malloc(count * size);
	i = 0;
	if (!str)
		return (NULL);
	while (i < size * count)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
