#include "minishell.h"

int	slash(char *str, int i, char **gen)
{
	char	s2[2];

	s2[0] = str[i + 1];
	s2[1] = '\0';
	*gen = ft_strjoin1(*gen, s2);
	i = i + 2;
	return (i);
}

int	wil_slash(char *str, int i, char **gen)
{
	g_mini.pars_wil[1] = 2;
	i = parser_simple(&(*gen), str, i);
	while (str[i] && str[i] == '/')
		i++;
	return (i);
}

int	parcer_star1(char *str, int i, char **gen)
{
	g_mini.pars_wil[2] = 3;
	i = parser_simple(&(*gen), str, i);
	return (i);
}

int	parser_star(char **gen, char *str, int i, char **env)
{
	while (str[i] && str[i] != '>' && str[i] != '<' && !ft_space(str[i]))
	{
		if (str[i] == 92)
			i = gmini_slash(i, str, gen);
		else if (str[i] == 36)
			i = gmini_dol(i, str, gen, env);
		else if (str[i] == 34)
			i = gmini_kov2(i, str, gen, env);
		else if (str[i] == '\'')
			i = gmini_kov(i, str, gen);
		else if (str[i] == '*')
		{
			while (str[i] && str[i] == '*')
				i++;
			g_mini.pars_wil[0] = 1;
			break ;
		}
		else if (str[i] == '/')
			i = wil_slash(str, i, gen);
		else
			i = parcer_star1(str, i, gen);
	}
	return (i);
}

int	parser_widcard(char **gen, char *str, int i, char **env)
{
	t_wil	wil;
	int		g[2];
	int		i1;

	init_mas();
	init_num(&g);
	i1 = i;
	++i;
	g[1] = first_wilcard((*gen), &wil);
	while (str[i] && !(ft_space(str[i])))
	{
		last_wilcard(&wil);
		g[0] = 1;
		i = parser_star(&wil.ju, str, i, env);
		if (g_mini.pars_wil[1] == 2)
			wil_buf(&wil, str, i);
		else if (g_mini.pars_wil[1] == 0 && g_mini.pars_wil[0] == 1)
			last_wil8(&wil);
		else if (g_mini.pars_wil[1] == 0 && g_mini.pars_wil[0] == 0 \
			&& g_mini.pars_wil[2] == 3)
			last_wil9(&wil);
	}
	loci_wil1(&wil);
	i = final_wilcard(i, i1, g, gen);
	return (i);
}
