#include "minishell.h"

int	check_err(t_line *res, char **str)
{
	int	i;

	i = 0;
	if ((*str)[i] == ';')
	{
		print_error("morty$: ", SY_TO, ";'\n");
		res->i = 258;
		return (res->i);
	}
	if ((*str)[i] == '|')
	{
		if ((*str)[i + 1] && ((*str)[i + 1] == '|'))
			print_error("morty$: ", SY_TO, "|'\n");
		else
			print_error("morty$: ", SY_TO, "||'\n");
		res->i = 258;
		return (res->i);
	}
	return (0);
}

int	check_err2(char **str, int i, t_line *res)
{
	int	k;

	if ((*str)[i] == '|')
	{
		g_mini.p = 1;
		k = i + 1;
		while ((*str)[k] && ft_space((*str)[k]))
			k++;
		if ((*str)[k] == '|')
		{
			print_error("morty$: ", SY_TO, "|'\n");
			res->i = 258;
			return (res->i);
		}
	}
	return (0);
}

int	change_str(char **str, int i, t_line *res)
{
	int		k;
	char	*tmp;

	tmp = (*str);
	if ((*str)[i] == ';')
	{
		k = i + 1;
		while ((*str)[k] && ft_space((*str)[k]))
			k++;
		if ((*str)[k] == ';')
		{
			print_error("morty$: ", SY_TO, ";;'\n");
			res->i = 258;
			return (res->i);
		}
		(*str) = ft_strdup(&(*str)[i + 1]);
	}
	else
		(*str) = NULL;
	free(tmp);
	return (0);
}

void	gnl_slush(char **str, t_line *res, int *i, int *j)
{
	if (!is_spec((*str)[*i]) && (*str)[*i] != ';')
	{
		res->line[*j] = (*str)[*i];
		*j = *j + 1;
		*i = *i + 1;
	}
	if ((*str)[*i] == '\\')
	{
		res->line[*j] = (*str)[*i];
		*j = *j + 1;
		*i = *i + 1;
		if (is_spec((*str)[*i]) || (*str)[*i] == ';')
		{
			res->line[*j] = (*str)[*i];
			*j = *j + 1;
			*i = *i + 1;
		}
	}
}

void	gnl_dol(char **str, t_line *res, int *i, int *j)
{
	if ((*str)[*i] == '\'')
	{
		res->line[*j] = (*str)[*i];
		*j = *j + 1;
		*i = *i + 1;
		while ((*str)[*i] && (*str)[*i] != '\'')
		{
			res->line[*j] = (*str)[*i];
			*j = *j + 1;
			*i = *i + 1;
		}
		res->line[*j] = (*str)[*i];
		*j = *j + 1;
		*i = *i + 1;
	}
	if ((*str)[*i] == '$')
	{
		res->line[*j] = (*str)[*i];
		*j = *j + 1;
		*i = *i + 1;
	}
}
