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
	size_t	len_src;
	size_t	len_dest;

	i = 0;
	j = 0;
	if (!n)
		return (0);
	len_src = ft_strlen(src);
	len_dest = ft_strlen((const char*)dest);
	i = len_dest;
	if (n <= len_dest)
		return (n + len_src);
	while (n - 1 > (i + j) && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (len_dest + len_src);
}
