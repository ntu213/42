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
	char	*str;
	size_t	i;
	size_t	j;

	if (ft_strlen((char*)s) < start || !len || !ft_strlen((char*)s))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < len)
		if (i++ >= start)
			j++;
	str = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] && len > 0)
	{
		if (i >= start)
		{
			str[i] = s[i];
			len--;
		}
		i++;
	}
	str[i] = 0;
	return (str);
}
