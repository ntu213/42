/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:58:11 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/28 09:59:58 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_r_up(int *tab1, int *tab2, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		tab1[i] = tab1[i + 1];
		tab2[i] = tab2[i + 1];
		i++;
	}
	tab1[i] = 0;
	tab2[i] = 0;
}

void	ft_r_rot(int *tab1, int *tab2, int size, char *str)
{
	int	n1;
	int	n2;

	n1 = tab1[0];
	n2 = tab2[0];
	ft_r_up(tab1, tab2, size);
	tab1[size - 1] = n1;
	tab2[size - 1] = n2;
	if (str[0])
		write(1, str, 3);
}

void	ft_r_revrot(int *tab1, int *tab2, int size, char *str)
{
	int	n1;
	int	n2;

	n1 = tab1[size - 1];
	n2 = tab2[size - 1];
	ft_r_down(tab1, tab2, size);
	tab1[0] = n1;
	tab2[0] = n2;
	write(1, str, 4);
}

void	ft_r_pb(t_tab *tab)
{
	ft_r_down(tab->indexb, tab->tabb, tab->size_b);
	tab->indexb[0] = tab->indexa[0];
	tab->tabb[0] = tab->taba[0];
	ft_r_up(tab->indexa, tab->taba, tab->size_a);
	tab->size_b += 1;
	tab->size_a -= 1;
	write(1, "pb\n", 3);
}

void	ft_r_pa(t_tab *tab)
{
	ft_r_down(tab->indexa, tab->taba, tab->size_a);
	tab->indexa[0] = tab->indexb[0];
	tab->taba[0] = tab->tabb[0];
	ft_r_up(tab->indexb, tab->tabb, tab->size_b);
	tab->size_a += 1;
	tab->size_b -= 1;
	write(1, "pa\n", 3);
}
