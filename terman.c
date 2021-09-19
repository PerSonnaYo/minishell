#include "minishell.h"

t_glo	g_mini;

int	mister_fork_child(char **line)
{
	int	i;

	i = mister_terminate(line, 1);
	return (i);
}

int	mister_fork_parent(char *line, char **env, int pop)
{
	if (pop != 1)
	{
		mister_loop(line, env);
	}
	if (pop == 1)
		pop = 0;
	return (pop);
}

int	mister_fork(char **env)
{
	int		fdd[2];
	char	*line;

	fdd[1] = 0;
	while (fdd[1] == 0)
	{
		line = NULL;
		ft_putstr_fd(PROMT, 1);
		fdd[1] = mister_fork_child(&line);
		fdd[1] = mister_fork_parent(line, env, fdd[1]);
	}
	return (fdd[1]);
}

int	main (int argc, char **argv, char **env)
{
	int		res;
	char	str[1024];
	char	**envn;
	int		i;

	i = 0;
	(void)argv;
	(void)argc;
	g_mini.cvd = ft_strjoin(getcwd(str, sizeof(str)), "/hist.txt");
	envn = ft_calloc(1024, sizeof (char *));
	while (env[i])
	{
		envn[i] = ft_strdup(env[i]);
		i++;
	}
	res = mister_fork(envn);
	return (res);
}
