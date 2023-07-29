/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:03:51 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/13 12:28:23 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

/*
* Partie 1 - Fonctions de la libc
==== Description
La fonction memchr() examine les n premiers octets de la zone mémoire 
pointée par s à la recherche du caractère c. 

Le premier octet correspondant à c (interprété comme un unsigned char) 
arrête l'opération.

// La fonction memrchr() travaille comme memchr(), sauf qu'elle recherche 
// en arrière depuis la fin de la zone de n octets pointée par s 
// plutôt que depuis le début.  

===== Paramètres


===== Valeur de retour

Les fonctions memchr() et memrchr() renvoient un pointeur sur l'octet 
correspondant, ou NULL si le caractère n'est pas présent 
dans la zone de mémoire concernée.  

===== Fonctionsexternes autorisées


*/
