/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:03:38 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/13 12:28:29 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*
* Partie 1 - Fonctions de la libc
	int isprint(int c);
    checks for any printable character including space.

===== RETURN VALUE
       The values returned are nonzero if the character c falls 
	   into the tested class, and zero if not.

*/
