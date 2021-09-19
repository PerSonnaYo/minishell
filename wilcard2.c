#include "minishell.h"

void	last_wil5(t_wil *wil)
{
	int	nb;
	int	x;

	nb = 0;
	x = 0;
	wil->index = 0;
	while (wil->buf[wil->index] != NULL)
	{
		nb++;
		if (nb == 1)
			ft_freetab1(g_mini.post);
		x = getKeys_cmp(wil->ju + wil->loop, x, wil->buf[wil->index]);
		wil->index++;
	}
	wil->loop = wil->str;
}

void	last_wil6(t_wil *wil)
{
	int	nb;
	int	x;

	nb = 0;
	x = 0;
	wil->index = 0;
	while (wil->buf[wil->index] != NULL)
	{
		nb++;
		if (nb == 1)
			ft_freetab1(g_mini.post);
		x = getKeys_start(wil->ju + wil->loop, x, wil->buf[wil->index]);
		wil->index++;
	}
	wil->loop = wil->str;
}

void	last_wil7(t_wil *wil)
{
	int	nb;
	int	x;

	nb = 0;
	x = 0;
	wil->index = 0;
	while (wil->buf[wil->index] != NULL)
	{
		nb++;
		if (nb == 1)
			ft_freetab1(g_mini.post);
		if (!papka(wil->buf[wil->index]))
			wil->index++;
		else
		{
			x = getKeys_norm(wil->ju, x, wil->buf[wil->index]);
			wil->index++;
		}
	}
	wil->loop = wil->str;
}

void	last_wil4(t_wil *wil, char *str, int i)
{
	if (g_mini.pars_wil[0] == 1 && wil->str > wil->loop)
		last_wil6(wil);
	else if (g_mini.pars_wil[0] == 1 && wil->str == wil->loop)
		last_wil7(wil);
	else if (g_mini.pars_wil[0] == 0 && g_mini.pars_wil[2] == 3 \
		&& g_mini.pars_wil[1] == 0)
		last_wil5(wil);
	else if (g_mini.pars_wil[0] == 0 && g_mini.pars_wil[2] == 3 \
		&& g_mini.pars_wil[1] == 2 && str[i - 1] != '/')
		last_wil5(wil);
	ft_freetab(wil->buf);
	wil->buf = ft_realloc_pars(g_mini.post);
}
