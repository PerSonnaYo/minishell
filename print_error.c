#include "minishell.h"

void	print_error(char *er, char *s, char *t)
{
	ft_putstr_fd(er, 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(t, 2);
}
