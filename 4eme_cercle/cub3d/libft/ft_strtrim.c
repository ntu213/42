/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:26:39 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/24 11:39:15 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_is_trimmable(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	nbr_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && char_is_trimmable(s1[i], set))
	{
		i++;
	}
	return (i);
}

// * pour cub3d, jai ajoute i >=0
static int	nbr_end(char const *s1, char const *set)
{
	int	i;
	int	nb;

	i = ft_strlen(s1) - 1;
	nb = 0;
	while (i >= 0 && s1[i] && char_is_trimmable(s1[i], set))
	{
		i--;
		nb++;
	}
	return (nb);
}

// * Partie 2 - Fonctions supplémentaires
char	*ft_strtrim(char const *s1, char const *set)
{
	int		nb_trim_start;
	int		nb_trim_end;
	int		len;

	if (!s1)
		return (NULL);
	nb_trim_start = nbr_start(s1, set);
	nb_trim_end = nbr_end(s1, set);
	len = ft_strlen(s1) - nb_trim_end - nb_trim_start;
	return (ft_substr(s1, nb_trim_start, len));
}

/*
===== Paramètres

Alloue (avec malloc(3)) et retourne une copie de
la chaîne ’s1’, sans les caractères spécifiés
dans ’set’ au début et à la fin de la chaîne de
caractères.

===== Paramètres
s1: La chaîne de caractères à trimmer.
set: Le set de référence de caractères à trimmer.

===== Valeur de retour

La chaîne de caractères trimmée.
NULL si l’allocation échoue.

===== Fonctionsexternes autorisées

malloc


*/
