/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:14:38 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 16:15:27 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_give_category(t_lst *lst, int i)
{
	int		n;
	t_lst	*first;

	i = 0;
	n = (ft_lst_count(lst) / 10) + (ft_lst_count(lst) % 10 / 5);
	first = lst->first;
	if (!n)
		n++;
	while (i < 10)
	{
		while (lst)
		{
			if (lst->pos / n == i)
				lst->category = i + 1;
			lst = lst->next;
		}
		lst = first;
		i++;
	}
	while (lst)
	{
		if (lst->category < 0)
			lst->category = 10;
		lst = lst->next;
	}
}
