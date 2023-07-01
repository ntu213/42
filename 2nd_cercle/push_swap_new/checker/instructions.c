/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:59:14 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 16:59:34 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_lst	*ft_ra(t_lst *a, t_lst *b)
{
	t_lst	*first;

	first = a->next;
	(void)b;
	ft_lstlast(a)->next = a;
	a->next = NULL;
	ft_newfirst(first, first);
	return (a->first);
}

t_lst	*ft_rb(t_lst *a, t_lst *b)
{
	t_lst	*first;

	first = b->next;
	(void)a;
	ft_lstlast(b)->next = b;
	b->next = NULL;
	ft_newfirst(first, first);
	return (b->first);
}

void	ft_rr(t_lst **a, t_lst **b)
{
	if (*a)
	{
		*a = ft_ra(*a, *b);
		*a = (*a)->first;
	}
	if (*b)
	{
		*b = ft_rb(*a, *b);
		*b = (*b)->first;
	}
}

t_lst	*ft_rra(t_lst *a, t_lst *b)
{
	t_lst	*tmp;

	(void)b;
	ft_newfirst(a, ft_lstlast(a));
	tmp = ft_lstlast(a);
	ft_lstprev(a, tmp)->next = NULL;
	tmp->next = a;
	return (a->first);
}

t_lst	*ft_rrb(t_lst *a, t_lst *b)
{
	t_lst	*tmp;

	(void)a;
	ft_newfirst(b, ft_lstlast(b));
	tmp = ft_lstlast(b);
	ft_lstprev(b, ft_lstlast(b))->next = NULL;
	tmp->next = b;
	return (b->first);
}
