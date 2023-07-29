/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:20:29 by dfleury           #+#    #+#             */
/*   Updated: 2023/03/10 14:54:50 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flag_set_prefix_p(t_flag *flag, unsigned long nbr)
{
	if (nbr)
		flag->prefix = "0x";
	else
		flag->prefix = "";
}

static void	flag_init_p(t_flag *flag, unsigned long nbr)
{
	int		current_len;

	flag->leading_spaces_len = 0;
	flag->zeros_len = 0;
	if (nbr == 0)
		flag->digit_len = ft_strlen("(nil)");
	else
		flag->digit_len = ft_countchars_ulong_base(nbr, 16);
	flag->ending_spaces_len = 0;
	flag_set_prefix_p(flag, nbr);
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
int	handle_p(unsigned long nbr, t_flag *flag)
{
	int		total_len;

	total_len = 0;
	flag_init_p(flag, nbr);
	total_len += ft_printxchars(' ', flag->leading_spaces_len);
	total_len += ft_printstr(flag->prefix);
	total_len += ft_printxchars('0', flag->zeros_len);
	if (!nbr)
		total_len += ft_printstr("(nil)");
	else
		total_len += ft_printulong16(nbr, 0);
	total_len += ft_printxchars(' ', flag->ending_spaces_len);
	return (total_len);
}
// put_debug_flag(flag);	// ! DEBUG
