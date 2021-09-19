#include "minishell.h"

void	sighnd(int signum)
{
	(void)signum;
	tcsetattr(0, TCSANOW, &g_mini.BACKUP_TTY);
	signal(SIGINT, &sighnd);
	while (g_mini.ter.tmp - g_mini.ter.end > -1)
	{
		ft_putstr_fd("\n", 2);
		g_mini.ter.end++;
	}
	exit(1);
}
