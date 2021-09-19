#include "minishell.h"

int 	lun_pwd(t_buld *gen)
{
	char	str[1024];

	(void)gen;
	printf("%s\n", getcwd(str, sizeof(str)));
	return (0);
}
