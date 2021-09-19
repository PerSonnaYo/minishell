/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdude <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:48:56 by mdude             #+#    #+#             */
/*   Updated: 2020/11/01 14:07:41 by mdude            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_space(char s)
{
	if (s == ' ' || s == '\n' || s == '\t' || \
	s == '\r' || s == '\f' || s == '\v')
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && ft_space(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res > 9223372036854775807 && sign == 1)
			return (21474836478);
		if (res > 1844674407370955161 && sign == -1)
			return (21474836478);
		i++;
	}
	return ((res * sign));
}
