/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:33:48 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/13 12:26:22 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_reverse(void *dest, const void *src, size_t n)
{
	char	*str_dest;
	char	*str_src;

	str_dest = (char *)dest;
	str_src = (char *)src;
	while (n > 0)
	{
		str_dest[n - 1] = str_src[n - 1];
		n--;
	}
	return (str_dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if ((char *)dest < (char *)src)
		ft_memcpy(dest, src, n);
	else
		ft_memcpy_reverse(dest, src, n);
	return (dest);
}

/*
* Partie 1 - Fonctions de la libc
==== Description
La fonction memmove() copie n octets depuis la zone mémoire src 
vers la zone mémoire dest. 

Les deux zones peuvent se chevaucher : 
la copie se passe comme si les octets de src étaient d'abord copiés dans
une zone temporaire qui ne chevauche ni src ni dest, 
et les octets sont ensuite copiés de la zone temporaire vers dest.  


===== Paramètres


===== Valeur de retour
La fonction memmove() renvoie un pointeur sur dest.  

===== Fonctionsexternes autorisées


*/
