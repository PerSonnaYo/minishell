#include "minishell.h"

void	doll_slas(t_wil *wil, char **gen, char **envy)
{
	if (wil->num == 1 && ft_strcmp(gen[0], "env") == 0)
		add_envd("/usr/bin/env", envy);
	else
		add_envd(gen[wil->num - 1], envy);
}

int	redic_pars(char **gen, char **envy, char *str, t_fd **fdl)
{
	t_wil	wil;
	int		met;

	wil.index = 0;
	met = 0;
	while (str[wil.index])
	{
		if (ft_space(str[wil.index]))
			wil.index++;
		if (str[wil.index] == '>')
			met = ret_met(&wil, str, envy, fdl);
		else if (str[wil.index] == '<')
		{
			parser_help1(gen, &wil, str, envy);
			met = 1;
		}
		else
			break ;
	}
	if (met == 1 && wil.index <= (int)ft_strlen(str))
		redic_pars1(gen, envy, str, &wil);
	return (met);
}

int	gen_init(char **gen, char **envy, char *str, t_fd **fdl)
{
	char	*s1;
	int		y;

	g_mini.fdu = 0;
	g_mini.doub_red = NULL;
	gen[0] = NULL;
	y = redic_pars(gen, envy, str, fdl);
	free_s1(gen);
	if (gen[0] == NULL && y == 0)
	{
		s1 = ret_word(str, envy);
		in_star(&s1, gen, str, envy);
		gen[0] = ft_calloc(sizeof(char), 1);
		gen[0] = ft_strjoin1(gen[0], s1);
		y = ret_y(&s1);
		if (y == 0 || y == 2)
			return (y);
		free(s1);
	}
	if (gen[0] == NULL)
		return (0);
	return (1);
}

void	parser_help(char **gen, t_wil *wil)
{
	int	j;

	j = 0;
	while (g_mini.post[j])
	{
		gen[wil->num] = ft_calloc(sizeof(char), 1);
		gen[wil->num] = ft_strjoin1(gen[wil->num], g_mini.post[j]);
		free(g_mini.post[j]);
		g_mini.post[j] = NULL;
		wil->num++;
		j++;
	}
	free(g_mini.post);
}

void	parser_help1(char **gen, t_wil *wil, char *str, char **envy)
{
	int	malo;

	(void)gen;
	malo = 0;
	wil->index = wil->index + parser_redicre(str + wil->index, \
		envy, &malo);
	g_mini.fdu = malo;
	++wil->index;
}
