/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:23:44 by dfleury           #+#    #+#             */
/*   Updated: 2023/05/24 15:40:59 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// * Partie 2 - Fonctions supplémentaires
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	int		i1;
	int		i2;
	char	*word;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	word = malloc(sizeof(char) * (total_len + 1));
	if (!word)
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (s1[i1])
	{
		word[i1] = s1[i1];
		i1++;
	}
	i2 = 0;
	while (s2[i2])
	{
		word[i1] = s2[i2];
		i1++;
		i2++;
	}
	word[i1] = '\0';
	return (word);
}

/*
===== Paramètres

s1: La chaîne de caractères préfixe.
s2: La chaîne de caractères suffixe.

===== Valeur de retour

La nouvelle chaîne de caractères.
NULL si l’allocation échoue.

===== Fonctions externes autorisées

malloc

===== Description
Alloue (avec malloc(3)) et retourne une nouvelle
chaîne, résultat de la concaténation de s1 et s2.


*/
