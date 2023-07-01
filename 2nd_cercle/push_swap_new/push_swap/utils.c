/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:21:47 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/07/01 16:22:30 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
