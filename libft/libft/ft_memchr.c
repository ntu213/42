/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:32:08 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/06 18:32:08 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	char	*str;

	str = (char *) s;
	while (n > 0)
	{
		if (*str == c)
			return ((void *)str);
		str++;
		n--;
	}
	return (0);
}
