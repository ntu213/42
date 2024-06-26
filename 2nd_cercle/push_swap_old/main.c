/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:27:05 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/30 08:27:05 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int n)
{
	write(2, "Error\n", 6);
	return (n);
}

int	ft_ok_2(int n, int *tab, int size)
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

int	ft_ok(char **strr, int n, int *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < n)
	{
		if (!ft_ok_2(ft_atoi(strr[j]), tab, j - 1))
			return (0);
		while (strr[j][i])
		{
			if (!((strr[j][i] >= '0' && strr[j][i] <= '9')
				|| strr[j][0] == '-'))
				return (0);
			i++;
		}
		j++;
		i = 0;
	}
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
		if (!ft_ok_2(ft_atoi(str[j]), tab, j))
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

	i = 1;
	tab = ft_calloc(argc - 1, sizeof(int));
	str = ft_split(argv[1], ' ');
	arg = argc - 1;
	if (argc == 2)
	{
		free(tab);
		tab = ft_calloc(ft_strrlen(str), sizeof(int));
		arg = ft_verif(str, tab);
		if (!arg)
			return (ft_error(0));
	}
	else if (argc == 1 || !ft_ok(argv, argc, tab))
		return (ft_error(0));
	if (arg < 55)
		ft_run(tab, arg);
	else
		ft_radix(tab, arg);
	ft_free(str, tab);
	return (1);
}
