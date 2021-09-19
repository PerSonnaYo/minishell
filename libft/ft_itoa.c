/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:04:17 by mdude             #+#    #+#             */
/*   Updated: 2020/11/02 14:04:19 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_reverse(char *s)
{
	int		i;
	int		k;
	char	temp;

	i = 0;
	k = (int)ft_strlen(s) - 1;
	while (k > i)
	{
		temp = s[i];
		s[i] = s[k];
		s[k] = temp;
		i++;
		k--;
	}
	return (s);
}

static int	radix(long n)
{
	int		count;

	count = 1;
	while (n / 10 > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static long	ft_abs(long n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		k;
	long	longn;

	i = 0;
	k = 0;
	if (n < 0)
		k = 1;
	if (n == 0)
		return (ft_strdup("0"));
	longn = ft_abs(n);
	str = (char *)malloc(radix(longn) + k + 1);
	if (!str)
		return (NULL);
	while (longn > 0)
	{
		str[i++] = longn % 10 + '0';
		longn = longn / 10;
	}
	if (k == 1)
		str[i] = '-';
	str[i + k] = '\0';
	return (ft_reverse(str));
}
