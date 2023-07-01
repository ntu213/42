/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:18:07 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 16:19:28 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sem_sort(t_lst **a, t_lst **b, int hicat, int locat)
{
	while (ft_is_category_in_lst(*b, locat) || ft_is_category_in_lst(*b, hicat))
	{
		if ((*b)->category == locat || (*b)->category == hicat)
		{
			ft_pa(a, b);
			if ((*a)->category == locat)
				*a = ft_ra(*a, *b, "ra\n");
		}
		else
			*b = ft_rb(*a, *b, "rb\n");
	}
	ft_on_top(a, b, hicat);
	ft_sort_ba(a, b, hicat);
}

void	ft_sort_aa(t_lst **a, t_lst **b, int cat)
{
	while (ft_lstlast(*a)->category == cat)
	{
		*a = ft_rra(*a, *b, "rra\n");
		if ((*a)->pos != (*a)->next->pos - 1)
			ft_pb(a, b);
	}
}

void	ft_give_str(t_lst *lst, char **str)
{
	while (lst)
	{
		lst->str = str;
		lst = lst->next;
	}
}

t_lst	*ft_quicksort(t_lst *a)
{
	t_lst	*b;
	char	*str;

	b = NULL;
	str = "";
	ft_give_str(a, &str);
	ft_give_pos(a);
	ft_give_category(a, 0);
	ft_1_to_6(&a, &b);
	ft_7_to_10(&a, &b);
	ft_sort_ba(&a, &b, 10);
	ft_sort_ba(&a, &b, 9);
	ft_sort_ba(&a, &b, 8);
	ft_sort_ba(&a, &b, 7);
	ft_sem_sort(&a, &b, 6, 1);
	ft_sem_sort(&a, &b, 5, 2);
	ft_sem_sort(&a, &b, 4, 3);
	ft_sort_aa(&a, &b, 3);
	ft_sort_ba(&a, &b, 3);
	ft_sort_aa(&a, &b, 2);
	ft_sort_ba(&a, &b, 2);
	ft_sort_aa(&a, &b, 1);
	ft_sort_ba(&a, &b, 1);
	ft_print_str(a, "");
	return (a);
}
