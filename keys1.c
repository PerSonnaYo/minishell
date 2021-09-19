#include "minishell.h"

char	*getccc(void)
{
	char	str[1024];
	char	*pap;

	getcwd(str, sizeof(str));
	pap = ft_strdup(str);
	return (pap);
}

int	keys_handler(int u, int *malo, char *gett)
{
	(void)malo;
	g_mini.wid[u] = ft_calloc(1, sizeof(char));
	g_mini.wid[u] = ft_strjoin1(g_mini.wid[u], gett);
	u++;
	g_mini.wid[u] = NULL;
	return (u);
}

int	keys_handler1(int u, int *malo, char *gett, char *buf)
{
	(void)malo;
	g_mini.post[u] = ft_calloc(1, sizeof(char));
	g_mini.post[u] = ft_strjoin1(g_mini.post[u], gett);
	g_mini.post[u] = ft_strjoin1(g_mini.post[u], buf);
	u++;
	g_mini.post[u] = NULL;
	return (u);
}

void	keys_handler2(char *gett, int u)
{
	g_mini.post[u] = ft_calloc(1, sizeof(char));
	g_mini.post[u] = ft_strjoin1(g_mini.post[u], gett);
}

void	maro(int qq, char *tmp)
{
	g_mini.post[qq] = calloc(1, sizeof(char));
	g_mini.post[qq] = ft_strjoin1(g_mini.post[qq], tmp);
	g_mini.post[qq] = ft_strjoin1(g_mini.post[qq], "/");
	g_mini.post[qq + 1] = NULL;
}
