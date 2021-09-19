#include "minishell.h"

void	childs_pipe1(t_buld *gen, char *argv)
{
	int	y;

	y = 0;
	mister_way(gen);
	y = execve(gen->str[0], &gen->str[0], gen->env);
	if (y < 0)
	{
		print_error(PROMT, argv, CO_NF);
		exit(127);
	}
}

void	childs_pipe(t_buld *gen)
{
	int		fdd;
	char	*argv;

	argv = gen->str[0];
	fdd = 0;
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
	ft_putstr_fd(g_mini.doub_red, 2);
	if (gen->doubl_red != NULL && gen->nbr == 0)
		redic_pip_double(gen);
	dup2(gen->nbr, 0);
	if (gen->next != NULL)
		dup2(gen->fd[1], 1);
	close(gen->fd[0]);
	fdd = mister_command_pip(gen);
	free(g_mini.doub_red);
	if (fdd == -1)
		childs_pipe1(gen, argv);
	if (fdd == 1)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	gend(t_buld *gen)
{
	gen = gen->next;
	while (gen != NULL)
	{
		close(gen->fd[0]);
		close(gen->fd[1]);
		gen = gen->next;
	}
}

void	pipe_fd(t_buld *gen)
{
	while (gen != NULL)
	{
		pipe(gen->fd);
		gen = gen->next;
	}
}

void	fork_pipe(t_buld *gen)
{
	while (gen != NULL)
	{
		if (ft_lstsize2(gen->fdl))
			gen->fd[1] = ft_re_output(gen->fdl);
		g_mini.pid = fork();
		if (g_mini.pid == 0)
		{
			gend(gen);
			childs_pipe(gen);
		}
		else if (g_mini.pid < 0)
			ft_putstr_fd("Error", 2);
		else
		{
			close(gen->fd[1]);
			if (gen->next != NULL)
				gen->next->nbr = gen->fd[0];
			gen = gen->next;
		}
	}
}
