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

	i = 0;
	while (dest[i])
		i++;
	while (n > 0)
	{
		dest[i] = src[i];
		i++;
		n--;
	}
	return (n + i);
}
