/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printxchars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:07:35 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/21 18:02:34 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printxchars(char c, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}
