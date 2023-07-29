/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:20:29 by dfleury           #+#    #+#             */
/*   Updated: 2023/03/10 14:54:47 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flag_set_prefix_x(unsigned int nbr, t_flag *flag, int upcase)
{
	if (flag->sharp && nbr != 0)
	{
		if (upcase)
			flag->prefix = "0X";
		else
			flag->prefix = "0x";
	}
	else
		flag->prefix = "";
}

static void	flag_init_x(t_flag *flag, int nbr, int upcase)
{
	int		current_len;

	flag->leading_spaces_len = 0;
	flag->zeros_len = 0;
	flag->digit_len = ft_countchars_uint_base(nbr, 16);
	flag->ending_spaces_len = 0;
	flag_set_prefix_x(nbr, flag, upcase);
	if (flag->precision > flag->digit_len)
		flag->zeros_len += flag->precision - flag->digit_len;
	current_len = flag->digit_len + flag->zeros_len + ft_strlen(flag->prefix);
	if (flag->width > current_len)
	{
		if (flag->left)
			flag->ending_spaces_len = flag->width - current_len;
		else if (flag->zero && !flag->precision)
			flag->zeros_len = flag->width - current_len;
		else
			flag->leading_spaces_len = flag->width - current_len;
	}
}

// *	(?) = facultatif
// *    leading_spaces(?) / prefix(?) / zeros(?) / absNumber / ending_spaces(?)
int	handle_x(unsigned int nbr, t_flag *flag, int upcase)
{
	int		total_len;

	total_len = 0;
	flag_init_x(flag, nbr, upcase);
	total_len += ft_printxchars(' ', flag->leading_spaces_len);
	total_len += ft_printstr(flag->prefix);
	total_len += ft_printxchars('0', flag->zeros_len);
	total_len += ft_printuint16(nbr, upcase);
	total_len += ft_printxchars(' ', flag->ending_spaces_len);
	return (total_len);
}
// total_len += put_debug_flag(flag);	// ! DEBUG
