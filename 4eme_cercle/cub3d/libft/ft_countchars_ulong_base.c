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

int	ft_countchars_ulong_base(unsigned long n, int base)
{
	int	result;

	result = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		result++;
	}
	return (result);
}

/*
compte le nombre de characteres dans un ulong de base 'int base'
*/