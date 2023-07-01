/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:22:01 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 16:22:41 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_newfirst(t_lst *first, t_lst *new)
{
	while (first)
	{
		first->first = new;
		first = first->next;
	}
}

t_lst	*ft_lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_lst	*ft_lstprev(t_lst *lst, t_lst *addr)
{
	if (!lst)
		return (NULL);
	while (lst->next && lst->next != addr)
		lst = lst->next;
	return (lst);
}

int	ft_lst_count(t_lst *lst)
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

int	ft_lst_min(t_lst *lst)
{
	int	n;

	n = lst->val;
	while (lst)
	{
		if (lst->val < n)
			n = lst->val;
		lst = lst->next;
	}
	return (n);
}
