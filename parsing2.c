#include "minishell.h"

int	gmini_slash(int i, char *str, char **gen)
{
	g_mini.pars_wil[2] = 3;
	i = slash(str, i, gen);
	return (i);
}

int	gmini_dol(int i, char *str, char **gen, char **env)
{
	g_mini.pars_wil[2] = 3;
	i = parcer_doll(&(*gen), str, i, env);
	return (i);
}

int	gmini_kov2(int i, char *str, char **gen, char **env)
{
	g_mini.pars_wil[2] = 3;
	i = parser_kov2(&(*gen), str, i, env);
	return (i);
}

int	gmini_kov(int i, char *str, char **gen)
{
	g_mini.pars_wil[2] = 3;
	i = parser_kov(&(*gen), str, i);
	return (i);
}
