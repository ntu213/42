/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:02:14 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 17:02:32 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_lst	*ft_init_lst(int val, int pos, t_lst *first, t_lst *nextof)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	new->val = val;
	new->pos = pos;
	new->category = -1;
	new->first = first;
	new->next = NULL;
	if (nextof)
	{
		new->next = nextof->next;
		new->first = nextof->first;
		nextof->next = new;
	}
	return (new);
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

void	ft_newfirst(t_lst *first, t_lst *new)
{
	while (first)
	{
		first->first = new;
		first = first->next;
	}
}

void	ft_free_lst(t_lst *lst)
{
	t_lst	*next;

	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
}
