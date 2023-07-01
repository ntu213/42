/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:57:09 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 16:57:20 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_lst	*ft_init_spaces(char *tmp)
{
	int		i;
	char	*str;
	t_lst	*new;

	i = 0;
	if (ft_isfullwspaces(tmp))
		return (NULL);
	str = ft_strdup(tmp);
	new = ft_init_lst(ft_atoi(str), -1, NULL, NULL);
	new->first = new;
	while (str[i])
	{
		while (!ft_iswhitespace(str[i]) && str[i])
			i++;
		while (ft_iswhitespace(str[i]))
			i++;
		if (!str[i])
			break ;
		new = ft_init_lst(ft_atoi(str + i), -1, NULL, new);
	}
	free(str);
	return (new->first);
}

t_lst	*ft_init_nospaces(char **str)
{
	int		i;
	t_lst	*new;

	i = 2;
	new = ft_init_lst(ft_atoi(str[1]), -1, NULL, NULL);
	new->first = new;
	while (str[i])
	{
		new = ft_init_lst(ft_atoi(str[i]), -1, NULL, new);
		i++;
	}
	return (new->first);
}

int	ft_hasdubs(t_lst *lst)
{
	t_lst	*lst2;
	int		i;
	int		j;

	i = 0;
	while (lst)
	{
		j = 0;
		lst2 = lst->first;
		while (lst2)
		{
			if (lst->val == lst2->val && i != j)
				return (1);
			lst2 = lst2->next;
			j++;
		}
		lst = lst->next;
		i++;
	}
	return (0);
}

int	ft_lst_count_nocat(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->category < 0)
			i++;
		lst = lst->next;
	}
	return (i);
}

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
