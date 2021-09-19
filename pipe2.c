#include "minishell.h"

void	close_pipe_fd(t_buld *gen)
{
	while (gen != NULL)
	{
		close(gen->fd[0]);
		close(gen->fd[1]);
		gen = gen->next;
	}
}

void	handle_pipe_result(t_buld *gen)
{
	int		status;

	while (gen != NULL)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, SIG_IGN);
		waitpid(g_mini.pid, &status, WUNTRACED);
		if (WTERMSIG(status) == 2)
			g_mini.qua = 130;
		else if (WTERMSIG(status) == 3)
			g_mini.qua = 131;
		else
			g_mini.qua = WEXITSTATUS(status);
		if (g_mini.qua == 131)
			printf("%s\n", "Quit: 3");
		gen = gen->next;
	}
}

void 	mister_popen_pipes(t_buld *gen)
{
	pipe_fd(gen);
	fork_pipe(gen);
	close_pipe_fd(gen);
	handle_pipe_result(gen);
}
