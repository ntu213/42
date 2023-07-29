/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:24:17 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/13 12:28:11 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str_dest;
	char	*str_src;

	if (!dest && !src)
		return (NULL);
	str_dest = (char *)dest;
	str_src = (char *)src;
	i = 0;
	while (i < n)
	{
		str_dest[i] = str_src[i];
		i++;
	}
	return (str_dest);
}

/*
* Partie 1 - Fonctions de la libc
==== Description
La fonction memcpy() copie n octets depuis la zone mémoire src
 vers la zone mémoire dest.

Les deux zones ne doivent pas se chevaucher.
Si c'est le cas, utilisez plutôt memmove(3).

===== Paramètres

===== Valeur de retour
La fonction memcpy() renvoie un pointeur sur dest.

===== Fonctionsexternes autorisées

*/
