#include "libft.h"

static int	ft_count_start(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (ft_is_set(s[i], set))
		i++;
	return (i);
}

static int	ft_count_end(char const *s, char const *set)
{
	int	i;

	i = ft_strlen(s);
	while (ft_is_set(s[i], set))
		i--;
	return (i);
}

static int	ft_is_set(char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	i = 0;
	start = ft_count_start(s1, set);
	end = ft_count_end(s1, set);
	str = malloc (sizeof(char) * (end - start + 1));
	while (start < end)
	{
		str[i] = s1[start + i];
		i++;
	}
	return (str);
}