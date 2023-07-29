/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:20:29 by dfleury           #+#    #+#             */
/*   Updated: 2023/03/10 14:54:53 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_c(char c, t_flag *flag)
{
	int	total_len;
	int	trailing_len;

	total_len = 0;
	trailing_len = flag->width - 1;
	if (!flag->left)
		total_len += ft_printxchars(' ', trailing_len);
	total_len += ft_printchar(c);
	if (flag->left)
		total_len += ft_printxchars(' ', trailing_len);
	return (total_len);
}
