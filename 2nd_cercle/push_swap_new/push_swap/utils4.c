/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:22:05 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 16:23:01 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_lst_cat_min(t_lst *lst, int cat)
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
		if (lst->pos < res->pos && lst->category == cat)
			res = lst;
		lst = lst->next;
	}
	return (res);
}

int	ft_diff(int n1, int n2)
{
	int	res;

	res = n1 - n2;
	if (res < 0)
		res *= -1;
	return (res);
}

int	ft_mindiff(int n, int max, int min)
{
	int	res;

	res = ft_diff(n, max);
	if (res > ft_diff(n, min))
		res = ft_diff(n, min);
	if (res > ft_diff(0, max))
		res = ft_diff(0, max);
	if (res > ft_diff(0, min))
		res = ft_diff(0, min);
	return (res);
}

//renvoie 1 pour mettre en haut, 0 sinon
int	ft_best_way(t_lst *lst, int cat)
{
	int	i;
	int	size;
	int	minpos;
	int	maxpos;

	i = 0;
	size = ft_lstsize(lst);
	while (lst)
	{
		if (lst == ft_lst_cat_max(lst->first, cat))
			maxpos = i;
		else if (lst == ft_lst_cat_min(lst->first, cat))
			minpos = i;
		lst = lst->next;
		i++;
	}
	i = ft_mindiff(size, minpos, maxpos);
	if (i == ft_diff(size, minpos) || i == ft_diff(size, maxpos))
		return (0);
	return (1);
}

int	ft_strstr(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] == s1[i])
		i++;
	if (!s1[i] && !s2[i])
		return (1);
	return (0);
}
