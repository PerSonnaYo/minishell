#include "minishell.h"

void	link_fd(t_fd **obj, int fd)
{
	t_fd	*new1;

	new1 = (t_fd *)malloc(sizeof(t_fd));
	if (!new1)
		exit(2);
	if (new1)
	{
		new1->nbr = fd;
		new1->next = NULL;
	}
	ft_lstadd_front4(obj, new1);
}

void	free_elem(t_buld **elem)
{
	t_buld	*buf;

	while (*elem != NULL)
	{
		buf = *elem;
		*elem = (*elem)->next;
		ft_freetab1(buf->str);
		free(buf->str);
		free(buf->doubl_red);
		free(buf);
		buf = NULL;
	}
	elem = NULL;
}

t_buld	*ft_lstlast1(t_buld *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_front3(t_buld **lst, t_buld *new)
{
	t_buld	*temp;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		temp = ft_lstlast1(*lst);
		temp->next = new;
	}
}

void	mister_link(t_buld **obj, char **env, char **str, t_fd **fdl)
{
	t_buld		*new;
	static int	i;

	new = (t_buld *)malloc(sizeof(t_buld));
	if (!new)
		exit(2);
	if (new)
	{
		new->str = str;
		new->env = env;
		new->nbr = g_mini.fdu;
		new->fdl = *fdl;
		new->doubl_red = g_mini.doub_red;
		new->next = NULL;
	}
	i++;
	ft_lstadd_front3(obj, new);
}
