/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:59:17 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 16:59:43 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rrr(t_lst **a, t_lst **b)
{
	if (*a)
	{
		*a = ft_rra(*a, *b);
		*a = (*a)->first;
	}
	if (*b)
	{
		*b = ft_rrb(*a, *b);
		*b = (*b)->first;
	}
}

void	ft_pa(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	ft_newfirst(*b, *b);
}

void	ft_pb(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	ft_newfirst(*a, *a);
}

void	ft_sa(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	(void)b;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *a;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	ft_sb(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	(void)a;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *b;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
}
