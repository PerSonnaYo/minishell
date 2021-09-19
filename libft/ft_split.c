/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:18:06 by mdude             #+#    #+#             */
/*   Updated: 2020/11/02 12:18:08 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	freemas(char **res, int j)
{
	int		i;

	i = 0;
	while (i < j)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}

static int	fillsplit(char **res, char const *s, char c)
{
	int		k;
	int		mas[2];
	int		count;

	mas[0] = 0;
	mas[1] = 0;
	while (s[mas[0]])
	{
		count = mas[0];
		while (s[mas[0]] && s[mas[0]] != c)
			mas[0]++;
		if (s[mas[0]] == c || mas[0] == (int)ft_strlen(s))
		{
			k = 0;
			res[mas[1]] = (char *)malloc(sizeof(char) * (mas[0] - count + 1));
			if (!(res[mas[1]]))
				return (freemas(res, mas[1]));
			while (mas[0] > count)
				res[mas[1]][k++] = s[count++];
			res[mas[1]++][k] = '\0';
		}
		while (s[mas[0]] && s[mas[0]] == c)
			mas[0]++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_countwords(s, c);
	res = (char **)malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	if (!(fillsplit(res, &s[i], c)))
		return (NULL);
	res[len] = NULL;
	return (res);
}
