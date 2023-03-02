/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:45:57 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/06 18:45:57 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t t)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] && i < t)
		i++;
	while (src[j] && (i + j + 1) < t)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < t)
		dest[i + j] = '\0';
	return (ft_strlen(src) + i);
}
