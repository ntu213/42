/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:48:53 by dfleury           #+#    #+#             */
/*   Updated: 2023/03/10 14:46:41 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_args_flag(va_list	args, t_flag *flag)
{
	int	total_len;

	total_len = 0;
	if (flag->typ == 'c')
		total_len += handle_c(va_arg(args, int), flag);
	else if (flag->typ == 's')
		total_len += handle_s(va_arg(args, char *), flag);
	else if (flag->typ == 'p')
		total_len += handle_p(va_arg(args, unsigned long), flag);
	else if (flag->typ == 'i' || flag->typ == 'd')
		total_len += handle_id(va_arg(args, int), flag);
	else if (flag->typ == 'u')
		total_len += handle_u(va_arg(args, unsigned int), flag);
	else if (flag->typ == 'x')
		total_len += handle_x(va_arg(args, unsigned int), flag, 0);
	else if (flag->typ == 'X')
		total_len += handle_x(va_arg(args, unsigned int), flag, 1);
	else if (flag->typ == '%')
		total_len += ft_printchar('%');
	return (total_len);
}

static t_flag	*update_flag_from_charg(const char c, t_flag *flag)
{
	if (c == '+')
	{
		flag->plus = 1;
		flag->space = 0;
	}
	else if (c == '-')
		flag->left = 1;
	else if (c == ' ' && !flag->plus)
		flag->space = 1;
	else if (c == '#')
		flag->sharp = 1;
	else if (c == '.')
		flag->dot = 1;
	else if (c == '0' && flag->width == 0 && flag->precision == 0)
		flag->zero = 1;
	else if (ft_isdigit(c) && !flag->dot)
		flag->width = flag->width * 10 + c - '0';
	else if (ft_isdigit(c) && flag->dot)
		flag->precision = flag->precision * 10 + c - '0';
	return (flag);
}

static t_flag	*get_flag(const char *str, int i, t_flag *flag)
{
	if (!flag)
		return (NULL);
	while (!ft_isalpha(str[i]) && str[i] != '%')
	{
		update_flag_from_charg(str[i], flag);
		flag->len++;
		i++;
	}
	flag->typ = str[i];
	return (flag);
}

static t_flag	*new_flag(void)
{
	t_flag	*flag;

	flag = malloc(sizeof(t_flag));
	if (!flag)
		return (NULL);
	flag->plus = 0;
	flag->space = 0;
	flag->left = 0;
	flag->zero = 0;
	flag->dot = 0;
	flag->sharp = 0;
	flag->precision = 0;
	flag->width = 0;
	flag->typ = '?';
	flag->len = 1;
	flag->leading_spaces_len = 0;
	flag->zeros_len = 0;
	flag->digit_len = 0;
	flag->ending_spaces_len = 0;
	return (flag);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_flag	*flag;
	int		i;
	int		total_len;

	i = 0;
	total_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			flag = get_flag(str, i + 1, new_flag());
			if (!flag)
				return (0);
			i += flag->len;
			total_len += handle_args_flag(args, flag);
			free(flag);
		}
		else
			total_len += ft_printchar(str[i]);
		i++;
	}
	va_end (args);
	return (total_len);
}

/*
-
	Left-justify within the given field width;
	Right justification is the default (see width sub-specifier).


+
	Forces to precede the result with a plus or minus sign (+ or -)
	 even for positive numbers.
	By default, only negative numbers are preceded with a -ve sign.


(space)
	If no sign is going to be written,
	 a blank space is inserted before the value.

#
	Used with o, x or X specifiers the value is preceded with 0, 0x or 0X
	 respectively for values different than zero.
	Used with e, E and f, it forces the written output to contain a
	 decimal point even if no digits would follow.
	By default, if no digits follow, no decimal point is written.
	Used with g or G the result is the same as with e or E but trailing zeros
	 are not removed.

0
	Left-pads the number with zeroes (0) instead of spaces,
	 where padding is specified (see width sub-specifier).


*/