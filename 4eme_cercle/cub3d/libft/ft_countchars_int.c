/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchars_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:05:20 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/21 16:14:43 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countchars_int(int n, int count_sign)
{
	return (ft_countchars_int_base(n, 10, count_sign));
}

/*
 * autre version qui n'utilise pas 'ft_countchars_int_base'
int	ft_countchars_int(int n, int count_sign)
{
	int	result;

	result = 0;
	if (n == 0)
		return (1);
	if (n < 0 && count_sign)
		result++;
	while (n)
	{
		n = n / 10;
		result++;
	}
	return (result);
}
*/
/*
compte le nombre de characteres dans un int avec ou sans le signe
*/