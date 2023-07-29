/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:20:29 by dfleury           #+#    #+#             */
/*   Updated: 2023/03/10 14:54:51 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flag_set_prefix_i_d(int nbr, t_flag *flag)
{
	if (nbr < 0)
		flag->prefix = "-";
	else if (flag->plus)
		flag->prefix = "+";
	else if (flag->space)
		flag->prefix = " ";
	else
		flag->prefix = "";
}

static void	flag_init_i_d(t_flag *flag, int nbr)
{
	int		current_len;

	flag->leading_spaces_len = 0;
	flag->zeros_len = 0;
	flag->digit_len = ft_countchars_int(nbr, 0);
	flag->ending_spaces_len = 0;
	flag_set_prefix_i_d(nbr, flag);
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
int	handle_id(int nbr, t_flag *flag)
{
	int		total_len;

	total_len = 0;
	flag_init_i_d(flag, nbr);
	total_len += ft_printxchars(' ', flag->leading_spaces_len);
	total_len += ft_printstr(flag->prefix);
	total_len += ft_printxchars('0', flag->zeros_len);
	total_len += ft_printint_abs(nbr);
	total_len += ft_printxchars(' ', flag->ending_spaces_len);
	return (total_len);
}
// total_len += put_debug_flag(flag);	// ! DEBUG
