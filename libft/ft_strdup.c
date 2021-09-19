/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:05:41 by mdude             #+#    #+#             */
/*   Updated: 2020/11/01 12:50:35 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = (char *)malloc(ft_strlen(s1) + 1);
	if (!newstr)
		return (NULL);
	else
	{
		while (s1[i] != '\0')
		{
			newstr[i] = s1[i];
			i++;
		}
		newstr[i] = '\0';
		return (newstr);
	}
}
