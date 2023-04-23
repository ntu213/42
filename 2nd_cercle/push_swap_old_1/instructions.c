/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:24:12 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/22 18:15:46 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_down(t_tab *tab)
{
	int	i;

	i = tab->size - 1;
	while (i > 0)
	{
		tab->tab[i] = tab->tab[i - 1];
		i--;
	}
}

void	ft_up(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->size - 1)
	{
		tab->tab[i]= tab->tab[i + 1];
		i++;
	}
//	tab->tab[i]->val = 0;
}

void	ft_push(t_tab *tab1, t_tab *tab2, char *s)
{
	ft_down(tab1);
	tab1->tab[0] = tab2->tab[0];
	ft_up(tab2);
	tab1->size++;
	tab2->size--;
	write(1, s, 3);
}

void	ft_ra(t_tab *tab)
{
	t_val	*n;

	n = tab->tab[0];
	ft_up(tab);
	tab->tab[tab->size - 1] = n;
	write(1, "ra\n", 3);
}

void	ft_rra(t_tab *tab)
{
	t_val	*n;

	n = tab->tab[tab->size - 1];
	ft_down(tab);
	tab->tab[0] = n;
	write(1, "rra\n", 4);
}

void	ft_sa(t_tab *tab)
{
	t_val	*n;

	n = tab->tab[0];
	tab->tab[0] = tab->tab[1];
	tab->tab[1] = n;
	write(1, "sa\n", 3);
}
