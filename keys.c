#include "minishell.h"

int	getKeys(char *gen, int u)
{
	int				malo;
	char			*buf;
	int				i;
	DIR				*table_dir;
	struct dirent	*get_info;

	buf = getccc();
	table_dir = opendir(buf);
	free(buf);
	buf = NULL;
	malo = REAL;
	readdir(table_dir);
	readdir(table_dir);
	while (1)
	{
		get_info = readdir(table_dir);
		if (get_info == 0)
			break ;
		i = ft_strtrim_s(get_info->d_name, gen);
		if (i)
			u = keys_handler(u, &malo, get_info->d_name);
	}
	closedir(table_dir);
	return (u);
}

int	getKeys_fold(char *gen, int u, char *pap)
{
	int				malo;
	DIR				*table_dir;
	struct dirent	*get_info;

	malo = REAL;
	(void)(*gen);
	table_dir = opendir(pap);
	readdir(table_dir);
	readdir(table_dir);
	while (1)
	{
		get_info = readdir(table_dir);
		if (get_info == 0)
			break ;
		g_mini.wid[u] = ft_calloc(1, sizeof(char));
		g_mini.wid[u] = ft_strjoin1(g_mini.wid[u], pap);
		g_mini.wid[u] = ft_strjoin1(g_mini.wid[u], get_info->d_name);
		u++;
		g_mini.wid[u] = NULL;
	}
	closedir(table_dir);
	return (u);
}

int	getKeys_post(char *gen, int u, char *pap)
{
	int	i;
	int	malo;

	malo = REAL;
	i = ft_strtrim_l(pap, gen);
	if (i)
	{
		g_mini.post[u] = ft_calloc(1, sizeof(char));
		g_mini.post[u] = ft_strjoin1(g_mini.post[u], pap);
		g_mini.post[u] = ft_strjoin1(g_mini.post[u], "/");
		u++;
		g_mini.post[u] = NULL;
	}
	return (u);
}

int	getKeys_mid(char *gen, int u, char *pap, char *tmp)
{
	char	*buf;
	int		malo;

	malo = REAL;
	buf = ft_strnstr(pap, gen, ft_strlen(pap));
	if (buf)
	{
		g_mini.post[u] = ft_calloc(1, sizeof(char));
		g_mini.post[u] = ft_strjoin1(g_mini.post[u], tmp);
		u++;
	}
	return (u);
}

int	getKeys_start(char *gen, int u, char *pap)
{
	int				malo;
	int				i;
	DIR				*table_dir;
	struct dirent	*get_info;

	malo = REAL;
	table_dir = opendir(pap);
	readdir(table_dir);
	readdir(table_dir);
	while (1)
	{
		get_info = readdir(table_dir);
		if (get_info == 0)
			break ;
		i = ft_strtrim_s(get_info->d_name, gen);
		if (i)
			u = keys_handler1(u, &malo, pap, get_info->d_name);
	}
	closedir(table_dir);
	return (u);
}
