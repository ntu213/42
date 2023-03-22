/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:01:48 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/22 15:28:56 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *) s;
	while (n)
	{
		*str = '\0';
		str++;
		n--;
	}
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*i;
	size_t	tmp;

	tmp = n * size;
	if (n == 0 || size == 0)
		return (malloc(0));
	if ((tmp / size) != n)
		return (NULL);
	i = malloc(tmp);
	if (!i)
		return (NULL);
	ft_bzero(i, tmp);
	return (i);
}

static int	ft_count_wrd(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == c))
			i++;
		if (str[i] && (str[i++] != c))
			count ++;
		while (str[i] != c && str[i])
			i++;
	}
	return (count);
}

static char	*ft_wrd_dup(char *src, char c, int *i)
{
	char	*dest;
	int		j;

	j = 0;
	while (src[(*i) + j] && (src[(*i) + j] != c))
		j++;
	dest = (char *)ft_calloc((j + 1), sizeof(char));
	if (!dest)
		return (NULL);
	j = 0;
	while ((src[(*i)] != c) && src[(*i)])
		dest[j++] = src[(*i)++];
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**res;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	res = ft_calloc((ft_count_wrd((char *)s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if ((s[i] != c) && s[i])
			res[j++] = ft_wrd_dup((char *)s, c, &i);
	}
	return (res);
}
