#include "minishell.h"

void	gnl_slushnew(char **str, t_line *res, int *i, int *j)
{
	if ((*str)[*i] == '\\')
	{
		*i = *i + 1;
		res->line[*j] = (*str)[*i];
		*j = *j + 1;
		*i = *i + 1;
	}
	if (!is_spec((*str)[*i]) && (*str)[*i] != '|')
	{
		res->line[*j] = (*str)[*i];
		*j = *j + 1;
		*i = *i + 1;
	}
}

int	flagnew(char **str, t_line *res, int *i, int *j)
{
	int	flag;

	flag = 0;
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
	if ((*str)[*i] == '|')
	{
		flag = 1;
		g_mini.pipe = 1;
	}
	return (flag);
}

t_line	gnl3(char **str)
{
	int		i;
	int		j;
	t_line	res;
	int		flag;
	char	*tmp;

	i = 0;
	j = 0;
	flag = 0;
	res.i = 0;
	res.line = (char *)malloc(sizeof(char) * ft_strlen(*str) + 1);
	while ((*str)[i] && (*str)[i] != '|' && !flag)
	{
		gnl_slushnew(str, &res, &i, &j);
		gnl_dol(str, &res, &i, &j);
		flag = flagnew(str, &res, &i, &j);
	}
	res.line[j] = '\0';
	tmp = *str;
	if ((*str)[i] == '|')
		(*str) = ft_strdup(&(*str)[i + 1]);
	else
		str[0] = NULL;
	free(tmp);
	return (res);
}
