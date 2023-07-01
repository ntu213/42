/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:02:19 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 17:02:40 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_iswhitespace(char c)
{
	if (c == 32 || (c <= 13 && c >= 9))
		return (1);
	return (0);
}

int	ft_haswspaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_iswhitespace(str[i]))
			return (1);
		i++;
	}
	if (!i)
		return (1);
	return (0);
}

int	ft_isfullwspaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_iswhitespace(str[i]))
			return (0);
		i++;
	}
	return (1);
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
