/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:55:03 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/02 19:21:48 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_end(t_tab *a, t_tab *b)
{
	int	i;
	int	cache;

	i = (a->size) - 1;
	cache = a->tab[i]->val;
	while (i > -1)
	{
		if (a->tab[i]->val > cache)
			return (0);
		cache = a->tab[i]->val;
		i--;
	}
	i = 0;
	while (i < b->size)
	{
		if (b->tab[i]->val > cache)
			return (0);
		cache = b->tab[i]->val;
		i++;
	}
	return (1);
}

int	ft_istop(t_tab *tab)
{
	int	i;

	i = 0;
	while (tab->tab[i]->val != ft_getmin(tab, tab))
		i++;
	if (i < tab->size /2)
		return (1);
	return (0);
}

t_tab	*ft_ztab(t_tab *tab)
{
	int	i;

	i = 0;
	while (i < tab->size)
	{
		tab->tab[i]->val = 0;
		i++;
	}
	tab->size = 0;
	return (tab);
}

t_tab	*ft_run(t_tab *a, int *tab)
{
	t_tab	*b;

	b = ft_init_tab(tab, a->size);
	b = ft_ztab(b);
	while (!ft_end(a, b))
	{
		while (a->tab[0]->val == ft_getmin(a, a))
			ft_push(b, a, "pb\n");
		if (ft_istop(a))
			ft_top(a, b);
		else
			ft_bot(a, b);
	}
	while (b->size)
		ft_push(a, b, "pa\n");
	return (b);
}