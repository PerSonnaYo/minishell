#include "minishell.h"

int	eq_instr(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '=')
		return (1);
	else
		return (0);
}

void	delete_env(t_buld *gen, int j)
{
	int	i;

	i = 0;
	while (i < j)
		i++;
	j++;
	while (gen->env[j])
	{
		free(gen->env[i]);
		gen->env[i] = ft_strdup(gen->env[j]);
		i++;
		j++;
	}
	free(gen->env[i]);
	gen->env[i] = NULL;
}

int	matching(t_buld *gen, int i)
{
	int		j;
	int		flag;
	char	*tmp;

	j = 0;
	flag = 0;
	while (gen->env[j] && !flag)
	{
		tmp = get_key(gen->env[j]);
		if (ft_strcmp(tmp, gen->str[i]) == 0)
			flag = 1;
		else
			j++;
		free(tmp);
	}
	return (j);
}

int	lun_uns(t_buld *gen)
{
	int		i;
	int		j;

	if (ft_strcmp(gen->str[0], "unset") == 0)
	{
		i = 1;
		while (gen->str[i])
		{
			if (eq_instr(gen->str[i]))
				print_error("unset: `", gen->str[i], EX_NV);
			else if (ft_isdigit(gen->str[i][0]))
				print_error("unset: `", gen->str[i], EX_NV);
			else
			{
				j = matching(gen, i);
				if (gen->env[j] != NULL)
					delete_env(gen, j);
			}
			i++;
		}
	}
	return (1);
}
