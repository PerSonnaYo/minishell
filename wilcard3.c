#include "minishell.h"

void	last_wil8(t_wil *wil)
{
	int		nb;
	int		t;
	int		qq;
	char	*tmp;

	nb = 0;
	qq = 0;
	while (wil->buf[wil->index] != NULL)
	{
		t = 0;
		nb++;
		if (nb == 1)
			ft_freetab1(g_mini.post);
		t = inc_wil(wil->buf[wil->index]);
		tmp = ft_strdup(wil->buf[wil->index] + t + 1);
		qq = getKeys_mid(wil->ju, qq, tmp, wil->buf[wil->index]);
		free(tmp);
		wil->index++;
	}
	g_mini.post[qq] = NULL;
	ft_freetab(wil->buf);
	free(wil->ju);
	wil->buf = ft_realloc_pars(g_mini.post);
}

void	last_wil9(t_wil *wil)
{
	int		nb;
	int		t;
	int		qq;
	char	*tmp;

	nb = 0;
	qq = 0;
	while (wil->buf[wil->index] != NULL)
	{
		t = 0;
		nb++;
		if (nb == 1)
			ft_freetab1(g_mini.post);
		while (wil->buf[wil->index][t])
			t++;
		while (wil->buf[wil->index][t] != '/' && t > -1)
			t--;
		tmp = ft_strdup(wil->buf[wil->index] + t + 1);
		qq = getKeys_post1(wil->ju, qq, tmp, wil->buf[wil->index]);
		free(tmp);
		wil->index++;
	}
	ft_freetab(wil->buf);
	free(wil->ju);
	wil->buf = ft_realloc_pars(g_mini.post);
}
