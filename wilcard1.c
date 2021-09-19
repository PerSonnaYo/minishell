#include "minishell.h"

void	last_wilcard(t_wil *wil)
{
	g_mini.pars_wil[0] = 0;
	g_mini.pars_wil[1] = 0;
	g_mini.pars_wil[2] = 0;
	wil->ju = ft_calloc(1, sizeof(char));
	wil->index = 0;
	wil->str = 0;
	ft_freetab1(g_mini.post);
}

void	last_wil1(t_wil *wil)
{
	int		x;
	char	*s4;
	int		qq;

	x = 0;
	qq = 0;
	while (wil->ju[wil->str] && wil->ju[wil->str] != '/')
		wil->str++;
	while (wil->buf[wil->index] != NULL)
	{
		x = papka(wil->buf[wil->index]);
		if (x == 1)
		{
			s4 = ft_substr(wil->ju, 0, wil->str);
			qq = getKeys_post(s4, qq, wil->buf[wil->index]);
			s4 = (char *)ft_memset(s4, 0, ft_strlen(s4));
			free(s4);
		}
		wil->index++;
	}
}

void	last_wil0(t_wil *wil)
{
	int	x;
	int	qq;

	x = 0;
	qq = 0;
	if (wil->ju[wil->str] == '/')
	{
		while (wil->buf[wil->index] != NULL)
		{
			x = papka(wil->buf[wil->index]);
			if (x == 1)
			{
				maro(qq, wil->buf[wil->index]);
				qq++;
			}
			wil->index++;
		}
		wil->str++;
	}
	else
		last_wil1(wil);
}

void	last_wil3(t_wil *wil, int nb)
{
	char	*s4;
	int		xx[2];
	char	*tmp;

	nb = 0;
	init_num(&xx);
	while (wil->buf[wil->index] != NULL)
	{
		s4 = ft_substr(wil->ju, wil->loop, wil->str - wil->loop);
		tmp = s4;
		s4 = ft_strjoin(wil->buf[wil->index], tmp);
		free(tmp);
		xx[0] = papka(s4);
		if (xx[0] == 1)
		{
			nb = nb + 1;
			if (nb == 1)
				ft_freetab1(g_mini.post);
			maro(xx[1], s4);
			xx[1]++;
		}
		free(s4);
		wil->index++;
	}
	wil->loop = wil->str + 1;
}

void	last_wil2(t_wil *wil)
{
	int	nb;

	nb = 0;
	if (wil->ju[wil->str] == '/')
		wil->str++;
	wil->loop = wil->str;
	while (wil->ju[wil->str])
	{
		wil->index = 0;
		ft_freetab(wil->buf);
		wil->buf = ft_realloc_pars(g_mini.post);
		if (wil->ju[wil->str] == '/')
			last_wil3(wil, nb);
		wil->str++;
	}
	ft_freetab(wil->buf);
	wil->buf = ft_realloc_pars(g_mini.post);
}
