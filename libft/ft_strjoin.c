/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:26:52 by mdude             #+#    #+#             */
/*   Updated: 2020/11/01 15:26:59 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (newstr)
	{
		while (s1[i] != '\0')
			newstr[j++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			newstr[j++] = s2[i++];
		newstr[j] = '\0';
		return (newstr);
	}
	else
		return (NULL);
}
