/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:10:15 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 16:12:55 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	ft_newfirst(*b, *b);
	ft_print_str(*a, "pa\n");
}

void	ft_pb(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	ft_newfirst(*a, *a);
	ft_print_str(*b, "pb\n");
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
	ft_print_str(*a, "sa\n");
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
	ft_print_str(*b, "sb\n");
}

void	ft_ss(t_lst **a, t_lst **b)
{
	t_lst	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *a;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *b;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	ft_print_str(*a, "ss\n");
}
