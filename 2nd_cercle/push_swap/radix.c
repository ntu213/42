/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:40:29 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/02 18:16:42 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_new_min(int min, t_tab *a)
{
	int	i;
	int	new;

	i = 0;
	while (i < a->size)
	{
		if (a->tab[i]->val > min)
		{
			new = a->tab[i]->val;
			break ;
		}
		i++;
	}
	i = 0;
	while (i < a->size)
	{
		if (a->tab[i]->val > min && a->tab[i]->val < new)
			new = a->tab[i]->val;
		i++;
	}
	return (new);
}

int	ft_bin(int n)
{
	int	res;

	res = 0;
	if (n)
	{
		res += ft_bin(n / 2);
		res *= 10;
	}
	res += n % 2;
	return (res);
}

void	ft_set_index(t_tab *tab, int *index)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->size)
	{
		j = 0;
		while (tab->tab[j]->val != index[i])
			j++;
		tab->tab[j]->index = i;
		tab->tab[j]->i_bin = ft_bin(i);
		i++;
	}
}

void	ft_get_index(t_tab *tab)
{
	int	i;
	int	itab[tab->size];

	i = 1;
	itab[0] = ft_getmin(tab, tab);
	while (i < tab->size)
	{
		itab[i] = ft_new_min(itab[i - 1], tab);
		i++;
	}
	ft_set_index(tab, itab);
}

void	ft_radix(t_tab *a, int *tab)
{
	t_tab	*b;

	b = ft_init_tab(tab, a->size);
	b = ft_ztab(b);
	ft_get_index(a);
}
