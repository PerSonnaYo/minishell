#include "minishell.h"

void	gnl_kov(char **str, t_line *res, int *i, int *j)
{
	if ((*str)[*i] == '"')
	{
		res->line[*j] = (*str)[*i];
		*j = *j + 1;
		*i = *i + 1;
		while ((*str)[*i] && (*str)[*i] != '"')
		{
			res->line[*j] = (*str)[*i];
			*j = *j + 1;
			*i = *i + 1;
		}
		res->line[*j] = (*str)[*i];
		*j = *j + 1;
		*i = *i + 1;
	}
	if ((*str)[*i] == '/')
		g_mini.sl = 1;
}

int	flagok(char **str, t_line *res, int *i, int *j)
{
	int	flag;

	flag = 0;
	gnl_slush(str, res, i, j);
	gnl_dol(str, res, i, j);
	gnl_kov(str, res, i, j);
	if ((*str)[*i] == ';')
		flag = 1;
	return (flag);
}

void	init_res(t_line *res, char **str)
{
	res->i = 0;
	g_mini.p = 0;
	g_mini.sl = 0;
	res->line = (char *)malloc(sizeof(char) * ft_strlen(*str) + 1);
	res->i = gnl4(*str);
}

t_line	gnl2(char **str)
{
	int		i;
	int		j;
	t_line	res;
	int		flag;

	i = 0;
	j = 0;
	flag = 0;
	init_res(&res, str);
	if (res.i > 0)
		return (res);
	if (check_err(&res, str) == 258)
		return (res);
	if ((*str)[i] == '/')
		g_mini.sl = 1;
	while ((*str)[i] && (*str)[i] != ';' && !flag)
	{
		flag = flagok(str, &res, &i, &j);
		if (check_err2(str, i, &res) == 258)
			return (res);
	}
	res.line[j] = '\0';
	if (change_str(str, i, &res) == 258)
		return (res);
	return (res);
}
