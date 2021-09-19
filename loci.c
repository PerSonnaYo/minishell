#include "minishell.h"

void	ft_freetab(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	ft_freetab1(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
}

char	**ft_realloc_pars(char **str)
{
	int		i;
	int		y;
	char	**new;

	i = env_size(str);
	new = (char **)ft_calloc(1024, sizeof(char *));
	y = 0;
	while (y < i)
	{
		new[y] = ft_calloc(1, ft_strlen(str[y]));
		new[y] = ft_strjoin1(new[y], str[y]);
		y++;
	}
	new[y] = NULL;
	return (new);
}
