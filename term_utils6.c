#include "minishell.h"

void	printchar(char c)
{
	char	*ost;
	char	*mm;

	ost = ft_strdup(&g_mini.ter.temp[g_mini.ter.col - 8]);
	tputs(tgetstr("sc", 0), 1, ft_putint);
	tputs(tgetstr("ce", 0), 1, ft_putint);
	g_mini.ter.temp = beg(g_mini.ter.temp, g_mini.ter.col - 8);
	write(g_mini.fd, &c, 1);
	if (ost[0] != '\0')
		insert(ost);
	g_mini.ter.col++;
	g_mini.ter.len++;
	mm = (char *) malloc(sizeof(char) * 2);
	mm[0] = c;
	mm[1] = '\0';
	g_mini.ter.temp = ft_strjoin1(g_mini.ter.temp, mm);
	g_mini.ter.temp = ft_strjoin1(g_mini.ter.temp, ost);
	if (g_mini.ter.len > tgetnum("co"))
		g_mini.ter.tmp = g_mini.ter.len / tgetnum("co");
	if (g_mini.ter.col > tgetnum("co"))
		g_mini.ter.end = g_mini.ter.col / tgetnum("co");
	free(ost);
	free(mm);
}

void	insert_hist(char *host, char **history, int j)
{
	int		l;
	int		l1;
	int		nk;
	int		yyy;

	(void)history;
	(void)j;
	get_cursor_position(&l, &l1);
	tputs(tgetstr("sc", 0), 1, ft_putint);
	yyy = 0;
	if (l1 == tgetnum("li") - 1 && g_mini.ter.len % tgetnum("co") == 0)
		last_l(&yyy, host);
	nk = 0;
	while (host[nk])
	{
		ft_putchar_fd(host[nk], g_mini.fd);
		nk++;
	}
	if (yyy == 0)
		tputs(tgetstr("rc", 0), 1, ft_putint);
	if (g_mini.ter.col % tgetnum("co") == 0)
		tputs(tgetstr("do", 0), 1, ft_putint);
}

void	printchar_hist(char c, char **history, int j)
{
	char	*host;
	char	*cc;

	host = ft_strdup(&(history[j])[g_mini.ter.col - 8]);
	tputs(tgetstr("sc", 0), 1, ft_putint);
	tputs(tgetstr("ce", 0), 1, ft_putint);
	history[j] = beg(history[j], g_mini.ter.col - 8);
	write(g_mini.fd, &c, 1);
	if (host[0] != '\0')
		insert_hist(host, history, j);
	g_mini.ter.col++;
	g_mini.ter.len++;
	cc = (char *)malloc(sizeof(char) * 2);
	cc[0] = c;
	cc[1] = '\0';
	history[j] = ft_strjoin1(history[j], cc);
	history[j] = ft_strjoin1(history[j], host);
	if (g_mini.ter.len > tgetnum("co"))
		g_mini.ter.tmp = g_mini.ter.len / tgetnum("co");
	if (g_mini.ter.col > tgetnum("co"))
		g_mini.ter.end = g_mini.ter.col / tgetnum("co");
	free(host);
	free(cc);
}

void	fill_hist(int file, char **history)
{
	char	*hist;
	int		index;

	hist = NULL;
	index = 0;
	while (get_next_line(file, &hist) > 0)
	{
		history[index] = ft_strdup(hist);
		index++;
		free(hist);
	}
	free(hist);
	history[index] = NULL;
}
