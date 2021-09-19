#include "minishell.h"

int	is_spec(char c)
{
	return ((c == '$') || (c == '\'') || (c == '"') || (c == '\\'));
}

void	vopros(char **res, t_ij *ij)
{
	char	*s4;

	s4 = ft_itoa(g_mini.qua);
	*res = ft_strjoin1(*res, s4);
	ij->i = ij->i + 1;
	ij->j = ft_strlen(s4);
	free(s4);
}

void	pars_dollar(char *str, char **env, t_ij *ij, char **res)
{
	int		k;
	char	*temp;
	char	*temp3;
	char	*temp4;

	ij->i = ij->i + 1;
	if (str[ij->i] == '?')
		vopros(res, ij);
	else
	{
		k = ij->i;
		while (str[ij->i] && !is_spec(str[ij->i]) && \
		!ft_space(str[ij->i]) && (str[ij->i]) != '=')
			ij->i = ij->i + 1;
		temp3 = ft_substr(str, k, ij->i - k);
		temp = dollar(temp3, env);
		free(*res);
		*res = ft_calloc(1, 1);
		temp4 = ft_substr(str, 0, k - 1);
		*res = ft_strjoin1(*res, temp4);
		*res = ft_strjoin1(*res, temp);
		free_all(&temp, &temp3, &temp4);
		ij->j = ij->j + ft_strlen(*res + ij->j);
	}
}

void	ret_i(char *str, int *i)
{
	*i = *i + 1;
	while (str[*i] && str[*i] != '"')
		*i = *i + 1;
	if (str[*i] == '"')
		*i = *i + 1;
}

int	num_space(char *str)
{
	int	i;

	i = 0;
	while (ft_space(str[i]))
		i++;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '\\')
			i++;
		if (str[i] != ' ' && str[i] != '"' && str[i] != '\'' && str[i] != '\\')
			i++;
		if (str[i] == '"')
			ret_i(str, &i);
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (str[i] == '\'')
				i++;
		}
	}
	return (i);
}
