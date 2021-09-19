#include "minishell.h"

int	inc_wil(char *str)
{
	int	t;

	t = 0;
	while (str[t])
		t++;
	while (str[t] != '/' && t > -1)
		t--;
	return (t);
}

int	dop_wil1(t_wil *wil)
{
	ft_freetab1(g_mini.wid);
	g_mini.wid[0] = NULL;
	ft_freetab1(wil->buf);
	return (-1);
}

void	dop_wil2(t_wil *wil, char *gen, int last)
{
	while (gen[wil->num] != '/' && wil->num > -1)
		wil->num--;
	past_wil1(wil, gen, last, wil->num);
}
