/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:59:22 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 17:00:24 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}
