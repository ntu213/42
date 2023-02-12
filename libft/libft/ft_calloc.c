/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:16:56 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/11 10:16:58 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*i;

	if (((n * size) / size) != n || !n || !size)
		return (NULL);
	i = malloc(size * n);
	if (!i)
		return (NULL);
	ft_bzero(i, (n * size));
	return (i);
}
