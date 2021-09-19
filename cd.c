#include "minishell.h"

void	to_with(t_buld *gen, char **str)
{
	char	**s;
	char	*t2;
	char	buf[1024];

	s = (char **)malloc(sizeof(char *) * 3);
	s[0] = catch_value(gen, "PWD");
	s[1] = catch_value(gen, "OLDPWD");
	s[2] = NULL;
	if (s[0])
	{
		t2 = ft_strtrim(s[0], "\"");
		ch_old(gen, t2);
		free(t2);
	}
	else
		ch_old(gen, *str);
	*str = getcwd(buf, sizeof(buf));
	ch_pwd(gen, *str);
	ft_freetab(s);
}

void	to_without(t_buld *gen, char **str)
{
	char	**s;
	char	*t2;

	s = (char **)malloc(sizeof(char *) * 3);
	s[0] = catch_value(gen, "PWD");
	s[1] = catch_value(gen, "OLDPWD");
	s[2] = NULL;
	if (s[0])
	{
		t2 = ft_strtrim(s[0], "\"");
		ch_old(gen, t2);
		free(t2);
	}
	else
		ch_old(gen, *str);
	ft_freetab(s);
}

int	with_arg(t_buld *gen, char **str)
{
	int		tmp;

	tmp = chdir(gen->str[1]);
	if (tmp < 0)
	{
		print_error("cd: `", gen->str[1], CO_DF);
		return (1);
	}
	else
		to_with(gen, str);
	return (0);
}

int	without_arg(t_buld *gen, char **str)
{
	int		i;
	char	*t1;
	char	*t2;

	i = is_key(gen);
	if (change_null(i, gen) == 1)
		return (1);
	to_without(gen, str);
	t1 = get_value(gen->env[i]);
	t2 = ft_strtrim(t1, "\"");
	ch_pwd(gen, t2);
	free(t1);
	free(t2);
	return (0);
}

int	lun_cdd(t_buld *gen)
{
	static char	*str;

	if (ft_strcmp(gen->str[0], "cd") == 0)
	{
		if (gen->str[1] == NULL)
		{
			if (without_arg(gen, &str) == 1)
				return (1);
		}
		else
		{
			if (with_arg(gen, &str) == 1)
				return (1);
		}
	}
	return (0);
}
