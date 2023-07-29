/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_multifree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:14:03 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/04 12:26:05 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 *	Free plusieurs str
 *
 *	use :
 *			ft_strs_multifree(3, str1, str2, str3);
 *
 */
void	ft_strs_multifree(int count, ...)
{
	va_list	args;

	va_start(args, count);
	while (count--)
	{
		free(va_arg(args, char *));
	}
}
