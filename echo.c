#include "minishell.h"

int	lun_ech(t_buld *gen)
{
	int	i;
	int	flag;
	int	fd;

	fd = 1;
	i = 1;
	flag = 0;
	if (gen->str[1] && gen->str[1][0] == '-' && gen->str[1][1] == \
	'n' && gen->str[1][2] =='\0')
	{
		flag = 1;
		i++;
	}
	while (gen->str[i + 1])
	{
		ft_putstr_fd(gen->str[i], fd);
		ft_putchar_fd(' ', fd);
		i++;
	}
	ft_putstr_fd(gen->str[i], fd);
	if (flag == 0)
		ft_putchar_fd('\n', fd);
	return (0);
}
