/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:24:40 by dfleury           #+#    #+#             */
/*   Updated: 2023/05/27 12:06:10 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*word;
	size_t	i;

	if (start >= ft_strlen(s) || len < 1)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		word[i] = s[i + start];
		i++;
	}
	word[i] = '\0';
	return (word);
}

/*
* Partie 2 - Fonctions supplémentaires
==== Paramètres
s: La chaîne de laquelle extraire la nouvelle chaîne.
start: L’index de début de la nouvelle chaîne dans la chaîne ’s’.
len: La taille maximale de la nouvelle chaîne.

==== Valeur de retour
Alloue (avec malloc(3)) et retourne une chaîne de caractères issue de la
 chaîne ’s’.
Cette nouvelle chaîne commence à l’index start et a pour taille maximale len.

==== Fonctions externes autorisées
malloc

*/
