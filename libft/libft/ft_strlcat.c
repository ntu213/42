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

int	ft_strlcat(char *dest, const char *src, size_t n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!n)
		return (0);
	while (dest[i])
		i++;
	while (n > (i + j) && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (ft_strlen(dest) + ft_strlen((char*)src));
}
