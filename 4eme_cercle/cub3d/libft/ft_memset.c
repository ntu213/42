/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:24:06 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/13 12:30:25 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

/*
* Partie 1 - Fonctions de la libc
==== Description
La fonction memset() remplit les n premiers octets de la zone mémoire 
pointée par s avec l'octet c.  

===== Paramètres


===== Valeur de retour
La fonction memset() renvoie un pointeur sur la zone mémoire s.


===== Fonctionsexternes autorisées

*/
