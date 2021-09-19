#include "minishell.h"

char	*ft_strjoin1(char const *s1, char const *s2)
{
	char		*ju;

	if (!s1 || !s2)
		return (NULL);
	ju = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ju)
		return (NULL);
	ft_strcpy(ju, (char *)s1);
	free((void *)s1);
	ft_strcat(ju, (char *)s2);
	return (ju);
}

char	*ft_substr1(char *s, unsigned long start, size_t len)
{
	int		y;
	char	*ju;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	y = ft_strlen(s) - start;
	ju = malloc(sizeof(char) * (len + 1));
	if (!ju)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (y-- && len--)
		{
			ju[i] = s[start];
			start++;
			i++;
		}
		ju[i] = '\0';
	}
	else
		ju[i] = '\0';
	free(s);
	return (ju);
}
