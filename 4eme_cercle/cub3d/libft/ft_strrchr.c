/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:19:16 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/13 12:27:23 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&(s[i]));
		i--;
	}
	return (NULL);
}

/*
* Partie 1 - Fonctions de la libc
== DESCRIPTION
// La fonction strchr() renvoie un pointeur sur la première 
// occurrence du caractère c dans la chaîne s.


La fonction strrchr() renvoie un pointeur sur la dernière 
occurrence du caractère c dans la chaîne s.

// La fonction strchrnul() est comme strchr() excepté que 
// si c n'est pas trouvé dans s, elle renvoie un pointeur
// sur l'octet nul à la fin de s, plutôt que NULL.

Pour ces fonctions, « caractère » signifie « octet » ;
 elles ne marchent pas avec des caractères larges ou multi-octets.  

== VALEUR RENVOYÉE
Les fonctions strchr() et strrchr() renvoient un pointeur sur le caractère
 correspondant, ou NULL si le caractère n'a pas été trouvé.

// La fonction strchrnul() renvoie un pointeur sur le caractère mis en 
// correspondance, ou bien un pointeur sur l'octet nul de fin de s 
// (c'est-à-dire, s+strlen(s)) si le caractère n'est pas trouvé. 

*/
