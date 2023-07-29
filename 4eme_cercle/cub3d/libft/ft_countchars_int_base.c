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

int	ft_countchars_int_base(int n, int base, int count_sign)
{
	int	result;

	result = 0;
	if (n == 0)
		return (1);
	if (n < 0 && count_sign)
		result++;
	while (n)
	{
		n = n / base;
		result++;
	}
	return (result);
}

/*
compte le nombre de characteres dans un int de base 'base' avec ou sans le signe
*/