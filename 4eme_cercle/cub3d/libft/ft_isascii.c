/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:03:50 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/13 12:28:41 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*

* Partie 1 - Fonctions de la libc
	int isascii(int c);

    checks whether c is a 7-bit unsigned char value 
	that fits into the ASCII character set.

===== RETURN VALUE
       The values returned are nonzero if the character c falls 
	   into the tested class, and zero if not.

*/
