#include "minishell.h"

int	ft_lstsize2(t_fd *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

int	ft_lstsize1(t_buld *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	free_fd(t_fd **elem)
{
	t_fd	*buf;

	while (*elem != NULL)
	{
		buf = *elem;
		*elem = (*elem)->next;
		free(buf);
		buf = NULL;
	}
	*elem = NULL;
}

t_fd	*ft_lstlast2(t_fd *lst)
{
	if (lst)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_front4(t_fd **lst, t_fd *new)
{
	t_fd	*temp;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		temp = ft_lstlast2(*lst);
		temp->next = new;
	}
}
