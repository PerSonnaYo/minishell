#include "minishell.h"

int	parser_alpha(char **gen, char *str, int i, char **env)
{
	int	poti;

	while (str[i] && str[i] != '>' && str[i] != '<' && !ft_space(str[i]))
	{
		if (str[i] == 92)
			i = slash(str, i, gen);
		else if (str[i] == 36)
		{
			i = parcer_doll(&(*gen), str, i, env);
		}
		else if (str[i] == 34)
			i = parser_kov2(&(*gen), str, i, env);
		else if (str[i] == '\'')
			i = parser_kov(&(*gen), str, i);
		else if (str[i] == '*')
		{
			poti = i;
			i = parser_widcard(&(*gen), str, i, env);
			if (poti == i)
				i = parser_alpha1(&(*gen), str, i, env);
		}
		else
			i = parser_simple(gen, str, i);
	}
	return (i);
}

void	loci_wil(t_wil *wil)
{
	free(wil->ju);
	wil->buf = ft_realloc_pars(g_mini.wid);
}

void	loci_wil1(t_wil *wil)
{
	free(wil->tmp);
	wil->tmp = NULL;
	ft_freetab(wil->buf);
}
