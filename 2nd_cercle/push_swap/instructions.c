/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:24:12 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/01 18:24:12 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_down(t_tab *tab)
{
	int	i;

	i = tab->size - 1;
	while (i)
	{
		tab->tab[i]->val = tab->tab[i - 1]->val;
		i--;
	}
	tab->size++;
}

void	ft_up(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->size - 1)
	{
		tab->tab[i]->val = tab->tab[i + 1]->val;
		i++;
	}
	tab->tab[i]->val = 0;
	tab->size--;
}

void	ft_push(t_tab *tab1, t_tab *tab2, char *s)
{
	ft_down(tab1);
	tab1->tab[0]->val = tab2->tab[0]->val;
	ft_up(tab2);
	write(1, s, 3);
}

void	ft_ra(t_tab *tab)
{
	int	n;

	n = tab->tab[0]->val;
	ft_up(tab);
	tab->size++;
	tab->tab[tab->size - 1]->val = n;
	write(1, "ra\n", 3);
}

void	ft_rra(t_tab *tab)
{
	int	n;

	n = tab->tab[tab->size - 1]->val;
	ft_down(tab);
	tab->size--;
	tab->tab[0]->val = n;
	write(1, "rra\n", 4);
}
