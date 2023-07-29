/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/24 13:59:09 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// * Message can be NULL !
int	print_error_message(char *msg)
{
	ft_putstr_fd(C_RED"❌ Error\n", 2);
	if (msg)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n"C_NOR, 2);
	}
	return (1);
}

int	print_error_message_x2(char *msg, char *msg2)
{
	ft_putstr_fd(C_RED"❌ Error\n", 2);
	if (msg)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd(msg2, 2);
		ft_putstr_fd("\n"C_NOR, 2);
	}
	return (1);
}
