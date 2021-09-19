#include "minishell.h"

void	init_wil(t_wil *wil)
{
	wil->ju = ft_calloc(sizeof(char), 1);
	wil->buf = ft_calloc(sizeof(char *), 1);
	wil->tmp = ft_calloc(sizeof(char), 1);
	wil->pap = NULL;
}

void	past_wil1(t_wil *wil, char *gen, int last, int num)
{
	int		nb;
	int		t;
	int		qq;
	char	*tmp;

	nb = 0;
	qq = 0;
	if (last != num)
	{
		last = 0;
		while (wil->buf[last] != NULL)
		{
			t = inc_wil(wil->buf[last]);
			nb++;
			if (nb == 1)
				ft_freetab1(g_mini.wid);
			tmp = ft_strdup(wil->buf[last] + t + 1);
			qq = getKeys_sw(gen + num + 1, qq, tmp, wil->buf[last]);
			free(tmp);
			last++;
		}
	}
}

int	past_wil(t_wil *wil, char *gen)
{
	int	xx[2];

	init_num(&xx);
	wil->num = 0;
	while (gen[wil->num])
	{
		xx[0] = 0;
		wil->tmp = ft_memset(wil->tmp, gen[wil->num], 1);
		wil->ju = ft_strjoin1(wil->ju, wil->tmp);
		if (gen[wil->num] == '/')
		{
			xx[1] = papka(wil->ju);
			if (xx[1] > 0)
			{
				ft_freetab1(g_mini.wid);
				xx[0] = getKeys_fold(gen, xx[0], wil->ju);
				ft_freetab(wil->buf);
				wil->buf = ft_realloc_pars(g_mini.wid);
			}
			else
				xx[1] = dop_wil1(wil);
		}
		wil->num++;
	}
	return (xx[1]);
}

int	first_wilcard(char *gen, t_wil *wil)
{
	int		_indef[2];
	int		last;

	init_wil(wil);
	init_num(&_indef);
	if (gen[0] == '\0')
		getKeys_fold1(gen, 0, wil->pap);
	else
	{
		_indef[1] = 1;
		_indef[0] = past_wil(wil, gen);
		--wil->num;
		last = wil->num;
		if (_indef[0] > 0)
			dop_wil2(wil, gen, last);
		else if (g_mini.wid[0] == NULL && _indef[0] == 0)
		{
			ft_freetab1(g_mini.wid);
			getKeys(gen, 0);
		}
	}
	wil->ju = ft_memset(wil->ju, 0, sizeof(wil->ju));
	ft_freetab(wil->buf);
	loci_wil(wil);
	return (_indef[1]);
}
