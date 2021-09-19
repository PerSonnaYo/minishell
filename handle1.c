#include "minishell.h"

void	ft_fopen(char *s, int l, t_fd **fdl)
{
	int	fd;

	if (l == 1)
	{
		fd = open(s, O_RDWR | O_CREAT | O_APPEND, 0666);
		if (fd < 0)
		{
			print_error(OP_CR, s, "\n");
			g_mini.qua = 1;
		}
	}
	else
	{
		fd = open(s, O_RDWR | O_CREAT | O_TRUNC, 0666);
		if (fd < 0)
		{
			print_error(OP_CR, s, "\n");
			g_mini.qua = 1;
		}
	}
	free(s);
	link_fd(fdl, fd);
}

int	ft_fopenre(char *s, int l)
{
	int	fd;

	fd = 0;
	if (l == 0)
	{
		fd = open(s, O_RDONLY);
		if (fd < 0)
		{
			print_error(OP_RE, s, "\n");
			g_mini.qua = 1;
		}
	}
	else
		g_mini.doub_red = ft_strdup(s);
	free(s);
	return (fd);
}

int	parser_redic(char *str, char **envy, t_fd **fdl)
{
	int		u;
	int		i;
	char	*gen;

	u = 0;
	i = 0;
	if (str[i + 1] == '>')
	{
		u = 1;
		i++;
	}
	++i;
	while (str[i] && ft_space(str[i]))
		i++;
	gen = ft_calloc(sizeof(char), 1);
	i = parser_alpha(&gen, str, i, envy);
	ft_fopen(gen, u, fdl);
	return (i);
}

int	parser_redicre(char *str, char **envy, int *pp)
{
	int		i;
	char	*gen;
	int		u;

	i = 0;
	u = 0;
	if (str[i + 1] == '<')
	{
		u = 1;
		i++;
	}
	++i;
	while (str[i] && ft_space(str[i]))
		i++;
	gen = ft_calloc(sizeof(char), 1);
	i = parser_alpha(&gen, str, i, envy);
	*pp = ft_fopenre(gen, u);
	return (i);
}
