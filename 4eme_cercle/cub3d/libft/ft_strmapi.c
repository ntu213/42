/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:28:07 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/07 14:03:14 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// * Partie 2 - Fonctions supplémentaires
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*word;

	word = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i])
	{
		word[i] = f(i, s[i]);
		i++;
	}
	word[i] = '\0';
	return (word);
}

/*
==== Description
 Applique la fonction ’f’ à chaque caractère de la
chaîne de caractères passée en argument pour créer
une nouvelle chaîne de caractères (avec malloc(3))
résultant des applications successives de ’f’.


===== Paramètres
s: La chaîne de caractères sur laquelle itérer.
f: La fonction à appliquer à chaque caractère.


===== Valeur de retour
La chaîne de caractères résultant des applications
successives de ’f’.
Retourne NULL si l’allocation échoue.

===== Fonctionsexternes autorisées
malloc

*/
