/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:10:21 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/04 18:24:59 by vgiraudo         ###   ########.fr       */
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
	else if(c == '#')
	{
		item->hash = 1;
		return (1);
	}
	else if(c == '+')
	{
		item->plus = 1;
		return (1);
	}
	return (0);
}

void	ft_int_writer(int nbr, t_obj *item)
{
	char	*str;

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
	ft_putstr_fd(str, 1);
	item->total += ft_strlen(str);
}

void	ft_unsint_writer(unsigned int nbr, t_obj *item)
{
	char	c;

	if (nbr)
	{
		ft_unsint_writer(nbr / 10, item);
		c = (nbr % 10) + '0';
		write(1, &c, 1);
		item->total++;
	}
}

int	ft_error(int i, t_obj *item)
{
	write(1, "%", 1);
	item->total++;
	return (i);
}

int	ft_tester(va_list *arg, const char* origin, int i, t_obj *item)
{
	char	*str;

	i++;
	while (origin[i] && !ft_comp(origin[i], "cspdiuxX%"))
	{
		if (!ft_midverif(item, origin[i]))
			return (ft_error(i, item));
		i++;
	}
	if (!origin[i])
		return (ft_error(i, item));
	if ((origin[i] == 'x') && item->hash)
		write(1, "0x", 2);
	else if ((origin[i] == 'X') && item->hash)
		write(1, "0X", 2);
	if ((origin[i] == 'x' || origin[i] == 'X') && item->hash)
		item->total += 2;
	if (origin[i] == 'c')
	{
		ft_putchar_fd(va_arg(*arg, int), 1);
		item->total++;
	}
	else if (origin[i] == 's')
	{
		str = va_arg(*arg, char *);
		ft_putstr_fd(str, 1);
		item->total += ft_strlen(str);
	}
	else if (origin[i] == 'p')
		ft_ptochar(va_arg(*arg, void *), "0123456789abcdef", item);
	else if (origin[i] == 'x')
		int_base(va_arg(*arg, int), "0123456789abcdef", item);
	else if (origin[i] == 'X')
		int_base(va_arg(*arg, int), "0123456789ABCDEF", item);
	else if (origin[i] == 'd' || origin[i] == 'i')
		ft_int_writer(va_arg(*arg, int), item);
	else if (origin[i] == '%')
		ft_error(i, item);
	else
		ft_unsint_writer(va_arg(*arg, int), item);
	return (i + 1);
}

void	ft_item_reset(t_obj *item)
{
	item->hash = 0;
	item->space = 0;
	item->plus = 0;
}

int	ft_printf(const char *origin, ...)
{
	t_obj	*item;
	va_list	arg;
	int		i;

	i = 0;
	item = malloc(sizeof(t_obj));
	va_start(arg, origin);
	while (origin[i])
	{
		if (origin[i] == '%')
		{
			i = ft_tester(&arg, origin, i, item);
			ft_item_reset(item);
		}
		else
		{
			write(1, &origin[i], 1);
			i++;
			item->total++;
		}
	}
	return (item->total);
}
