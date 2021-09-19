#include "minishell.h"

void	check_lines(void)
{
	if (g_mini.ter.len > tgetnum("co"))
		g_mini.ter.tmp = g_mini.ter.len / tgetnum("co");
	else
		g_mini.ter.tmp = 0;
	if (g_mini.ter.col > tgetnum("co"))
		g_mini.ter.end = g_mini.ter.col / tgetnum("co");
	else
		g_mini.ter.end = 0;
}

void	up_utils(void)
{
	int	k;

	k = 0;
	while (k < g_mini.ter.end)
	{
		tputs(tgetstr("up", 0), 1, ft_putint);
		k++;
	}
	tputs(tgetstr("cr", 0), 1, ft_putint);
	tputs(tgetstr("cd", 0), 1, ft_putint);
}

void	down_utils(void)
{
	int	k;

	tputs(tgetstr("dl", 0), 1, ft_putint);
	tputs(tgetstr("cd", 0), 1, ft_putint);
	k = 0;
	while (k < g_mini.ter.end)
	{
		tputs(tgetstr("up", 0), 1, ft_putint);
		tputs(tgetstr("dl", 0), 1, ft_putint);
		k++;
	}
	g_mini.ter.end = 0;
	tputs(tgetstr("cr", 0), 1, ft_putint);
	tputs(tgetstr("cd", 0), 1, ft_putint);
}

void	k_up(char **history, int *j)
{
	if (history[*j] != NULL)
	{
		up_utils();
		*j = *j + 1;
		if (!history[*j])
		{
			write(g_mini.fd, "morti$ ", 8);
			write(g_mini.fd, g_mini.ter.temp, ft_strlen(g_mini.ter.temp));
			g_mini.ter.len = ft_strlen(g_mini.ter.temp) + 8;
			g_mini.ter.col = g_mini.ter.len;
		}
		else
		{
			write(g_mini.fd, "morti$ ", 8);
			write(g_mini.fd, history[*j], ft_strlen(history[*j]));
			g_mini.ter.len = ft_strlen(history[*j]) + 8;
			g_mini.ter.col = g_mini.ter.len;
		}
		check_lines();
	}
}

void	k_down(char **history, int *j)
{
	down_utils();
	if (!history[*j])
	{
		*j = *j - 1;
		if (*j < 0)
			*j = *j + 1;
		write(g_mini.fd, "morti$ ", 8);
		write(g_mini.fd, history[*j], ft_strlen(history[*j]));
		g_mini.ter.len = ft_strlen(history[*j]) + 8;
		g_mini.ter.col = g_mini.ter.len;
	}
	else if (history[*j] && *j >= 0)
	{
		*j = *j - 1;
		if (*j == -1)
		{
			*j = 0;
			tputs(tgetstr("bl", 0), 1, ft_putint);
		}
		write(g_mini.fd, "morti$ ", 8);
		write(g_mini.fd, history[*j], ft_strlen(history[*j]));
		g_mini.ter.len = ft_strlen(history[*j]) + 8;
		g_mini.ter.col = g_mini.ter.len;
	}
	check_lines();
}
