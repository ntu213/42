/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:06:22 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/13 12:25:27 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
* Partie 1 - Fonctions de la libc
	int isalnum(int c);

    checks for an alphanumeric character; 
	it is equivalent to (isalpha(c) || isdigit(c)).


===== RETURN VALUE
       The values returned are nonzero if the character c falls 
	   into the tested class, and zero if not.

*/
