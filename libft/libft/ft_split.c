/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:18:24 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/11 10:18:26 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_size(char const *str, char c);
static int	ft_words_count(char const *str, char c);

char	**ft_split(char const *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	size;
	int	words;
	char	*str;
	char	**strr;

	i = 0;
	k = 0;
	strr = malloc(sizeof(char*) * ft_words_count(s, c));
	while (s[i])
	{
		j = 0;
		size = ft_word_size(s, c);
		str = malloc(sizeof(char) * (size + 1));
		while (j < size)
		{
			str[j] = s[i];
			j++;
			i++;
		}
		str[j] = 0;
		strr[k++] = str;
		i++;
	}
	strr[k] = NULL;
	return (strr);
}

static int	ft_word_size(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_words_count(char const *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (str[i])
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return(j);
}