/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:13:14 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/11 14:13:14 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	i = 0;
	if (len >= ft_strlen(s + start))
		res = (char *)ft_calloc(ft_strlen(s + start) + 1, sizeof(char));
	else
		res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (len > i && s[start + i])
	{
		res[i] = s[start + i];
		i ++;
	}
	res[i] = 0;
	return (res);
}
