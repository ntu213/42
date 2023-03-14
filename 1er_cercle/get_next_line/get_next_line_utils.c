/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:10:27 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/14 10:10:27 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *c)
{
	int	i;

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j++])
		str[i + j - 1] = s2[j - 1];
	str[i + j - 1] = 0;
	free(s1);
	return (str);
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

char	*get_str(char *str, int fd)	//retourne "str" concatenee avec "size" caracteres de "fd"
{
	char	*cache;
	int		index;

	cache = malloc(BUFFER_SIZE + 1);
	if (!cache)
		return (NULL);
	cache[0] = 0;
	while (!is_line(cache) && !is_line(str))
	{
		str = ft_strjoin(str, cache);
		index = read(fd, cache, BUFFER_SIZE);
		if (!index)
			return (str);
		cache[index] = 0;
	}
	str = ft_strjoin(str, cache);
	free(cache);
	return (str);
}
