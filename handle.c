#include "minishell.h"

int	parcer_doll(char **tmp, char *str, int i, char **envy)
{
	int		u;
	char	*s4;
	char	*t;

	u = i;
	if (str[i + 1] == '?')
	{
		s4 = ft_itoa(g_mini.qua);
		*tmp = ft_strjoin1(*tmp, s4);
		++i;
		free(s4);
	}
	while (str[i] && str[i] != '"' && !ft_space(str[i]) \
	&& str[i] != '=' && str[i] != 92 && str[i] != '\'')
		i++;
	s4 = ft_substr(str, u + 1, i - u - 1);
	t = dollar(s4, envy);
	*tmp = ft_strjoin1(*tmp, t);
	free(t);
	free(s4);
	if (str[i] == '"')
		i++;
	return (i);
}

int	parser_simple(char **tmp, char *str, int i)
{
	char	s2[2];

	s2[0] = str[i];
	s2[1] = '\0';
	*tmp = ft_strjoin1(*tmp, s2);
	i++;
	return (i);
}

int	parser_kov2(char **gen, char *str, int i, char **env)
{
	char	s2[2];

	i++;
	while (str[i] && str[i] != 34)
	{
		if (str[i] == 92 && (str[i + 1] == 92 || \
			str[i + 1] == 34 || str[i + 1] == '$'))
		{
			s2[0] = str[i + 1];
			s2[1] = '\0';
			*gen = ft_strjoin1(*gen, s2);
			i = i + 2;
		}
		else if (str[i] == 36)
			i = parcer_doll(&(*gen), str, i, env);
		else
			i = parser_simple(&(*gen), str, i);
	}
	if (str[i] == '"')
		i++;
	return (i);
}

int	parser_kov(char **gen, char *str, int i)
{
	char	s2[2];

	++i;
	while (str[i] && str[i] != '\'')
	{
		s2[0] = str[i];
		s2[1] = '\0';
		*gen = ft_strjoin1(*gen, s2);
		i++;
	}
	if (str[i] == '\'')
		i++;
	return (i);
}

int	parser_alpha1(char **gen, char *str, int i, char **env)
{
	while (str[i] && str[i] != '>' && str[i] != '<' && !ft_space(str[i]))
	{
		if (str[i] == 92)
			i = slash(str, i, gen);
		else if (str[i] == 36)
			i = parcer_doll(&(*gen), str, i, env);
		else if (str[i] == 34)
			i = parser_kov2(&(*gen), str, i, env);
		else if (str[i] == '\'')
			i = parser_kov(&(*gen), str, i);
		else
			i = parser_simple(&(*gen), str, i);
	}
	return (i);
}
