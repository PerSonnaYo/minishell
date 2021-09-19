#include "minishell.h"

void	newadd(t_buld *gen, char *str)
{
	int		i;

	i = 0;
	while (gen->env[i])
		i++;
	gen->env[i] = ft_strdup(str);
	gen->env[i + 1] = NULL;
}

int	lun_exp(t_buld *gen)
{
	if (ft_strcmp(gen->str[0], "export") == 0)
	{
		if (gen->str[1] == NULL)
			return (lun_prexp(gen));
		else
			return (lun_adexp(gen));
	}
	return (1);
}
