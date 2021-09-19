#include "minishell.h"

void	redic_pip(t_fd *fdl)
{
	while (fdl)
	{
		dup2(fdl->nbr, 1);
		fdl = fdl->next;
	}
}

void	redicor_pip(t_fd *fdl, int fd)
{
	while (fdl)
	{
		fdl->nbr = fd;
		fdl = fdl->next;
	}
}

int	ft_re_output(t_fd *fds)
{
	int	i;

	i = 0;
	while (fds)
	{
		i = fds->nbr;
		fds = fds->next;
	}
	return (i);
}

int	gnl_redic(t_buld *gen)
{
	int		res;
	char	*line;

	res = 1;
	ft_putstr_fd("> ", 0);
	line = NULL;
	mister_terminate(&line, 2);
	if (!ft_strcmp(line, gen->doubl_red))
		return (0);
	line = ft_strjoin1(line, "\n");
	write(1, line, ft_strlen(line));
	free(line);
	return (res);
}

void	redic_pip_double(t_buld *gen)
{
	int		pfd[2];
	pid_t	child_pid;
	int		res;

	res = 1;
	pipe(pfd);
	child_pid = fork();
	if (child_pid == 0)
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		while (res > 0)
			res = gnl_redic(gen);
		exit(EXIT_SUCCESS);
	}
	else if (child_pid < 0)
		ft_putstr_fd("Error", 2);
	close(pfd[1]);
	dup2(pfd[0], 0);
	waitpid(child_pid, 0, WUNTRACED);
}
