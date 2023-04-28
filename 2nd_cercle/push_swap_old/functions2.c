/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:55:31 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/28 09:56:50 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str, int *tab)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	free(tab);
}

int	ft_strrlen(char **strr)
{
	int	i;

	i = 0;
	while (strr[i])
		i++;
	return (i);
}

void	ft_pb(int *taba, int *tabb, int *size_a, int *size_b)
{
	ft_push(tabb, taba, size_b, size_a);
	*size_b += 1;
	*size_a -= 1;
	write(1, "pb\n", 3);
}

void	ft_pa(int *taba, int *tabb, int *size_a, int *size_b)
{
	ft_push(taba, tabb, size_a, size_b);
	*size_a += 1;
	*size_b -= 1;
	write(1, "pa\n", 3);
}
