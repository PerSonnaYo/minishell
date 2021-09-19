/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:09:19 by mdude             #+#    #+#             */
/*   Updated: 2020/11/01 13:02:21 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	i = 0;
	ns1 = (unsigned char *)s1;
	ns2 = (unsigned char *)s2;
	while (ns1[i] != '\0' && ns2[i] != '\0' && ns1[i] == ns2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	else
		return (ns1[i] - ns2[i]);
}
