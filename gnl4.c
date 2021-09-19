#include "minishell.h"

int	palka(char *str, int *i)
{
	int	k;

	if (str[*i] == '|')
	{
		if (str[*i + 1] == '|')
			*i = *i + 1;
		k = *i + 1;
		while (ft_space(str[k]))
			k++;
		if (str[k] && str[k] == '|')
		{
			if (str[k + 1] && str[k + 1] == '|')
				return (perro("||'\n"));
			else
				return (perro("|'\n"));
		}
		else if (!str[k])
			return (perro("|'\n"));
		*i = *i + 1;
	}
	return (0);
}

int	dotcom(char *str, int *i)
{
	int	k;

	if (str[*i] == ';')
	{
		k = *i + 1;
		if (str[k] && str[k] == ';')
		{
			print_error("morty$: ", SY_TO, ";;'\n");
			return (258);
		}
		else
		{
			while (ft_space(str[k]))
				k++;
			if (str[k] == ';')
			{
				print_error("morty$: ", SY_TO, ";'\n");
				return (258);
			}
		}
		*i = *i + 1;
	}
	return (0);
}

void	checker(char *str, int *i)
{
	if (str[*i] == '\\' || !is_spec(str[*i]) || str[*i] == '$')
	{
		if (str[*i] == '/')
			g_mini.sl = 1;
		*i = *i + 1;
	}
	if (str[*i] == '"')
	{
		*i = *i + 1;
		while (str[*i] && str[*i] != '"')
			*i = *i + 1;
		if (str[*i] == '"')
			*i = *i + 1;
	}
	if (str[*i] == '\'')
	{
		*i = *i + 1;
		while (str[*i] && str[*i] != '\'')
			*i = *i + 1;
		if (str[*i] == '\'')
			*i = *i + 1;
	}
}

int	gnl4(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_space(str[i]))
		i++;
	if (token(str, &i) == 258)
		return (258);
	while (str[i])
	{
		checker(str, &i);
		if (dotcom(str, &i) == 258)
			return (258);
		if (palka(str, &i) == 258)
			return (258);
		if (str[i] == '>')
			if (bolshe(str, &i) == 258)
				return (258);
		if (str[i] == '<')
			if (menshe(str, &i) == 258)
				return (258);
	}
	return (0);
}
