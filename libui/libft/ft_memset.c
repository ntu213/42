/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:52:55 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/03 09:52:55 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *) s;
	while (n > i)
	{
		str[i] = (char)c;
		i++;
	}
	return ((void *) s);
}
