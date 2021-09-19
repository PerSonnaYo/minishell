#include "minishell.h"

void	redicor(t_fd *fdl)
{
	while (fdl)
	{
		dup2(fdl->nbr, 1);
		fdl = fdl->next;
	}
}

void	close_fd(t_fd *fdl)
{
	while (fdl)
	{
		close(fdl->nbr);
		fdl = fdl->next;
	}
	if (g_mini.fdu != 0)
		close(g_mini.fdu);
	free_fd(&fdl);
}
