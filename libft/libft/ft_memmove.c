/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:40:23 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/06 18:40:23 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	i = 1;
	str1 = (char *) dest;
	str2 = (char *) src;
	if (dest == 0 && src == 0)
		return (0);
	if (src > dest)
		ft_memcpy(dest, src, n);
	else
	{
		while (i <= n)
		{
			str1[n - i] = str2[n - i];
			i++;
		}
	}
	return (dest);
}
