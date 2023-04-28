/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:26:57 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/28 10:00:40 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pow(int n, int exp)
{
	int	i;

	i = n;
	exp--;
	while (exp > 0)
	{
		i *= n;
		exp--;
	}
	return (i);
}

void	ft_pa_all(t_tab *tab)
{
	while (tab->size_b)
		ft_r_pa(tab);
}

t_tab	*ft_init_struct(int *taba, int *tabb, int size_a, int size_b)
{
	t_tab	*new;

	new = malloc(sizeof(t_tab));
	new->taba = taba;
	new->tabb = tabb;
	new->size_a = size_a;
	new->size_b = size_b;
	new->indexa = NULL;
	new->indexb = NULL;
	return (new);
}

void	ft_pb_pow(t_tab *tab, int pow)
{
	int	j;
	int	tmp;
	int	tmp2;

	j = 0;
	tmp2 = tab->size_a;
	while (j < tmp2)
	{
		tmp = tab->indexa[0];
		if ((tmp >> pow & 1) == 0)
			ft_r_pb(tab);
		else
			ft_r_rot(tab->taba, tab->indexa, tab->size_a, "ra\n");
		j++;
	}
}

void	ft_radix(int *taba, int size_a)
{
	int		*tabb;
	int		size_b;
	int		pow;
	t_tab	*tab;

	tabb = malloc(sizeof(int) * size_a);
	tab = ft_init_struct(taba, tabb, size_a, 0);
	pow = 0;
	tab->indexa = ft_get_index(tab->taba, tab->size_a);
	tab->indexb = malloc(sizeof(int) * size_a);
	while (!ft_end(tab->taba, tab->tabb, tab->size_a, tab->size_b) && pow <= 32)
	{
		ft_pb_pow(tab, pow);
		ft_pa_all(tab);
		pow++;
	}
	free(tab->indexa);
	free(tab->indexb);
	free(tabb);
	free(tab);
}
