/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:36:54 by mdude             #+#    #+#             */
/*   Updated: 2020/10/30 12:36:59 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i] != needle[j] && (haystack[i] != '\0'))
			i++;
		while (haystack[i] == needle[j] && haystack[i] != '\0' \
		&& needle[j] != '\0')
		{
			i++;
			j++;
		}
		if (needle[j] == '\0' && i <= len)
			return ((char *)&haystack[i - j]);
	}
	return (NULL);
}
