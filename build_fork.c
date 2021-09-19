#include "minishell.h"

void	signalc(int signum)
{
	signum = 0;
	signal(SIGINT, &signalc);
	ft_putstr_fd("\n", 1);
}

void	parent_error(int status)
{
	if (WIFEXITED(status) != 0)
		g_mini.qua = WEXITSTATUS(status);
	else if (WTERMSIG(status) == 2)
		g_mini.qua = 130;
	else if (WTERMSIG(status) == 3)
	{
		printf("%s\n", "Quit: 3");
		g_mini.qua = 131;
	}
}

void	child_pid(t_buld *gen, t_fd *fdl, char *argv)
{
	int	status;
	int	y;

	y = 0;
	redicor(fdl);
	if (g_mini.fdu != 0)
		dup2(g_mini.fdu, 0);
	else if (gen->doubl_red != NULL)
		redic_pip_double(gen);
	status = mister_exit(gen);
	if (status < 0)
	{
		mister_way(gen);
		y = execve(gen->str[0], &gen->str[0], gen->env);
		if (y < 0)
		{
			print_error(PROMT, argv, CO_NF);
			exit(127);
		}
	}
	if (status == 1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	mister_launch(t_buld *gen, t_fd *fdl)
{
	pid_t	pid1;
	int		status;
	char	*argv;

	argv = gen->str[0];
	g_mini.pid = fork();
	if (g_mini.pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, &signalc);
		child_pid(gen, fdl, argv);
	}
	else if (g_mini.pid < 0)
		ft_putstr_fd("Error", 2);
	else
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, SIG_IGN);
		pid1 = waitpid(g_mini.pid, &status, WUNTRACED);
		parent_error(status);
	}
}

int	mister_popen(t_buld *gen)
{
	int		y;
	t_line	io;

	y = ret_int(&io, gen);
	if (y == 1)
	{
		y = mister_exit1(io, gen);
		if (y != -1)
		{
			g_mini.qua = y;
			return (1);
		}
		mister_launch(gen, gen->fdl);
	}
	close_fd(gen->fdl);
	return (1);
}
