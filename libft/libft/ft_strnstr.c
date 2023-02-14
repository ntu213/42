/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:46:39 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/06 18:46:39 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *obj, size_t n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!src && !obj)
		return (NULL);
	if (!obj[0])
		return((char*)src);
	while (n > 0 && src[i] && obj[i])
	{
		while (n > 0 && src[i + j] && obj[i + j] == src[i + j])
		{
			j++;
			if (!obj[i + j])
				return ((char*)(src + i));
			n--;
		}
		i++;
		n -= j - 1;
		j = 0;
	}
	return (NULL);
}
