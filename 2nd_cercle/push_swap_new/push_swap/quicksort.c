/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:17:54 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 16:18:32 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_on_top(t_lst **a, t_lst **b, int cat)
{
	while (ft_is_category_in_lst(*a, cat))
	{
		if ((*a)->category == cat)
			ft_pb(a, b);
		else
			*a = ft_ra(*a, *b, "ra\n");
	}
}

void	ft_1_to_6(t_lst **a, t_lst **b)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(*a);
	while (i < size)
	{
		if ((*a)->category >= 1 && (*a)->category <= 6)
		{
			ft_pb(a, b);
			if ((*b)->category == 2 || (*b)->category == 5)
				*b = ft_rb(*a, *b, "rb\n");
		}
		else
			*a = ft_ra(*a, *b, "ra\n");
		i++;
	}
}

void	ft_7_to_10(t_lst **a, t_lst **b)
{
	while (ft_is_category_in_lst(*a, 7) || ft_is_category_in_lst(*a, 8))
	{
		if ((*a)->category == 7 || (*a)->category == 8)
		{
			ft_pb(a, b);
			if ((*b)->category == 8)
				*b = ft_rb(*a, *b, "rb\n");
		}
		else
			*a = ft_ra(*a, *b, "ra\n");
	}
	ft_on_top(a, b, 9);
	ft_on_top(a, b, 10);
}

void	ft_sort_ba(t_lst **a, t_lst **b, int cat)
{
	while (ft_is_category_in_lst(*b, cat))
	{
		if (*b == ft_lst_cat_min(*b, cat))
		{
			ft_pa(a, b);
			if (ft_lstsize(*a) > 1)
				*a = ft_ra(*a, *b, "ra\n");
		}
		else if (*b == ft_lst_cat_max(*b, cat))
			ft_pa(a, b);
		else
		{
			if (ft_best_way(*b, cat))
				*b = ft_rb(*a, *b, "rb\n");
			else
				*b = ft_rrb(*a, *b, "rrb\n");
		}
	}
	if (ft_lstlast(*a))
		while (ft_lstlast(*a)->category == cat && ft_lstsize(*a) > 1
			&& (ft_lstlast(*a) != ft_lst_cat_max(*a, cat)
				|| ft_lst_cat_max(*b, cat)))
			*a = ft_rra(*a, *b, "rra\n");
}

void	ft_do_ss(t_lst **a, t_lst **b, int hicat, int locat)
{
	if (*a)
	{
		if ((*a)->next)
		{
			if ((*a)->category == hicat && (*a)->next->category == hicat
				&& (*a)->next->pos < (*a)->pos)
				ft_sa(a, b);
		}
	}
	if (*b)
	{
		if ((*b)->next)
		{
			if ((*b)->category == locat && (*b)->next->category == locat
				&& (*b)->next->pos > (*b)->pos)
				ft_sb(a, b);
		}
	}
}
