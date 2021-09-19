#include "minishell.h"

void	kov_ret(char **str, char **env, t_ij *ij, char **res)
{
	ij->i++;
	while ((*str)[ij->i] && (*str)[ij->i] != '"')
	{
		if ((*str)[ij->i] == '\\')
		{
			ij->i++;
			(*res)[ij->j] = (*str)[ij->i];
			ij->j++;
			ij->i++;
		}
		if ((*str)[ij->i] != '$' && (*str)[ij->i] != '\\')
		{
			(*res)[ij->j] = (*str)[ij->i];
			ij->j++;
			ij->i++;
		}
		if ((*str)[ij->i] == '$')
		{
			pars_dollar(*str, env, ij, res);
		}
	}
	if ((*str)[ij->i] == '"')
		ij->i++;
	else
		(*res)[ij->j] = '\0';
}

void	slush_ret(char *str, t_ij *ij, char **res)
{
	ij->i = ij->i + 1;
	while (str[ij->i] && str[ij->i] != '\'')
	{
		(*res)[ij->j] = str[ij->i];
		ij->j = ij->j + 1;
		ij->i = ij->i + 1;
	}
	if (str[ij->i] == '\'')
		ij->i = ij->i + 1;
	else
		(*res)[ij->j] = '\0';
}

void	go_ret(char *str, t_ij *ij, char **res)
{
	if (!is_spec(str[ij->i]))
	{
		(*res)[ij->j] = str[ij->i];
		ij->i++;
		ij->j++;
	}
	if (str[ij->i] == '\\' && str[ij->i + 1])
	{
		ij->i++;
		(*res)[ij->j] = str[ij->i];
		ij->i++;
		ij->j++;
	}
}

char	*ret_word(char *str, char **env)
{
	t_ij	ij;
	char	*res;

	ij.i = 0;
	ij.j = 0;
	while (ft_space(str[ij.i]))
		ij.i++;
	res = (char *) malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[ij.i] && str[ij.i] != ' ')
	{
		go_ret(str, &ij, &res);
		if (str[ij.i] == '\'')
			slush_ret(str, &ij, &res);
		if (str[ij.i] == '"')
			kov_ret(&str, env, &ij, &res);
		if (str[ij.i] == '$')
			pars_dollar(str, env, &ij, &res);
	}
	res[ij.j] = '\0';
	return (res);
}
