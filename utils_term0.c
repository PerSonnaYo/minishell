#include "minishell.h"

int	new_tty (int fd)
{
	struct termios	buffer;

	if (!isatty(0))
		return (-1);
	if ((tcgetattr (fd, &g_mini.BACKUP_TTY)) == -1)
		return (-1);
	buffer = g_mini.BACKUP_TTY;
	buffer.c_lflag = buffer.c_lflag & ~(ECHO | ICANON | ISIG);
	buffer.c_cc[VMIN] = 1;
	if ((tcsetattr (fd, TCSAFLUSH, &buffer)) == -1)
		return (-1);
	return (0);
}

int	ft_putint(int c)
{
	return (write(g_mini.fd, &c, 1));
}

void	get_cursor_position(int *col, int *rows)
{
	int		a;
	size_t	i;
	char	buf[255];
	int		ret;

	a = 0;
	i = 1;
	write(0, "\033[6n", 4);
	ret = read(0, buf, 254);
	buf[ret] = '\0';
	while (buf[i])
	{
		if (buf[i] >= 48 && buf[i] <= 57)
		{
			if (a == 0)
				*rows = ft_atoi(&buf[i]) - 1;
			else
				*col = ft_atoi(&buf[i]) - 1;
			a++;
			i += ft_intlen(*col) - 1;
		}
		i++;
	}
}

int	restore_tty (int fd)
{
	if ((tcsetattr (fd, TCSAFLUSH, &g_mini.BACKUP_TTY)) == -1)
		exit (-1);
	return (0);
}
