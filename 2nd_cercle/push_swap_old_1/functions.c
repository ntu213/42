/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:15:48 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/22 18:14:25 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_val *ft_init_val(int n)
{
	t_val *new;

	new = malloc(sizeof(t_val));
	new->val = n;
	new->index = -1;
	new->i_bin = 0;
	return (new);
}

t_tab	*ft_init_tab(int *tab, int size)
{
	int		i;
	t_tab	*new;

	i = 0;
	new = malloc(sizeof(t_tab));
	new->tab = malloc(sizeof(t_val *) * size + 1);
	while (i < size)
	{
		printf("tab[%d] = %d\n", i, tab[i]);
		new->tab[i] = ft_init_val(tab[i]);
		i++;
	}
	new->size = size;
	return (new);
}

int	ft_getmin(t_tab *tab1, t_tab *tab2)
{
	int	i;
	int	cache;

	i = 0;
	cache = tab1->tab[0]->val;
	while (i < tab1->size)
	{
		if (cache > tab1->tab[i]->val)
			cache = tab1->tab[i]->val;
		i++;
	}
	i = 0;
	while (i < tab2->size)
	{
		if (cache > tab2->tab[i]->val)
			cache = tab2->tab[i]->val;
		i++;
	}
	return (cache);
}

void	ft_top(t_tab *a, t_tab *b)
{
	int	i;

	i = 0;
	if (a->tab[1]->val == ft_getmin(a, a))
		ft_sa(a);
	while (a->tab[0]->val != ft_getmin(a, a))
		ft_ra(a);
}

void	ft_bot(t_tab *a, t_tab *b)
{
	int	i;

	i = 0;
	if (a->tab[1]->val == ft_getmin(a, a))
		ft_sa(a);
	while (a->tab[0]->val != ft_getmin(a, a))
		ft_rra(a);
}
