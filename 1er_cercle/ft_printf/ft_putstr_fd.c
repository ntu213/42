/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:02:28 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/18 12:02:28 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, t_obj *item)
{
	int	i;

	i = 0;
	if (!s || !fd)
	{
		write(1, "(null)", 6);
		item->total += 6;
		return ;
	}
	while (s[i])
		write(fd, &s[i++], 1);
}
