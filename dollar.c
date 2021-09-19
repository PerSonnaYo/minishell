#include "libft/libft.h"

char	*dollar(char *str, char **env)
{
	int		i;
	int		flag;
	char	*res;
	int		len;

	i = 0;
	len = ft_strlen(str);
	flag = 0;
	while (env[i] && !flag)
	{
		if (ft_strnstr(env[i], str, len) && env[i][len] == '=')
		{
			res = ft_strdup(&env[i][len + 1]);
			flag = 1;
		}
		i++;
	}
	if (flag == 0)
		res = ft_strdup("");
	return (res);
}

void	free_all(char **temp, char **temp3, char **temp4)
{
	free(*temp4);
	free(*temp);
	free(*temp3);
}

int 	ret_y(char **s1)
{
	if ((*s1)[0] == '\0')
	{
		free(*s1);
		return (0);
	}
	if (ft_space((*s1)[0]))
	{
		free(*s1);
		return (2);
	}
	return (1);
}
