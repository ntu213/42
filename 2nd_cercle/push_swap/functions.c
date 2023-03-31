/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:15:48 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/31 10:53:04 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_val *ft_init_val(int n)
{
	t_val *new;

	new = malloc(sizeof(t_val));
	new->val = n;
	return (new);
}

t_tab	*ft_init_tab(int *tab, int size)
{
	int		i;
	t_tab	*new;

	i = 0;
	new = malloc(sizeof(t_tab));
	while (i < size)
	{
		new->tab[i] = ft_init_val(tab[i]);
		i++;
	}
}
