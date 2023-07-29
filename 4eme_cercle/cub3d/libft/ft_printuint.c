/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:59:39 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/22 11:00:44 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printuint_rec(unsigned int n, int count)
{
	if (n > 9)
	{
		count = ft_printuint_rec(n / 10, count);
		n = n % 10;
	}
	ft_printchar(n + 48);
	count++;
	return (count);
}

int	ft_printuint(unsigned int n)
{
	return (ft_printuint_rec(n, 0));
}
