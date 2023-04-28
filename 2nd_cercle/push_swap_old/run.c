/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:27:01 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/30 08:27:01 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_tab(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
}

int	ft_istop(int *taba, int size_a)
{
	int	i;
	int	pos;
	int	mem;

	i = 0;
	mem = taba[0];
	pos = i;
	while (i < size_a)
	{
		if (mem > taba[i])
		{
			mem = taba[i];
			pos = i;
		}
		i++;
	}
	if (pos <= size_a / 2)
		return (1);
	return (0);
}

int	ft_getmin(int *taba, int *tabb, int size_a, int size_b)
{
	int	pos;
	int	i;

	i = 0;
	pos = taba[0];
	while (i < size_a)
	{
		if (taba[i] < pos)
			pos = taba[i];
		i++;
	}
	i = 0;
	while (i < size_b)
	{
		if (tabb[i] < pos)
			pos = tabb[i];
		i++;
	}
	return (pos);
}

int	ft_end(int *taba, int *tabb, int size_a, int size_b)
{
	int	pos;
	int	i;

	pos = ft_getmin(taba, tabb, size_a, size_b);
	i = 1;
	if (pos > taba[0])
		return (0);
	while (i < size_a)
	{
		if (taba[i] < taba[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_run(int *taba, int size_a)
{
	int	tabb
	[size_a];
	int	size_b;
	int	hasrun;

	size_b = 0;
	hasrun = 0;
	ft_init_tab(tabb, size_a);
	while (!ft_end(taba, tabb, size_a, size_b))
	{
		while (hasrun-- && taba[0] == ft_getmin(taba, taba, size_a, size_a))
			ft_pb(taba, tabb, &size_a, &size_b);
		if (ft_istop(taba, size_a))
			ft_top(taba, tabb, &size_a, &size_b);
		else
			ft_bot(taba, tabb, &size_a, &size_b);
		hasrun = 1;
	}
	while (size_b)
		ft_pa(taba, tabb, &size_a, &size_b);
}
