#include "get_next_line.h"

int	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

int	ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	j;
	char	*cache;

	i =  0;
	j = 0;
	cache = ft_strdup(dest);
	free(dest);
	dest = malloc(ft_strlen(dest) + ft_strlen(src) + 1);
	if (!dest)
		return (0);
	while (cache[i])
		dest[i++] = cache[i];
	while (src[j])
		dest[i + j++] = src[j];
	dest[i + j] = '\0';
	free(cache);
	return (ft_strlen(src) + i);
}

int	is_line(char *str)	//renvoie 1 si "str" contient '\n', 0 sinon
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	get_str(char *str, int fd, int *done)	//retourne "str" concatenee avec "size" caracteres de "fd"
{
	char	*cache;
	int		index;

	cache = malloc(BUFFER_SIZE + 1);
	if (!cache)
		return ;
	while (!is_line(cache) && !is_line(str))
	{
		ft_strcat(str, cache);
		index = read(fd, cache, BUFFER_SIZE);
		if (!index)
		{
			*done = 1;
			return ;
		}
		cache[index] = 0;
	}
	ft_strcat(str, cache);
printf("%s\n", str);
}
