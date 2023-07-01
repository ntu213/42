/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 15:49:27 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 15:49:59 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_end(t_lst *a, t_lst *b)
{
	int		n;
	t_lst	*first;

	first = a;
	n = a->val;
	while (a)
	{
		if (a->val < n)
			return (0);
		n = a->val;
		a = a->next;
	}
	n = first->val;
	while (b)
	{
		if (b->val > n)
			return (0);
		n = b->val;
		b = b->next;
	}
	return (1);
}

int	ft_is_on_top(t_lst *a, t_lst *b)
{
	int	i;
	int	target;

	(void)b;
	i = 0;
	target = ft_lst_min(a);
	while (a && a->val != target)
	{
		a = a->next;
		i++;
	}
	if (i > ft_lstsize(a) / 2)
		return (0);
	return (1);
}

t_lst	*ft_kebab(t_lst *a)
{
	t_lst	*b;
	char	*str;

	b = NULL;
	str = "";
	ft_give_pos(a);
	ft_give_str(a, &str);
	while (!ft_is_end(a, b))
	{
		if (a->next && a->next->pos == a->pos - 1)
			ft_sa(&a, &b);
		else if ((b && a->pos == b->pos + 1) || a->pos == 0)
			ft_pb(&a, &b);
		else if (ft_is_on_top(a, b))
			a = ft_ra(a, b, "ra\n");
		else
			a = ft_rra(a, b, "rra\n");
	}
	while (b)
		ft_pa(&a, &b);
	ft_print_str(a, "");
	return (a);
}
