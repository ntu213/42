/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:10:21 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/02 21:08:47 by vgiraudo         ###   ########.fr       */
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

void	ft_int_writer(int nbr, int n)
{
	char	*str;

	if (nbr >= 0 && n)
		ft_putchar_fd('+', 1);
	ft_putstr_fd(ft_itoa(nbr), 1);
}

void	ft_unsint_writer(unsigned int nbr, int n)
{
	char	*str;
	int		nbr2;
	int		i;

	nbr2 = nbr;
	i = 1;
	if (nbr >= 0 && n)
		ft_putchar_fd('+', 1);
	while (nbr2)
	{
		i++;
		nbr2 /= 10;
	}
	str = malloc(sizeof(char) * i);
	i = 0;
	while (nbr)
	{
		str[i++] = nbr % 10;
		nbr /= 10;
	}
	str[i] = 0;
	ft_reverse(str);
	ft_putstr_fd(str, 1);
	free(str);
}

int	ft_error()
{
	write(1, "%", 1);
	return (1);
}

int	ft_tester(va_list *arg, const char* origin)
{
	int		i;
	t_obj	*item;

	i = 1;
	item = malloc(sizeof(t_obj));
	while (origin[i] && !ft_comp(origin[i], "cspdiuxX%"))
	{
		if (!ft_midverif(item, origin[i]))
			return (ft_error());
		i++;
	}
	if (!origin[i])
		return (ft_error());
	if (item->space)
		write(1, " ", 1);
	if ((origin[i] == 'x' || origin[i] == 'X') && item->hash)
		write(1, "0x", 2);
write(1, "OK", 2);
	if (origin[i] == 'c')
		ft_putchar_fd((char)va_arg(*arg, int), 1);
	else if (origin[i] == 's')
		ft_putstr_fd(va_arg(*arg, char *), 1);
	else if (origin[i] == 'p')
		ft_putstr_fd(ft_ptochar(va_arg(*arg, void *), "0123456789abcdef"), 1);
	else if (origin[i] == 'x')
		ft_putstr_fd(int_base(va_arg(*arg, int), "0123456789abcdef"), 1);
	else if (origin[i] == 'X')
		ft_putstr_fd(int_base(va_arg(*arg, int), "0123456789ABCDEF"), 1);
	else if (origin[i] == 'd' || origin[i] == 'i')
		ft_int_writer(va_arg(*arg, int), item->plus);
	else if (origin[i] == '%')
		ft_error();
	else
		ft_unsint_writer(va_arg(*arg, int), item->plus);
	return (i);
}

int	ft_printf(const char *origin, ...)
{
	va_list	*arg;
	int		i;
	int		j;

	i = 0;
	j = ft_count(origin) + 1;
	while (j && origin[i])
	{
		if (origin[i] == '%')
		{
			i += ft_tester(arg, origin + i);
			j--;
		}
		else
		{
			write(1, &origin[i], 1);
			i++;
		}
	}
}

void	main(int argc, char ** argv)
{
	int	i = 1;

	ft_printf("salut j'ai %c", 'y');
/*	while (i < argc)
	{
		printf(argv[i], argv[i + 1]);
		ft_printf(argv[i], argv[i + 1]);
		write (1, "\n", 1);
		i += 2;
	}*/
}