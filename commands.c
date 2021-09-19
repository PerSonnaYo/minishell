#include "minishell.h"

void	redic_bul(t_buld *gen)
{
	int		res;
	char	*line;

	res = 1;
	while (res > 0)
	{
		ft_putstr_fd("> ", 0);
		line = NULL;
		res = get_next_line(0, &line);
		if (!ft_strcmp(line, gen->doubl_red))
			break ;
		free(line);
	}
}

int	ret_int(t_line *io, t_buld *gen)
{
	int			i;
	static char	*mas[NUM__BUIL];

	i = 0;
	mas[0] = "cd";
	mas[1] = "export";
	mas[2] = "unset";
	mas[3] = "exit";
	io->i = 0;
	if (gen->str[0] == NULL)
		return (0);
	while (i < NUM__BUIL)
	{
		if (ft_strcmp(gen->str[0], mas[i]) == 0)
		{
			io->i = 1;
			if (i == 1 && !gen->str[1])
				io->i = 0;
		}
		i++;
	}
	return (1);
}

int	mister_exit1(t_line io, t_buld *gen)
{
	int				i;
	static char		*mas[NUM__BUIL];
	static t_func	oper[NUM__BUIL] = {lun_cdd, lun_adexp, lun_uns, lun_exi};

	i = 0;
	mas[0] = "cd";
	mas[1] = "export";
	mas[2] = "unset";
	mas[3] = "exit";
	while (i < NUM__BUIL)
	{
		if ((ft_strcmp(gen->str[0], mas[i]) == 0) && io.i == 1)
		{
			if (gen->doubl_red != NULL)
				redic_bul(gen);
			return (oper[i](gen));
		}
		i++;
	}
	return (-1);
}

int	mister_exit(t_buld *gen)
{
	int				i;
	static char		*mas[NUM__BUIL_PIP];
	static t_func	oper1[NUM__BUIL_PIP] = {lun_pwd, \
		lun_prexp, lun_env, lun_ech};

	i = 0;
	mas[0] = "pwd";
	mas[1] = "export";
	mas[2] = "env";
	mas[3] = "echo";
	while (i < NUM__BUIL_PIP)
	{
		if (ft_strcmp(gen->str[0], mas[i]) == 0)
			return (oper1[i](gen));
		i++;
	}
	return (-1);
}

int	mister_command_pip(t_buld *gen)
{
	int				i;
	static char		*mas[PIP__BUIL];
	static t_func	oper[PIP__BUIL] = {lun_cdd, lun_exp, lun_uns, \
		lun_exi, lun_pwd, lun_env, lun_ech};

	i = 0;
	mas[0] = "cd";
	mas[1] = "export";
	mas[2] = "unset";
	mas[3] = "exit";
	mas[4] = "pwd";
	mas[5] = "env";
	mas[6] = "echo";
	while (i < PIP__BUIL)
	{
		if (ft_strcmp(gen->str[0], mas[i]) == 0)
			return (oper[i](gen));
		i++;
	}
	return (-1);
}
