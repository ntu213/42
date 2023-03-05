/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:43:59 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/05 16:03:55 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(const char *origin)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (origin[i])
	{
		if (origin[i] == '%')
			j++;
		i++;
	}
	return (j);
}

int	ft_comp(char orig, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == orig)
			return (1);
		i++;
	}
	return (0);
}

int	ft_midverif(t_obj *item, char c)
{
	if (c == ' ')
	{
		item->space = 1;
		return (1);
	}
	else if (c == '#')
	{
		item->hash = 1;
		return (1);
	}
	else if (c == '+')
	{
		item->plus = 1;
		return (1);
	}
	return (0);
}

void	ft_int_writer(int nbr, t_obj *item)
{
	char	*str;

	if (nbr == INT_MIN)
	{
		write(1, "-2147483648", 11);
		item->total += 11;
		return ;
	}
	if (item->space && !item->plus && nbr >= 0)
	{
		write(1, " ", 1);
		item->total++;
	}
	else if (nbr >= 0 && item->plus)
	{
		ft_putchar_fd('+', 1);
		item->total++;
	}
	str = ft_itoa(nbr);
	ft_putstr_fd(str, 1, item);
	item->total += ft_strlen(str);
}

void	ft_unsint_writer(unsigned int nbr, t_obj *item, int kebab)
{
	char	c;

	if (nbr)
	{
		ft_unsint_writer(nbr / 10, item, 1);
		c = (nbr % 10) + '0';
		write(1, &c, 1);
		item->total++;
	}
	else if (!kebab)
	{
		write(1, "0", 1);
		item->total++;
	}
}
