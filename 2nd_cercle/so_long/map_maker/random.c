/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:02:55 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/04 09:10:47 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapmaker.h"
#include <limits.h>

int	ft_random(int n, unsigned long int next)
{
	int	res;

	if (!next)
		next = 1103515245;
	next = next * 1103515245 + (n + (next / 5) / (50 * 50 - (SEED * SEED) - 7))
		* (SEED % 957473) + 1;
	if (next <= 0)
		next = (SEED % 957473) + 1;
	res = (next / 65536) % n;
	return (res);
}

/*
void	main()
{
	int	x = 1;
	int	y = 1;
	int	res = 1;
unsigned long int next = 1;
	while(x < 50)
	{
		y = 1;
		while (y++ < 50)
		{
next = next * 1103515245 + (x + y / (50 * 50 - (SEED * SEED) - 7)) * SEED / 3;
//			res = ft_random(5, x, y, res);
			printf("%ld\n", (next/65536) % 32768 % 64);
		}
		x++;
	}
}*/