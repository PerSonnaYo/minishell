#include "minishell.h"

int	err_read(void)
{
	ft_putstr_fd("Error read", 2);
	restore_tty (STDIN_FILENO);
	return (1);
}

int	ctrl_c(char **history)
{
	tcsetattr(0, TCSANOW, &g_mini.BACKUP_TTY);
	while (g_mini.ter.tmp - g_mini.ter.end > -1)
	{
		ft_putstr_fd("\n", g_mini.fd);
		g_mini.ter.end++;
	}
	g_mini.qua = 1;
	free(g_mini.ter.temp);
	ft_freetab1(history);
	return (1);
}

int	if_else(char c, char **history, int *j)
{
	if (c == 27)
		escape(history, &(*j), env_size(history));
	else if (c == '\004')
		fin_ctrl(history, *j);
	else if (c == '\177')
		fin_backspace(history, *j);
	else if (c == 3)
		return (ctrl_c(history));
	else if (c == 28)
		;
	else if (c != '\n' && env_size(history) == *j)
		printchar(c);
	else if (c != '\n' && env_size(history) != *j)
		printchar_hist(c, history, *j);
	return (0);
}

int	cycle_main(char **history, int *j)
{
	char	c;

	c = '\0';
	while (c != '\n')
	{
		if (read (STDIN_FILENO, &c, 1) < 1)
			return (err_read());
		if (c == '\n')
		{
			write(g_mini.fd, "\n", 1);
			break ;
		}
		if (if_else(c, history, j) == 1)
			return (1);
	}
	return (0);
}

int	mister_terminate(char **line, int fork)
{
	int		j;
	int		file;
	char	*history[1024];

	g_mini.fd = fork;
	file = open(g_mini.cvd, O_RDWR | O_CREAT | O_APPEND, 0777);
	fill_hist(file, history);
	j = env_size(history);
	init_gmini();
	check_terminal();
	if (tgetent(0, getenv("TERM")) == -1)
		return (1);
	if (cycle_main(history, &j) == 1)
		return (1);
	close_file(history, j, file, line);
	while (g_mini.ter.tmp - g_mini.ter.end > 0)
	{
		ft_putstr_fd("\n", g_mini.fd);
		g_mini.ter.end++;
	}
	ft_freetab1(history);
	free(g_mini.ter.temp);
	restore_tty (STDIN_FILENO);
	return (0);
}
