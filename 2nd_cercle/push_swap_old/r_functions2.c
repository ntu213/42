/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_functions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:58:47 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/28 10:00:43 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_new_min(int *tab, int size, int old)
{
	int	new;
	int	i;

	i = 0;
	while (tab[i] <= old && i < size)
		i++;
	new = tab[i];
	i = 0;
	while (i < size)
	{
		if (tab[i] < new && !(tab[i] <= old))
			new = tab[i];
		i++;
	}
	return (new);
}

int	ft_nb_pos(int *tab, int pos, int n)
{
	int	i;

	i = 0;
	while (tab[i] != n && i < pos)
		i++;
	return (i);
}

int	*ft_get_index(int *tab, int size)
{
	int	i;
	int	new;
	int	*temp;

	i = 0;
	temp = malloc(sizeof(int) * size);
	new = ft_getmin(tab, tab, size, size);
	while (i < size)
	{
		temp[ft_nb_pos(tab, size, new)] = i + 1;
		if (i < size - 1)
			new = ft_get_new_min(tab, size, new);
		i++;
	}
	return (temp);
}

void	ft_r_down(int *tab1, int *tab2, int size)
{
	int	i;

	i = size + 1;
	while (i)
	{
		tab1[i] = tab1[i - 1];
		tab2[i] = tab2[i - 1];
		i--;
	}
}
