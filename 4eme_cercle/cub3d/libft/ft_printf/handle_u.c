/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:20:29 by dfleury           #+#    #+#             */
/*   Updated: 2023/03/10 14:54:48 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// !! unisgned ????????????
static void	flag_init_u(t_flag *flag, int nbr)
{
	int		current_len;

	flag->leading_spaces_len = 0;
	flag->zeros_len = 0;
	flag->digit_len = ft_countchars_uint_base(nbr, 10);
	flag->ending_spaces_len = 0;
	if (flag->precision > flag->digit_len)
		flag->zeros_len += flag->precision - flag->digit_len;
	current_len = flag->digit_len + flag->zeros_len ;
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

int	handle_u(unsigned int nbr, t_flag *flag)
{
	int		total_len;

	total_len = 0;
	flag_init_u(flag, nbr);
	total_len += ft_printxchars(' ', flag->leading_spaces_len);
	total_len += ft_printxchars('0', flag->zeros_len);
	total_len += ft_printuint(nbr);
	total_len += ft_printxchars(' ', flag->ending_spaces_len);
	return (total_len);
}
// total_len += put_debug_flag(flag);	// ! DEBUG
