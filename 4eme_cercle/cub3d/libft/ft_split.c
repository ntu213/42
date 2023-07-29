/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:38:33 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/08 14:22:56 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// renvoi le nombre de mots dans str
static int	count_words(const char *str, char c)
{
	int	count_words;
	int	i;

	count_words = 0;
	i = 0;
	while (str[i])
	{
		if ((c != str[i]) && (i == 0 || c == str[i - 1]))
			count_words++;
		i++;
	}
	return (count_words);
}

static int	get_index_next_sep(const char *str, char c, int start_index)
{
	int	i;

	while (str[start_index] && c != str[start_index])
		start_index++;
	if (str[start_index] && c == str[start_index])
		return (start_index);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

// * Partie 2 - Fonctions supplémentaires
char	**ft_split(const char *str, char c)
{
	int		i;
	char	**words;
	int		words_index;
	int		current_word_len;

	words = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!words)
		return (NULL);
	words_index = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] != c) && (i == 0 || str[i - 1] == c))
		{
			current_word_len = get_index_next_sep(str, c, i + 1) - i;
			words[words_index] = ft_substr(str, i, current_word_len);
			i += current_word_len -1;
			words_index++;
		}
		i++;
	}
	words[words_index] = NULL;
	return (words);
}

/*
==== Description
Alloue (avec malloc(3)) et retourne un tableau
de chaînes de caractères obtenu en séparant ’s’ à
l’aide du caractère ’c’, utilisé comme délimiteur.
Le tableau doit être terminé par NULL.

===== Paramètres
s: La chaîne de caractères à découper.
c: Le caractère délimiteur.

===== Valeur de retour
Le tableau de nouvelles chaînes de caractères
résultant du découpage.
NULL si l’allocation échoue.
===== Fonctionsexternes autorisées
malloc, free


*/
