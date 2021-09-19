#include "minishell.h"

void	p_down(void)
{
	int	l;
	int	l1;

	get_cursor_position(&l, &l1);
	if (g_mini.ter.tmp > g_mini.ter.end)
	{
		tputs(tgoto(tgetstr("cv", 0), 0, l1 + 1), 1, ft_putint);
		g_mini.ter.col = g_mini.ter.col + tgetnum("co");
		g_mini.ter.end++;
	}
	if (g_mini.ter.end == g_mini.ter.tmp && (g_mini.ter.len <= g_mini.ter.col))
	{
		g_mini.ter.col = g_mini.ter.len;
		tputs(tgoto(tgetstr("ch", 0), 0, g_mini.ter.len - \
		tgetnum("co") * g_mini.ter.end - 1), 1, ft_putint);
	}
}

void	p_up(void)
{
	int	l;
	int	l1;

	get_cursor_position(&l, &l1);
	if (g_mini.ter.end > 0)
	{
		tputs(tgoto(tgetstr("cv", 0), 0, l1 - 1), 1, ft_putint);
		g_mini.ter.col = g_mini.ter.col - tgetnum("co");
		g_mini.ter.end--;
	}
	if (g_mini.ter.end == 0 && (8 >= g_mini.ter.col))
	{
		g_mini.ter.col = 8;
		tputs(tgoto(tgetstr("ch", 0), 0, 7), 1, ft_putint);
	}
}

void	escape(char **history, int *j, int index)
{
	int		rd;
	char	buffer[5];

	rd = read (STDIN_FILENO, buffer, 5);
	buffer[rd] = '\0';
	if (strcmp (buffer, "[C") == 0)
		k_left(&g_mini.ter);
	if (strcmp (buffer, "[D") == 0)
		k_right(&g_mini.ter);
	if (strcmp (buffer, "[B") == 0)
		k_up(history, &(*j));
	if (strcmp (buffer, "[A") == 0 && index != 0)
		k_down(history, &(*j));
	if (strcmp (buffer, "[3~") == 0)
		fin_del(history, *j);
	if (strcmp (buffer, "[H") == 0)
		home();
	if (strcmp (buffer, "[F") == 0)
		end();
	if (strcmp (buffer, "[1;5B") == 0)
		p_down();
	if (strcmp (buffer, "[1;5A") == 0)
		p_up();
}

void	ctrl_d(void)
{
	int		i;
	char	*ost;

	if (g_mini.ter.temp[0] == '\0')
	{
		write(2, " exit\n", 6);
		restore_tty (STDIN_FILENO);
		exit(g_mini.qua);
	}
	else if (g_mini.ter.col <= g_mini.ter.len && \
	g_mini.ter.len >= g_mini.ter.col + 1)
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
		check_lines();
		free(ost);
	}
}
