#include "minishell.h"

char	*under(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	str[i] = '\0';
	return (str);
}

void	is_tail(char **str, char ***line, char **ch)
{
	if (*str)
	{
		*ch = ft_strchr(*str, '\n');
		if (*ch)
		{
			**line = under(*str);
			*str = ft_strdup(*ch + 1);
		}
		else
		{
			**line = ft_strdup(*str);
			free(*str);
			*str = NULL;
		}
	}
	else
		**line = ft_strdup("");
}

void	ch_check(char *ch, char **tail, char **line, char *str)
{
	if (ch)
	{
		*tail = ft_strdup(ch + 1);
		*line = ft_strjoin(*line, under(str));
	}
	else
		*line = ft_strjoin(*line, str);
}

int	get_next_line(int fd, char **line)
{
	char		str[BUFFER_SIZE + 1];
	int			bytes;
	static char	*tail;
	char		*ch;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || (read(fd, NULL, 0) < 0))
		return (-1);
	ch = NULL;
	is_tail(&tail, &line, &ch);
	while (!ch)
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		str[bytes] = '\0';
		tmp = *line;
		ch = ft_strchr(str, '\n');
		ch_check(ch, &tail, &(*line), str);
		free(tmp);
	}
	if (bytes == 0 && !tail)
		return (0);
	else
		return (1);
}
