/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inctructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:27:19 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/30 08:27:19 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *tab)
{
	int	i;

	i = tab[0];
	tab[0] = tab[1];
	tab[1] = i;
}

void	ft_ss(int *taba, int *tabb)
{
	ft_swap(taba);
	ft_swap(tabb);
	ft_putstr("ss\n");
}

void	ft_down(int *tab, int size)
{
	int	i;

	i = size + 1;
	while (i)
	{
		tab[i] = tab[i - 1];
		i--;
	}
}

void	ft_up(int *tab, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = 0;
}

void	ft_push(int *tab1, int *tab2, int *size1, int *size2)
{
	int	i;

	i = 0;
	ft_down(tab1, *size1);
//	printf("ok\n");
	tab1[0] = tab2[0];
	ft_up(tab2, *size2);
}
