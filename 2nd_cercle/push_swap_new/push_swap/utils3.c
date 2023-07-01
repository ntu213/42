/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:22:03 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 16:22:53 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_max(t_lst *lst)
{
	int	n;

	n = lst->val;
	while (lst)
	{
		if (lst->val > n)
			n = lst->val;
		lst = lst->next;
	}
	return (n);
}

void	ft_val_pos(t_lst *lst, int val, int pos)
{
	while (lst)
	{
		if (lst->val == val)
			lst->pos = pos;
		lst = lst->next;
	}
}

int	ft_lstsize(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_is_category_in_lst(t_lst *lst, int cat)
{
	while (lst)
	{
		if (lst->category == cat)
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_lst	*ft_lst_cat_max(t_lst *lst, int cat)
{
	t_lst	*res;

	res = NULL;
	while (!res && lst)
	{
		if (lst->category == cat)
			res = lst;
		lst = lst->next;
	}
	while (lst)
	{
		if (lst->pos > res->pos && lst->category == cat)
			res = lst;
		lst = lst->next;
	}
	return (res);
}
