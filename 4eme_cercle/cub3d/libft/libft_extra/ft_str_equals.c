/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_equals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:14:03 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/04 12:26:05 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 *	@desc
 *		compare si 2 chaines de characteres sont STRICTEMENT identiques
 *		(avec le meme nombre de charactere0
 *	@return {0|1}
 */
int	ft_str_equals(char *s1, char *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s1)+1) == 0);
}
