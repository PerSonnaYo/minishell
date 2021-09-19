#include "minishell.h"

void	init_gmini(void)
{
	g_mini.ter.col = 8;
	g_mini.ter.len = 8;
	g_mini.ter.end = 0;
	g_mini.ter.temp = ft_calloc(1, 1);
}

void	close_file(char **history, int j, int file, char **line)
{
	if (env_size(history) == j)
	{
		if (g_mini.ter.temp[0] != '\0' && g_mini.ter.temp[0] != '\n')
		{
			ft_putendl_fd(g_mini.ter.temp, file);
			*line = ft_strdup(g_mini.ter.temp);
		}
		close(file);
	}
	else
	{
		if (history[j][0] != '\n' && history[j][0] != '\0')
		{
			ft_putendl_fd(history[j], file);
			*line = ft_strdup(history[j]);
		}
		close(file);
	}
}

void	check_terminal(void)
{
	if (new_tty (STDIN_FILENO) == -1)
	{
		ft_putstr_fd("Not a terminal\n", 2);
		exit (-1);
	}
}

void	fin_ctrl(char **history, int j)
{
	if (env_size(history) == j)
		ctrl_d();
	else
		ctrl_dh(history, j);
}

void	fin_backspace(char **history, int j)
{
	if (env_size(history) == j)
		backspace();
	else
		backspace_hist(history, j);
}
