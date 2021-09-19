#include "minishell.h"

int	lun_env(t_buld *gen)
{
	int	i;

	i = 0;
	while (gen->env[i])
	{
		if (get_value(gen->env[i]))
		{
			ft_putstr_fd(gen->env[i], 1);
			ft_putchar_fd('\n', 1);
		}
		i++;
	}
	return (0);
}
