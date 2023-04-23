/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:27:28 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/30 08:27:28 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

t_pos	*ft_init_pos(int n, int *tab, int size)
{
	t_pos	*new;
	int		i;

	new = malloc(sizeof(t_pos));
	i = 0;
	new->pos = 0;
	new->value = n;
	while (i < size)
	{
		if (tab[i] < new->value)
		{
			new->value = tab[i];
			new->pos = i;
		}
		i++;
	}
	return (new);
}

void	ft_sa(int *taba, t_pos *item)
{
	if (item->pos == 1)
	{
		ft_swap(taba);
		write(1, "sa\n", 3);
		item->pos = 0;
	}
}

void	ft_top(int *taba, int *tabb, int *size_a, int *size_b)
{
	int		i;
	t_pos	*item;

	i = 0;
	item = ft_init_pos(taba[0], taba, *size_a);
	ft_sa(taba, item);
	while (item->pos)
	{
		ft_rotate(taba, *size_a);
		write(1, "ra\n", 3);
		item->pos--;
	}
	free(item);
}

void	ft_bot(int *taba, int *tabb, int *size_a, int *size_b)
{
	int		i;
	t_pos	*item;

	i = 0;
	item = ft_init_pos(taba[0], taba, *size_a);
	while (item->pos)
	{
		ft_revrot(taba, *size_a);
		write(1, "rra\n", 4);
		if (item->pos != *size_a - 1)
			item->pos++;
		else
			item->pos = 0;
	}
	free(item);
}
