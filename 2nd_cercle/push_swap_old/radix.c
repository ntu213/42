/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:26:57 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/24 19:12:38 by vgiraudo         ###   ########.fr       */
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

void	ft_pa_all(t_tab *tab)
{
	while (tab->size_b)
		ft_r_pa(tab);
}

t_tab	*ft_init_struct(int *taba, int *tabb, int size_a, int size_b)
{
	t_tab	*new;

	new = malloc(sizeof(t_tab));
	new->taba = taba;
	new->tabb = tabb;
	new->size_a = size_a;
	new->size_b = size_b;
	new->indexa = NULL;
	new->indexb = NULL;
	return (new);
}

void	ft_printbinary(int n)
{
	int i = 0;

	printf("%d | ", n);
	while (i < 32)
	{
		printf("%d", n >> i & 1);
		i++;
	}
	printf("\n");
}

void	ft_pb_pow(t_tab *tab, int pow)
{
	int	i;
	int	j;
	int	tmp;
	int	tmp2;

	i = 0;
	j = 0;
	tmp2 = tab->size_a;
	while (j < tmp2)
	{
		tmp = tab->indexa[i];
	printf("%d | %d | %d | %d\n", tmp, tab->taba[i], tmp >> pow & 1, i);
		if (tmp >> pow & 1)
			ft_r_pb(tab);
		else
		{
			i++;
			ft_r_rot(tab->taba, tab->indexa, tab->size_a, "ra\n");
		}
		j++;
	}
}

int	ft_get_new_min(int *tab, int size, int old)
{
	int	new;
	int i;

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
		temp[i] = i + 1;
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
//	printf("a = %d | %d\n", tab1[size - 1], size);
	while (i)
	{
		tab1[i] = tab1[i - 1];
		tab2[i] = tab2[i - 1];
		i--;
	}
}

void	ft_r_up(int *tab1, int *tab2, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		tab1[i] = tab1[i + 1];
		tab2[i] = tab2[i + 1];
		i++;
	}
	tab1[i] = 0;
	tab2[i] = 0;
}

void	ft_r_rot(int *tab1, int *tab2, int size, char *str)
{
	int	n1;
	int	n2;

	n1 = tab1[0];
	n2 = tab2[0];
	ft_r_up(tab1, tab2, size);
	tab1[size - 1] = n1;
	tab2[size - 1] = n2;
	write(1, str, 3);
}

void	ft_r_pb(t_tab *tab)
{
	ft_r_down(tab->indexb, tab->tabb, tab->size_b);
	tab->indexb[0] = tab->indexa[0];
	tab->tabb[0] = tab->taba[0];
	ft_r_up(tab->indexa, tab->taba, tab->size_a);
	tab->size_b += 1;
	tab->size_a -= 1;
	write(1, "pb\n", 3);
}

void	ft_r_pa(t_tab *tab)
{
	ft_r_down(tab->indexa, tab->taba, tab->size_a);
	tab->indexa[0] = tab->indexb[0];
	tab->taba[0] = tab->tabb[0];
	ft_r_up(tab->indexb, tab->tabb, tab->size_b);
	tab->size_a += 1;
	tab->size_b -= 1;
	write(1, "pa\n", 3);
}


void	ft_temp_printtab(int *tab, int size)
{
	int i = 0;
	while (i < size)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}

void	ft_radix(int *taba, int size_a)
{
	int		*tabb;
	int		size_b;
	int		pow;
	t_tab	*tab;

	tabb = malloc(sizeof(int) * size_a);
	tab = ft_init_struct(taba, tabb, size_a, 0);
	pow = 0;
	tab->indexa = ft_get_index(tab->taba, tab->size_a);
	tab->indexb = malloc(sizeof(int) * size_a);
ft_temp_printtab(tab->indexa, tab->size_a);
	while (!ft_end(tab->taba, tab->tabb, tab->size_a, tab->size_b) && pow < 10)
	{
		printf("%d: ", pow);
		ft_pb_pow(tab, pow);
		ft_pa_all(tab);
		pow++;
//		printf("\n");
	}
	free(tab->indexa);
	free(tab->indexb);
	free(tabb);
	free(tab);
}
