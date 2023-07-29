/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:59:39 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/22 11:00:30 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printint_rec(int n, int count)
{
	if (n == -2147483648)
		return (ft_printstr("-2147483648"));
	if (n < 0)
	{
		ft_printchar('-');
		count++;
		n = -n;
	}
	if (n > 9)
	{
		count = ft_printint_rec(n / 10, count);
		n = n % 10;
	}
	ft_printchar(n + 48);
	count++;
	return (count);
}

int	ft_printint(int n)
{
	return (ft_printint_rec(n, 0));
}
