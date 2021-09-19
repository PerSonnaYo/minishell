#include "minishell.h"

int	star(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*')
			return (i);
		i++;
	}
	return (-1);
}

void	in_star(char **s1, char **gen, char *str, char **envy)
{
	int	i;

	i = star(*s1);
	if (i >= 0)
	{
		gen[0] = ft_substr(*s1, 0, i);
		i = parser_widcard(&gen[0], str, i, envy);
		if (g_mini.i == 1)
		{
			free(*s1);
			*s1 = ft_calloc(sizeof(char), 1);
			*s1 = ft_strjoin1(*s1, g_mini.post[0]);
			ft_freetab(g_mini.post);
		}
		else if (g_mini.i == 2)
		{
			free(*s1);
			*s1 = ft_calloc(sizeof(char), 1);
			*s1 = ft_strjoin1(*s1, g_mini.wid[0]);
			ft_freetab(g_mini.wid);
		}
		else
			free(gen[0]);
	}
}

void	redic_pars1(char **gen, char **envy, char *str, t_wil *wil)
{
	gen[0] = ft_calloc(sizeof(char), 1);
	while (str[wil->index] && ft_space(str[wil->index]))
		wil->index++;
	if (str[wil->index] != '\0')
		wil->index = parser_alpha(gen, str, wil->index, envy);
	g_mini.index = wil->index;
}

void	free_s1(char **gen)
{
	if (gen[0] && gen[0][0] == '\0')
	{
		free(gen[0]);
		gen[0] = NULL;
	}
}

int	ret_met(t_wil *wil, char *str, char **envy, t_fd **fdl)
{
	wil->index = wil->index + parser_redic(str + wil->index, envy, fdl);
	++wil->index;
	return (1);
}
