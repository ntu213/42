/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:10:27 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/16 15:51:12 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_stlen(const char *c)
{
	int	i;

	if (!c)
		return (0);
	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	*ft_stjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_stlen(s1) + ft_stlen(s2) + 1);
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

int	is_line(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_str(char *str, int fd)
{
	char	*cache;
	int		index;

	cache = malloc(BUFFER_SIZE + 1);
	if (!cache)
		return (NULL);
	cache[0] = 0;
	while (!is_line(cache) && !is_line(str))
	{
		index = read(fd, cache, BUFFER_SIZE);
		if (!index)
			break ;
		cache[index] = 0;
		str = ft_stjoin(str, cache);
	}
	free(cache);
	return (str);
}
