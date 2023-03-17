/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:05:09 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/17 18:11:48 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strnstr(const char *src, const char *obj, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!src && !obj)
		return (0);
	if (!obj[0])
		return (0);
	while (n > i && src[i])
	{
		j = 0;
		while (n > i + j && src[i + j] && obj[j] == src[i + j])
		{
			j++;
			if (!obj[j])
				return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
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
