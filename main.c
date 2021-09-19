#include "minishell.h"

void	parser_wil_alpha(char **envy, char **gen, char *str, t_wil *wil)
{
	int	j;

	j = 0;
	gen[wil->num] = ft_calloc(sizeof(char), 1);
	wil->index = parser_alpha(&gen[wil->num], str, wil->index, envy);
	if (g_mini.i == 1)
		parser_help(gen, wil);
	else if (g_mini.i == 2)
	{
		while (g_mini.wid[j])
		{
			gen[wil->num] = ft_calloc(sizeof(char), 1);
			gen[wil->num] = ft_strjoin1(gen[wil->num], g_mini.wid[j]);
			free(g_mini.wid[j]);
			g_mini.wid[j] = NULL;
			wil->num++;
			j++;
		}
		free(g_mini.wid);
	}
	else
		wil->num++;
}

void	parser_loop(char **envy, char **gen, t_fd **fdl, char *str)
{
	t_wil	wil;

	wil.str = REAL;
	wil.index = (g_mini.index == 0) * num_space(str) + \
		(!(g_mini.index == 0)) * g_mini.index;
	wil.num = 1;
	while (str[wil.index] != '\0')
	{
		g_mini.i = 0;
		if (ft_space(str[wil.index]))
			wil.index++;
		else if (str[wil.index] == '>')
		{
			wil.index = wil.index + parser_redic(str + wil.index, envy, fdl);
			++wil.index;
		}
		else if (str[wil.index] == '<')
			parser_help1(gen, &wil, str, envy);
		else
			parser_wil_alpha(envy, gen, str, &wil);
	}
	doll_slas(&wil, gen, envy);
	gen[wil.num] = NULL;
}

int	mister_parser(t_buld **obj, char **envy, char *str, t_fd **fdl)
{
	char	**gen;
	int		pp;

	g_mini.index = 0;
	gen = malloc(sizeof(char *) * REAL);
	g_mini.i = 0;
	pp = gen_init(gen, envy, str, fdl);
	if (pp == 0)
	{
		ft_freetab(gen);
		return (0);
	}
	else if (pp == 2)
	{
		mister_link(obj, envy, gen, fdl);
		return (1);
	}
	parser_loop(envy, gen, fdl, str);
	mister_link(obj, envy, gen, fdl);
	return (1);
}

void	loop_continue(t_line *str, char **envn, t_buld *gen, t_fd *fdl)
{
	t_line	s1;
	int		j;

	j = 1;
	while (str->line != NULL)
	{
		s1.line = NULL;
		s1 = gnl3(&str->line);
		j = mister_parser(&gen, envn, s1.line, &fdl);
		free(s1.line);
	}
	if (j == 1)
		mister_popen_pipes(gen);
	free_elem(&gen);
	free_fd(&fdl);
}

int	mister_loop(char *line, char **envn)
{
	t_line		str;
	t_buld		*gen;
	t_fd		*fdl;

	init_fdl_gen(&gen, &fdl);
	while (line != NULL)
	{
		str.line = NULL;
		str = gnl2(&line);
		if (str.i > 0)
		{
			free(line);
			g_mini.qua = str.i;
			line = NULL;
		}
		else
		{
			if (g_mini.p == 1)
				loop_continue(&str, envn, gen, fdl);
			else
				loop_continue1(&str, envn, gen, fdl);
		}
		free(str.line);
	}
	return (0);
}
