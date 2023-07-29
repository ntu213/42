/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:08:56 by dfleury           #+#    #+#             */
/*   Updated: 2023/05/18 10:49:22 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// * Modifié : secure,
char	*ft_strchr_x(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&(s[i]));
		i++;
	}
	if (s[i] == c)
		return ((char *)&(s[i]));
	return (NULL);
}

// * Modifié : prototype, secure, delete int total_len
char	*ft_strjoin_x(char *s1, char const *s2)
{
	int		i1;
	int		i2;
	char	*word;

	if (!s2)
		return (s1);
	word = malloc(sizeof(char) * (ft_strlen_x(s1) + ft_strlen_x(s2) + 1));
	if (!word)
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (s1 && s1[i1])
	{
		word[i1] = s1[i1];
		i1++;
	}
	i2 = 0;
	while (s2[i2])
	{
		word[i1] = s2[i2];
		i1++;
		i2++;
	}
	word[i1] = '\0';
	return (word);
}

// * Modifié : secure
size_t	ft_strlen_x(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
