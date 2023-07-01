/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:10:30 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 16:12:05 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_ra(t_lst *a, t_lst *b, char *str)
{
	t_lst	*first;

	first = a->next;
	(void)b;
	ft_lstlast(a)->next = a;
	a->next = NULL;
	ft_newfirst(first, first);
	ft_print_str(a, str);
	return (a->first);
}

t_lst	*ft_rb(t_lst *a, t_lst *b, char *str)
{
	t_lst	*first;

	first = b->next;
	(void)a;
	ft_lstlast(b)->next = b;
	b->next = NULL;
	ft_newfirst(first, first);
	ft_print_str(b, str);
	return (b->first);
}

void	ft_rr(t_lst **a, t_lst **b)
{
	if (*a)
	{
		*a = ft_ra(*a, *b, "");
		*a = (*a)->first;
	}
	if (*b)
	{
		*b = ft_rb(*a, *b, "");
		*b = (*b)->first;
	}
	ft_print_str(*a, "rr\n");
}

t_lst	*ft_rra(t_lst *a, t_lst *b, char *str)
{
	t_lst	*tmp;

	(void)b;
	ft_newfirst(a, ft_lstlast(a));
	tmp = ft_lstlast(a);
	ft_lstprev(a, tmp)->next = NULL;
	tmp->next = a;
	ft_print_str(a, str);
	return (a->first);
}

t_lst	*ft_rrb(t_lst *a, t_lst *b, char *str)
{
	t_lst	*tmp;

	(void)a;
	ft_newfirst(b, ft_lstlast(b));
	tmp = ft_lstlast(b);
	ft_lstprev(b, ft_lstlast(b))->next = NULL;
	tmp->next = b;
	ft_print_str(b, str);
	return (b->first);
}
