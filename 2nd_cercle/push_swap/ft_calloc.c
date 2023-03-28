/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:16:56 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/11 10:16:58 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*i;
	size_t	tmp;

	tmp = n * size;
	if (n == 0 || size == 0)
		return (malloc(0));
	if ((tmp / size) != n)
		return (NULL);
	i = malloc(tmp);
	if (!i)
		return (NULL);
	ft_bzero(i, tmp);
	return (i);
}
