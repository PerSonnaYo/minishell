#include "minishell.h"

char	*get_env(char **env, char *l)
{
	char	*key;
	char	*tmp;
	int		i;

	i = 0;
	key = ft_strdup(l);
	while (env[i])
	{
		if (!ft_strncmp(env[i], key, ft_strlen(key)))
		{
			tmp = ft_strdup(get_value(env[i]));
			tmp = ft_strtrim(tmp, "\"");
			free(key);
			return (tmp);
		}
		i++;
	}
	free(key);
	return (NULL);
}

void	dop_way(char *str, DIR *dir)
{
	print_error(PROMT, str, CO_DI);
	closedir(dir);
	exit(126);
}

int	way1(t_buld *gen)
{
	DIR			*ty;
	struct stat	buf;

	if (!stat(gen->str[0], &buf))
	{
		ty = opendir(gen->str[0]);
		if (!ty)
		{
			if (!(buf.st_mode & (S_IXGRP | S_IXUSR | S_IXOTH)))
			{
				print_error(PROMT, gen->str[0], PE_DI);
				exit(126);
			}
			return (1);
		}
		else
			dop_way(gen->str[0], ty);
	}
	else if (g_mini.sl > 0)
	{
		print_error(PROMT, gen->str[0], CO_DF);
		exit(127);
	}
	return (0);
}

int 	way2(t_buld *gen, char **ju, char *file_name)
{
	char		*ptir;
	int			i;
	struct stat	buf;

	i = 0;
	while (ju[i])
	{
		ju[i] = ft_strjoin1(ju[i], "/");
		ptir = ft_strjoin(ju[i], gen->str[0]);
		if (!stat(ptir, &buf))
		{
			gen->str[0] = ft_substr(ptir, 0, ft_strlen(ptir));
			free(file_name);
			ft_freetab(ju);
			return (1);
		}
		free(ptir);
		i++;
	}
	return (0);
}

void	mister_way(t_buld *gen)
{
	char	**ju;
	char	*file_name;

	if (way1(gen) == 1)
		return ;
	file_name = get_env(gen->env, "PATH=");
	if (file_name == NULL)
	{
		gen->str[0] = NULL;
		return ;
	}
	ju = ft_split(file_name, ':');
	if (way2(gen, ju, file_name) == 1)
		return ;
	free(file_name);
	ft_freetab(ju);
	gen->str[0] = NULL;
}
