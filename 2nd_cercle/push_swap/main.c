/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:11:17 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/31 10:52:28 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int n)
{
	write(2, "Error\n", 6);
	return (n);
}

void	ft_fullfree(char **str, t_tab *tab)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	i = 0;
	while (i < tab->size)
	{
		free(tab->tab[i]);
		i++;
	}
	free(str);
	free(tab);
}

int	ft_in_tab(int n, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (n == tab[i])
			return (0);
		i++;
	}
	tab[i] = n;
	return (1);
}

int	ft_verif(char **str, int *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
	{
		if (!ft_in_tab(ft_atoi(str[j]), tab, j))
			return (0);
		while (str[j][i])
		{
			if (!((str[j][i] >= '0' && str[j][i] <= '9') || str[j][0] == '-'))
				return (0);
			i++;
		}
		j++;
		i = 0;
	}
	return (j);
}

int	main(int argc, char **argv)
{
	int		i;
	int		arg;
	int		*tab;
	char	**str;
	t_tab	a;

	i = 1;
	str = ft_split(argv[1], ' ');
	arg = argc - 1;
	if (argc == 2)
	{
		arg = ft_verif(str, tab);
		if (!arg)
			return (ft_error(0));
	}
	else if (argc == 1 || !ft_verif(argv + 1, tab))
		return (ft_error(0));
	a = ft_init_tab(tab, arg);
	if (arg < 3)
		ft_run(a);
	else
		ft_radix(a);
	ft_free(str, a);
	return (1);
}
