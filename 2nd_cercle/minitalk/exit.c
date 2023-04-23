/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:36:38 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/21 17:38:31 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isexit(char *str)
{
	if (str[0] == 'e' && str[1] == 'x' && str[2] == 'i' && str[3] == 't'
		&& str[4] == '\0')
		return (1);
	return (0);
}

void	ft_exit(t_strct *strct)
{
	free(strct);
	exit(0);
}
