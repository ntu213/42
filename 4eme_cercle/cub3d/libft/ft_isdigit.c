/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:43:45 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/21 14:43:16 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
* Partie 1 - Fonctions de la libc
checks for a digit (0 through 9).

===== RETURN VALUE
The values returned are nonzero if the character c falls into the tested class,
 and zero if not.
*/
