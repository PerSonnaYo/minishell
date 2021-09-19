#include "minishell.h"

void	add_envd1(char *str, char **env, int i)
{
	char	*temp;

	if (g_mini.pipe == 1)
	{
		temp = env[i];
		env[i] = ft_strdup("_=");
		free(temp);
	}
	if (env[i])
	{
		temp = env[i];
		env[i] = ft_strdup("_=");
		env[i] = ft_strjoin1(env[i], str);
		free(temp);
	}
	else
	{
		temp = env[i];
		env[i] = ft_strdup("_=");
		env[i] = ft_strjoin1(env[i], str);
		env[i + 1] = NULL;
		free(temp);
	}
}

void	add_envd(char *str, char **env)
{
	int		i;
	char	*key;

	i = 0;
	while (env[i])
	{
		key = get_key(env[i]);
		if (ft_strcmp(key, "_") == 0)
		{
			free(key);
			break ;
		}
		else
		{
			i++;
			free(key);
		}
	}
	add_envd1(str, env, i);
}

void	loop_continue1(t_line *str, char **envn, t_buld *gen, t_fd *fdl)
{
	int	j;

	j = 1;
	j = mister_parser(&gen, envn, str->line, &fdl);
	if (j == 1)
		mister_popen(gen);
	free_elem(&gen);
	free_fd(&fdl);
}

void	init_fdl_gen(t_buld **gen, t_fd **fdl)
{
	*gen = NULL;
	*fdl = NULL;
}
