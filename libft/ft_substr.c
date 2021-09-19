/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:25:27 by mdude             #+#    #+#             */
/*   Updated: 2020/10/30 14:25:30 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	in_cycle(char **ju, char *s, size_t *i, unsigned int *start)
{
	(*ju)[*i] = s[*start];
	*start = *start + 1;
	*i = *i + 1;
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	int		y;
	char	*ju;
	size_t	i;
	char	*s;

	i = 0;
	if (!str)
		return (NULL);
	s = ft_strdup(str);
	y = ft_strlen(s) - start;
	ju = malloc(sizeof(char) * (len + 1));
	if (!ju)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (y-- && len--)
			in_cycle(&ju, s, &i, &start);
		ju[i] = '\0';
	}
	else
		ju[i] = '\0';
	free(s);
	return (ju);
}
