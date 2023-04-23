/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:26:57 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/23 18:42:33 by vgiraudo         ###   ########.fr       */
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
	int	tmp;

	i = 0;
//printf("%d | %d\n", tab->size_a,  tab->size_b);
	while (i < tab->size_a)
	{
		tmp = tab->taba[i];
//		ft_printbinary(tmp);
//		printf(" | %d | ", tmp>>pow);
//		printf("%d", tmp >> pow & 1);
//		printf("yoyo\n");
		if (tmp >> pow & 1)
			ft_pa(tab->taba, tab->tabb, &(tab->size_a), &(tab->size_b));
		i++;
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
		temp[i] = new;
printf("%d|%d|%d\n", i, tab[i], new);
		if (i < size - 1)
			new = ft_get_new_min(tab, size, new);
		i++;
	}
	return (temp);
}

void	ft_r_down(int *tab, int size)
{
	int	i;

	i = size + 1;
	while (i)
	{
		tab[i] = tab[i - 1];
		i--;
	}
}

void	ft_r_up(int *tab, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = 0;
}

void	ft_r_push(int *tab1, int *tab2, int *size1, int *size2)
{
	int	i;

	i = 0;
	ft_down(tab1, *size1);
	printf("ok\n");
	tab1[0] = tab2[0];
	ft_up(tab2, *size2);
}

void	ft_pb(int *taba, int *tabb, int *size_a, int *size_b)
{
	ft_push(tabb, taba, size_b, size_a);
	*size_b += 1;
	*size_a -= 1;
	write(1, "pb\n", 3);
}

void	ft_pa(int *taba, int *tabb, int *size_a, int *size_b)
{
	ft_push(taba, tabb, size_a, size_b);
	*size_a += 1;
	*size_b -= 1;
	write(1, "pa\n", 3);
}

void	ft_radix(int *taba, int size_a)
{
	int		*tabb;
	int		size_b;
	int		pow;
	t_tab	*tab;

	tab = ft_init_struct(taba, tabb, size_a, 0);
	pow = 0;
	tab->indexa = ft_get_index(tab->taba, tab->size_a);
	tab->indexb = malloc(sizeof(int) * size_a);
	while (!ft_end(tab->taba, tab->tabb, tab->size_a, tab->size_b) && pow < 32)
	{
		printf("%d: ", pow);
		ft_pb_pow(tab, pow);
		ft_pa_all(tab->taba, tab->tabb, &tab->size_a, &tab->size_b);
		pow++;
		printf("\n");
	}
	free(tab->indexa);
	free(tab->indexb);
	free(tab);
}
