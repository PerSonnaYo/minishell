#include "minishell.h"

void	wil_buf(t_wil *wil, char *str, int i)
{
	last_wil0(wil);
	last_wil2(wil);
	last_wil4(wil, str, i);
	free(wil->ju);
}

void	init_mas(void)
{
	g_mini.wid = ft_calloc(8192, sizeof(char *));
	g_mini.post = ft_calloc(8192, sizeof(char *));
}

int	papka(char *gen)
{
	struct stat	buf;
	DIR			*ty;

	if (!stat(gen, &buf))
	{
		ty = opendir(gen);
		if (ty)
		{
			closedir(ty);
			return (1);
		}
	}
	return (0);
}

int	final_wilcard(int i, int il, int *g, char **gen)
{
	if ((g[0] == 1 && g_mini.post[0] == NULL) || \
		(g[1] == 1 && g_mini.wid[0] == NULL))
	{
		ft_freetab(g_mini.wid);
		ft_freetab(g_mini.post);
		return (il);
	}
	if (g_mini.post[0] == NULL)
	{
		g_mini.i = 2;
		free(g_mini.post);
		free(*gen);
	}
	else
	{
		ft_freetab(g_mini.wid);
		g_mini.i = 1;
		free(*gen);
	}
	return (i);
}

int	*init_num(int (*t)[2])
{
	(*t)[0] = 0;
	(*t)[1] = 0;
	return (0);
}
