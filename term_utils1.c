#include "minishell.h"

char	*dell(char *str, int col)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(str));
	while (i < col)
	{
		new[i] = str[i];
		i++;
	}
	col = col + 1;
	while (col < (int)ft_strlen(str))
	{
		new[i] = str[col];
		i++;
		col++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

char	*beg(char *str, int col)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * col + 1);
	while (i < col)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

void	k_left(t_term *tter)
{
	if (tter->len > tter->col)
	{
		if (tter->col % tgetnum("co") == 0)
		{
			tter->end++;
			tputs(tgetstr("do", 0), 1, ft_putint);
		}
		else
			tputs(tgetstr("nd", 0), 1, ft_putint);
		tter->col++;
	}
}

void	k_right(t_term *tter)
{
	if (tter->col > 8)
	{
		tputs(tgetstr("le", 0), 1, ft_putint);
		tter->col--;
		if (tter->col % tgetnum("co") == 0)
			tter->end--;
	}
}

void	fin_del(char **history, int j)
{
	if (env_size(history) == j)
		del();
	else
		del_hist(history, j);
}
