/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint16.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:59:39 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/22 11:04:27 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printuint16_rec(unsigned int n, int upcase, int count)
{
	char	char_a;

	if (upcase)
		char_a = 'A';
	else
		char_a = 'a';
	if (n >= 16)
	{
		count = ft_printuint16_rec(n / 16, upcase, count);
		n = n % 16;
	}
	if (n < 10)
		ft_printchar(n + 48);
	else
		ft_printchar(n + char_a -10);
	count++;
	return (count);
}

int	ft_printuint16(unsigned int n, int upcase)
{
	return (ft_printuint16_rec(n, upcase, 0));
}
