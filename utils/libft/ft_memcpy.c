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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *) dest;
	str2 = (char *) src;
	if (dest == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		*str1 = *str2;
		str1++;
		str2++;
		n--;
	}
	return (dest);
}
