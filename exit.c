#include "minishell.h"

int	code_n(t_buld *gen)
{
	long long	tmp;
	int			code;

	tmp = ft_atoi(gen->str[1]);
	if (tmp > 2147483647 || tmp < -2147483647)
	{
		print_error("\x1b[31m""exit: ", gen->str[1], EX_NU);
		exit(255);
	}
	code = (int)tmp % 256;
	if (gen->str[2] != NULL)
	{
		ft_putstr_fd(EX_TO, 2);
		return (1);
	}
	else
		exit((int) code);
}

int	lun_exi(t_buld *gen)
{
	int	i;

	if (gen->str[1] == NULL)
		exit(g_mini.qua);
	else
	{
		i = 0;
		if (gen->str[1][i] == '-')
			i++;
		while (gen->str[1][i] && ft_isdigit(gen->str[1][i]))
			i++;
		if (!gen->str[1][i])
			return (code_n(gen));
		else
		{
			print_error("\x1b[31m""exit: ", gen->str[1], EX_NU);
			exit(255);
		}
	}
}
