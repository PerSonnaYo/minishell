#include "minishell.h"

char	*get_key(char *arg)
{
	int		i;
	int		k;
	char	*res;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	k = 0;
	res = (char *)malloc(sizeof(char) * i + 1);
	while (k < i)
	{
		res[k] = arg[k];
		k++;
	}
	res[k] = '\0';
	return (res);
}

char	*get_value(char *arg)
{
	int		i;
	int		k;
	char	*res;

	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	if (!arg[i])
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(arg) - i + 2));
	res[0] = '"';
	k = 1;
	i++;
	while (arg[i])
	{
		res[k] = arg[i];
		k++;
		i++;
	}
	res[k] = '"';
	res[k + 1] = '\0';
	return (res);
}

char	*set_value(char *arg, char *value, char **env)
{
	int		i;
	int		j;
	char	*res;
	char	*temp;

	temp = ret_word(value, env);
	i = 0;
	while (arg[i] && arg[i] != '=')
		i++;
	res = (char *)malloc(sizeof(char) * (ft_strlen(temp) + i + 2));
	i = 0;
	while (arg[i] && arg[i] != '=')
	{
		res[i] = arg[i];
		i++;
	}
	res[i] = '=';
	i++;
	j = 0;
	while (temp[j])
		res[i++] = temp[j++];
	res[i] = '\0';
	free(arg);
	free(temp);
	return (res);
}

int	env_size(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

void	sort(t_buld *arg)
{
	int		i;
	int		k;
	char	*str;
	char	*str1;

	k = 1;
	while (k < env_size(arg->env))
	{
		i = 0;
		while (i < env_size(arg->env) - k)
		{
			if (ft_strcmp(arg->env[i], arg->env[i + 1]) > 0)
			{
				str = arg->env[i];
				arg->env[i] = ft_strdup(arg->env[i + 1]);
				str1 = arg->env[i + 1];
				arg->env[i + 1] = ft_strdup(str);
				free (str);
				free (str1);
			}
			i++;
		}
		k++;
	}
}
