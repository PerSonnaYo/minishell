#include "minishell.h"

int	lun_prexp(t_buld *gen)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	sort(gen);
	i = 0;
	while (gen->env[i])
	{
		tmp = get_key(gen->env[i]);
		if (ft_strcmp(tmp, "_") != 0)
		{
			tmp2 = get_value(gen->env[i]);
			if (tmp2)
				printf("declare -x %s=%s\n", tmp, tmp2);
			else
				printf("declare -x %s\n", gen->env[i]);
			free(tmp);
			free(tmp2);
		}
		else
			free(tmp);
		i++;
	}
	return (0);
}
