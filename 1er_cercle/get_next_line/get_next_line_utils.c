#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

size_t	ft_strcat(char *dest, char *src)
{
	size_t	i;
	size_t	j;
	char	*cache;

	i =  0;
	j = 0;
	cache = dest;
	free(dest);
	dest = malloc(ft_strlen(dest) + ft_strlen(src) + 1);
	if (!dest)
		return (0);
	while (cache[i])
		dest[i] = cache[i++];
	while (src[j])
		dest[i + j] = src[j++];
	dest[i + j] = '\0';
	return (ft_strlen(src) + i);
}

int	is_line(char *str)	//renvoie 1 si "str" contient '\n', 0 sinon
{
	int	i;

	i = 0;
	while (cache[i])
	{
		if (cache[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	get_str(char *str, int size, int fd, int *done)	//retourne "str" concatenee avec "size" caracteres de "fd"
{
	char	*cache;

	cache = "";
	while (!is_line(cache) && !is_line(str))
	{
		ft_strcat(str, cache);
		if (!read(fd, cache, size))
		{
			*done = 1;
			return ;
		}
	}
	ft_strcat(str, cache);
}
