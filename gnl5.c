#include "minishell.h"

int	perro(char *str)
{
	print_error("morty$: ", SY_TO, str);
	return (258);
}

int	cyc(char *str, int *i)
{
	int	k;

	k = *i + 1;
	while (str[k] && ft_space(str[k]))
		k++;
	if (!str[k])
		return (perro("newline'\n"));
	else if (str[k] == '>')
		return (perro(">'\n"));
	else if (str[k] == '<')
		return (perro("<'\n"));
	else if (str[k] == ';')
		return (perro(";'\n"));
	else if (str[k] == '|')
		return (perro("|'\n"));
	else
		*i = *i + 1;
	return (0);
}

int	bolshe(char *str, int *i)
{
	if (str[*i + 1] && str[*i + 1] == '<')
		return (perro("<'\n"));
	else if (str[*i + 1] && str[*i + 1] == '>' && \
	str[*i + 2] && str[*i + 2] == '>')
		return (perro(">'\n"));
	else if (str[*i + 1] && str[*i + 1] == '>' && \
	str[*i + 2] && str[*i + 2] == '<')
		return (perro("<'\n"));
	else
	{
		if (str[*i + 1] == '>')
			*i = *i + 1;
		if (cyc(str, i) == 258)
			return (258);
	}
	return (0);
}

int	menshe(char *str, int *i)
{
	if (str[*i + 1] && str[*i + 1] == '<' && str[*i + 2] && str[*i + 2] == '>')
		return (perro(">'\n"));
	else if (str[*i + 1] && str[*i + 1] == '<' && \
	str[*i + 2] && str[*i + 2] == '<')
		return (perro("<'\n"));
	else
	{
		if (str[*i + 1] == '<')
			*i = *i + 1;
		if (cyc(str, i) == 258)
			return (258);
	}
	return (0);
}

int	token(char *str, int *i)
{
	if (str[*i] == ';')
	{
		if (str[*i + 1] && str[*i + 1] == ';')
			print_error("morty$: ", SY_TO, ";;'\n");
		else
			print_error("morty$: ", SY_TO, ";'\n");
		return (258);
	}
	if (str[*i] == '|')
	{
		if (str[*i + 1] && str[*i + 1] == '|')
			print_error("morty$: ", SY_TO, "||'\n");
		else
			print_error("morty$: ", SY_TO, "|'\n");
		return (258);
	}
	if (str[*i] == '>')
		if (bolshe(str, i) == 258)
			return (258);
	if (str[*i] == '<')
		if (menshe(str, i) == 258)
			return (258);
	return (0);
}
