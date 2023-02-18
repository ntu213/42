/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:01:48 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/18 12:02:02 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_count(char const *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c)
			j++;
		i++;
	}
	return(j);
}

static char	*ft_word_def(char const *str, char c, int *i)
{
	char	*dest;
	int		j;

	j = *i;
	while (str[j] && str[j] != c)
		j++;
	dest = malloc(j + 1);
	if (!dest)
		return (NULL);
	j = 0;
	while (str[*i] && str[*i] != c)
	{
		dest[j] = str[*i];
		j++;
		(*i)++;
	}
	dest[j] = 0;
	return (dest);
}

static int	ft_error(char ***str, int j)
{
	while(0 <= j)
	{
		free(*(str[j]));
		j--;
	}
	free(*str);
	return (1);
}

char **ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char*) * (ft_words_count(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		str[j] = ft_word_def(s, c, &i);
		if (!str[j])
			if (ft_error(&str, j))
				return (NULL);
		j++;
	}
	str[j] = (char*)NULL;
	return (str);
}