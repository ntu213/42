#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (ft_strlen(s) < start || !len || !ft_strlen(s))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < len)
	{
		if (i >= start)
			j++;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && len > 0)
	{
		if (i >= start)
		{
			str[i] = s[i];
			len--;
		}
		i++;
	}
	str[i] = 0;
	return (str);
}