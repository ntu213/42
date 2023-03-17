/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:57:59 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/18 15:57:59 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

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

	i = ft_strlen(s) - 1;
	while (ft_is_set(s[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start = ft_count_start(s1, set);
	end = ft_count_end(s1, set);
	if (end < start)
		return (ft_strdup(""));
	str = (char *)malloc (sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	while ((start + i) <= end)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
