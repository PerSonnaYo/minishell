#include "minishell.h"

void	add_toenv(t_buld *gen, int j, int i)
{
	char	*t3;

	if (!gen->env[j])
		newadd(gen, gen->str[i]);
	else
	{
		t3 = get_value(gen->str[i]);
		if (t3)
			gen->env[j] = set_value(gen->env[j], t3, gen->env);
		free(t3);
	}
}

int	match(t_buld *gen, char *t2)
{
	int		j;
	char	*t1;

	j = 0;
	while (gen->env[j])
	{
		t1 = get_key(gen->env[j]);
		if (ft_strcmp(t1, t2) == 0)
		{
			free(t1);
			break ;
		}
		free(t1);
		j++;
	}
	return (j);
}

int	lun_adexp(t_buld *gen)
{
	int		i;
	int		j;
	char	*t2;

	i = 1;
	while (gen->str[i])
	{
		if (!ft_isalpha(gen->str[i][0]))
		{
			print_error("morti$ :export: `", gen->str[i], EX_NV);
			return (1);
		}
		else
		{
			t2 = get_key(gen->str[i]);
			j = match(gen, t2);
			add_toenv(gen, j, i);
			free(t2);
		}
		i++;
	}
	return (0);
}
