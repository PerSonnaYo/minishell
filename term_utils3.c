#include "minishell.h"

void	del(void)
{
	char	*ost;
	int		i;

	if (g_mini.ter.col < g_mini.ter.len && g_mini.ter.col >= 8)
	{
		ost = ft_strdup(&g_mini.ter.temp[g_mini.ter.col - 7]);
		tputs(tgetstr("cd", 0), 1, ft_putint);
		i = 0;
		tputs(tgetstr("sc", 0), 1, ft_putint);
		while (ost[i])
			write(g_mini.fd, &ost[i++], 1);
		tputs(tgetstr("rc", 0), 1, ft_putint);
		g_mini.ter.temp = dell(g_mini.ter.temp, g_mini.ter.col - 8);
		g_mini.ter.len--;
		if (g_mini.ter.len > tgetnum("co"))
			g_mini.ter.tmp = g_mini.ter.len / tgetnum("co");
		else
			g_mini.ter.tmp = 0;
		if (g_mini.ter.col > tgetnum("co"))
			g_mini.ter.end = g_mini.ter.col / tgetnum("co");
		else
			g_mini.ter.end = 0;
		free(ost);
	}
}

void	del_hist(char **history, int j)
{
	char	*host;
	int		i;

	if (g_mini.ter.col < g_mini.ter.len && g_mini.ter.col >= 8)
	{
		host = ft_strdup(&(history[j])[g_mini.ter.col - 7]);
		tputs(tgetstr("cd", 0), 1, ft_putint);
		i = 0;
		tputs(tgetstr("sc", 0), 1, ft_putint);
		while (host[i])
			write(g_mini.fd, &host[i++], 1);
		tputs(tgetstr("rc", 0), 1, ft_putint);
		history[j] = dell(history[j], g_mini.ter.col - 8);
		g_mini.ter.len--;
		if (g_mini.ter.len > tgetnum("co"))
			g_mini.ter.tmp = g_mini.ter.len / tgetnum("co");
		else
			g_mini.ter.tmp = 0;
		if (g_mini.ter.col > tgetnum("co"))
			g_mini.ter.end = g_mini.ter.col / tgetnum("co");
		else
			g_mini.ter.end = 0;
		free(host);
	}
}

void	home(void)
{
	int	k;

	tputs(tgetstr("cr", 0), 1, ft_putint);
	k = 0;
	while (k < g_mini.ter.end)
	{
		k++;
		tputs(tgetstr("up", 0), 1, ft_putint);
	}
	g_mini.ter.end = 0;
	tputs(tgetstr("bl", 0), 1, ft_putint);
	g_mini.ter.col = 8;
	k = 0;
	while (k < 7)
	{
		tputs(tgetstr("nd", 0), 1, ft_putint);
		k++;
	}
}

int	flag_res(void)
{
	int	flag;

	flag = 0;
	while (g_mini.ter.end < g_mini.ter.tmp)
	{
		tputs(tgetstr("do", 0), 1, ft_putint);
		g_mini.ter.end++;
		flag = 1;
	}
	return (flag);
}

void	end(void)
{
	int	flag;

	flag = flag_res();
	if (flag == 1)
	{
		g_mini.ter.col = g_mini.ter.tmp * tgetnum("co") + 1;
		while (g_mini.ter.col < g_mini.ter.len)
		{
			tputs(tgetstr("nd", 0), 1, ft_putint);
			g_mini.ter.col++;
		}
	}
	else
	{
		while (g_mini.ter.col < g_mini.ter.len)
		{
			tputs(tgetstr("nd", 0), 1, ft_putint);
			g_mini.ter.col++;
		}
	}
	tputs(tgetstr("bl", 0), 1, ft_putint);
}
