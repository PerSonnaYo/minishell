/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: latkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:19:19 by latkins           #+#    #+#             */
/*   Updated: 2020/11/04 17:19:45 by latkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	q;

	q = 0;
	while (src[q])
	{
		dest[q] = src[q];
		q++;
	}
	dest[q] = '\0';
	return (dest);
}