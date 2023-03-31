/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:26:57 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/31 10:07:32 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pow(int n, int exp)
{
	int	i;

	i = n;
	exp--;
	while (exp > 0)
	{
		i *= n;
		exp--;
	}
	return (i);
}

void	ft_pa_all(int *taba, int *tabb, int *size_a, int *size_b)
{
	while (*size_b)
		ft_pa(taba, tabb, size_a, size_b);
}

t_tab	*ft_init_struct(int *taba, int *tabb, int size_a, int size_b)
{
	t_tab	*new;

	new = malloc(sizeof(t_tab));
	new->taba = taba;
	new->tabb = tabb;
	new->size_a = size_a;
	new->size_b = size_b;
	new->btaba = NULL;
	new->btabb = NULL;
	new->indexa = NULL;
	new->indexb = NULL;
	return (new);
}

int	*ft_get_bin(int n)
{
	int	*bin;
	int	pow;
	int	i;

	pow = 1073741824;
	i = 1;
	if (n < 0)
		n *= -1;
	if (n < 0)
		bin[0] = 1;
	else
		bin[0] = 0;
	while (pow)
	{
		if (n <= pow)
			n -= pow;
		if (n <= pow)
			bin[i] = 1;
		else
			bin[i] = 0;
		pow /= 2;
		i++;
	}
	return (bin);
}

void	ft_to_bin(t_tab *tab, int pow)
{
	int	i;

	i = 0;
	while (i < tab->size_a)
	{
		tab->btaba[i] = ft_get_bin(tab->taba[i]);
		i++;
	}
}

void	ft_pb_pow(t_tab *tab, int pow)
{
	int	i;

	i = 0;
	while (i < tab->size_b)
	{
		printf("%d", tab->btaba[i][pow]);
		if (tab->btaba[i][pow])
			ft_pa(tab->taba, tab->tabb, &tab->size_a, &tab->size_b);
		i++;
	}
}

int	ft_get_new_min(int *tab, int size, int old)
{
	int	new;
	int i;

	i = 0;
	while (tab[i] <= old && size)
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

void	ft_get_index(int *tab, int size, int *index)
{
	int	i;
	int	new;
	int	*temp;

	i = 0;
	new = ft_getmin(tab, size);
	while (i < size)
	{
		index[i] = new;
		new = ft_get_new_min(tab, size, new);
		i++;
	}
}

void	ft_radix(int *taba, int size_a)
{
	int		*tabb;
	int		size_b;
	int		pow;
	t_tab	*tab;

	tab = ft_init_struct(taba, tabb, size_a, 0);
	pow = 0;
	ft_get_index(tab->taba, tab->size_a, tab->indexa);
	while (!ft_end(tab->taba, tab->tabb, tab->size_a, tab->size_b) && pow < 32)
	{
		printf("%d: ", pow);
		ft_pb_pow(tab, pow);
		ft_pa_all(tab->taba, tab->tabb, &tab->size_a, &tab->size_b);
		pow++;
		printf("\n");
	}
	free(tab);
}
