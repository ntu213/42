#include "libft_bonus.h"
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int	i;

	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return(&str);
}