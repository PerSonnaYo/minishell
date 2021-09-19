#include "minishell.h"

char	*catch_value(t_buld *gen, char *str)
{
	char	*s;
	int		i;

	i = 0;
	while (gen->env[i])
	{
		s = get_key(gen->env[i]);
		if (ft_strcmp(s, str) == 0)
		{
			free(s);
			break ;
		}
		i++;
		free(s);
	}
	if (!gen->env[i])
		return (NULL);
	else
	{
		s = get_value(gen->env[i]);
		return (s);
	}
}

void	ch_pwd(t_buld *gen, char *new_pwd)
{
	int		i;
	char	*temp;

	i = 0;
	while (gen->env[i])
	{
		temp = get_key(gen->env[i]);
		if (ft_strcmp(temp, "PWD") == 0)
		{
			free(temp);
			break ;
		}
		i++;
		free(temp);
	}
	if (gen->env[i])
	{
		temp = gen->env[i];
		gen->env[i] = ft_strjoin("PWD=", new_pwd);
		free(temp);
	}
}

void	ch_old(t_buld *gen, char *old_pwd)
{
	int		i;
	char	*t1;

	i = 0;
	while (gen->env[i])
	{
		t1 = get_key(gen->env[i]);
		if (ft_strcmp(t1, "OLDPWD") == 0)
		{
			free(t1);
			break ;
		}
		i++;
		free(t1);
	}
	if (gen->env[i])
	{
		t1 = gen->env[i];
		gen->env[i] = ft_strjoin("OLDPWD=", old_pwd);
		free(t1);
	}
}

int	is_key(t_buld *gen)
{
	int		i;
	char	*t1;

	i = 0;
	while (gen->env[i])
	{
		t1 = get_key(gen->env[i]);
		if (ft_strcmp(t1, "HOME") == 0)
		{
			free(t1);
			break ;
		}
		free(t1);
		i++;
	}
	return (i);
}

int	change_null(int i, t_buld *gen)
{
	char	*t1;
	char	*t2;

	if (gen->env[i])
	{
		t1 = get_value(gen->env[i]);
		t2 = ft_strtrim(t1, "\"");
		chdir(t2);
		free(t1);
		free(t2);
	}
	else
	{
		print_error("morti$: ", gen->str[0], HO_SE);
		return (1);
	}
	return (0);
}
