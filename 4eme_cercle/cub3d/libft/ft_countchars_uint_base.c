/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchars_uint_base.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:05:20 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/21 16:12:19 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countchars_uint_base(unsigned int n, int base)
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
compte le nombre de characteres dans un uint en base 'int base'
*/