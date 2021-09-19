#include "minishell.h"

int	getKeys_norm(char *gen, int u, char *pap)
{
	DIR				*table_dir;
	struct dirent	*get_info;

	(void)gen;
	table_dir = opendir(pap);
	readdir(table_dir);
	readdir(table_dir);
	while (1)
	{
		get_info = readdir(table_dir);
		if (get_info == 0)
			break ;
		g_mini.post[u] = ft_calloc(1, sizeof(char));
		g_mini.post[u] = ft_strjoin1(g_mini.post[u], pap);
		g_mini.post[u] = ft_strjoin1(g_mini.post[u], get_info->d_name);
		u++;
		g_mini.post[u] = NULL;
	}
	closedir(table_dir);
	return (u);
}

int	getKeys_cmp(char *gen, int u, char *pap)
{
	DIR				*table_dir;
	struct dirent	*get_info;

	table_dir = opendir(pap);
	readdir(table_dir);
	readdir(table_dir);
	while (1)
	{
		get_info = readdir(table_dir);
		if (get_info == 0)
			break ;
		if (!ft_strcmp(get_info->d_name, gen))
		{
			keys_handler2(pap, u);
			g_mini.post[u] = ft_strjoin1(g_mini.post[u], get_info->d_name);
			u++;
			g_mini.post[u] = NULL;
		}
	}
	closedir(table_dir);
	return (u);
}

int	getKeys_post1(char *gen, int u, char *pap, char *tmp)
{
	int	i;

	i = ft_strtrim_l(pap, gen);
	if (i)
	{
		g_mini.post[u] = ft_calloc(1, sizeof(char));
		g_mini.post[u] = ft_strjoin1(g_mini.post[u], tmp);
		u++;
		g_mini.post[u] = NULL;
	}
	return (u);
}

int	getKeys_sw(char *gen, int u, char *pap, char *tmp)
{
	int	i;

	i = ft_strtrim_s(pap, gen);
	if (i)
	{
		g_mini.wid[u] = ft_calloc(1, sizeof(char));
		g_mini.wid[u] = ft_strjoin1(g_mini.wid[u], tmp);
		u++;
		g_mini.wid[u] = NULL;
	}
	return (u);
}

int	getKeys_fold1(char *gen, int u, char *pap)
{
	char			*buf;
	DIR				*table_dir;
	struct dirent	*get_info;

	(void)gen;
	(void)pap;
	buf = getccc();
	table_dir = opendir(buf);
	free(buf);
	readdir(table_dir);
	readdir(table_dir);
	while (1)
	{
		get_info = readdir(table_dir);
		if (get_info == 0)
			break ;
		g_mini.wid[u] = ft_calloc(1, sizeof(char));
		g_mini.wid[u] = ft_strjoin1(g_mini.wid[u], get_info->d_name);
		u++;
		g_mini.wid[u] = NULL;
	}
	closedir(table_dir);
	return (u);
}
