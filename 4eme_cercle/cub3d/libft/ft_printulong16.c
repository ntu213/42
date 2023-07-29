/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printulong16.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:59:39 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/22 11:00:54 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printulong16_rec(unsigned long n, int upcase, int count)
{
	char	char_a;

	if (upcase)
		char_a = 'A';
	else
		char_a = 'a';
	if (n >= 16)
	{
		count = ft_printulong16_rec(n / 16, upcase, count);
		n = n % 16;
	}
	if (n < 10)
		ft_printchar(n + 48);
	else
		ft_printchar(n + char_a -10);
	count++;
	return (count);
}

int	ft_printulong16(unsigned long n, int upcase)
{
	return (ft_printulong16_rec(n, upcase, 0));
}
