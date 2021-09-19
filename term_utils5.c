#include "minishell.h"

void	ctrl_dh(char **history, int j)
{
	char	*host;
	int		i;

	if (history[j][0] == '\0')
	{
		write(2, " exit\n", 6);
		restore_tty (STDIN_FILENO);
		exit(g_mini.qua);
	}
	else if (g_mini.ter.col <= g_mini.ter.len && \
	g_mini.ter.len >= g_mini.ter.col + 1)
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
		check_lines();
		free(host);
	}
}

void	backspace(void)
{
	char	*ost;

	if (g_mini.ter.col > 8)
	{
		ost = ft_strdup(&g_mini.ter.temp[g_mini.ter.col - 8]);
		tputs(tgetstr("kb", 0), 1, ft_putint);
		g_mini.ter.col--;
		tputs(tgetstr("cd", 0), 1, ft_putint);
		tputs(tgetstr("sc", 0), 1, ft_putint);
		write(g_mini.fd, ost, ft_strlen(ost));
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

void	backspace_hist(char **history, int j)
{
	char	*host;

	if (g_mini.ter.col > 8)
	{
		host = ft_strdup(&(history[j])[g_mini.ter.col - 8]);
		tputs(tgetstr("kb", 0), 1, ft_putint);
		g_mini.ter.col--;
		tputs(tgetstr("cd", 0), 1, ft_putint);
		tputs(tgetstr("sc", 0), 1, ft_putint);
		write(g_mini.fd, host, ft_strlen(host));
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

void	last_l(int *ppp, char *ost)
{
	char	*hhh;
	int		i;

	tputs(tgetstr("up", 0), 1, ft_putint);
	tputs(tgoto(tgetstr("ch", 0), 0, 8), 1, ft_putint);
	tputs(tgetstr("cd", 0), 1, ft_putint);
	*ppp = 1;
	hhh = ft_strdup(g_mini.ter.temp + g_mini.ter.len - \
			tgetnum("co") - tgetnum("co"));
	i = 0;
	while (i < tgetnum("co") * 2 - (int)ft_strlen(ost))
		ft_putchar_fd(hhh[i++], g_mini.fd);
	free(hhh);
}

void	insert(char *ost)
{
	int		i;
	int		l;
	int		l1;
	int		ppp;

	get_cursor_position(&l, &l1);
	tputs(tgetstr("sc", 0), 1, ft_putint);
	ppp = 0;
	if (l1 == tgetnum("li") - 1 && g_mini.ter.len % tgetnum("co") == 0)
		last_l(&ppp, ost);
	i = 0;
	while (ost[i])
		ft_putchar_fd(ost[i++], g_mini.fd);
	if (ppp == 0)
		tputs(tgetstr("rc", 0), 1, ft_putint);
	if (g_mini.ter.col % tgetnum("co") == 0)
		tputs(tgetstr("do", 0), 1, ft_putint);
}
