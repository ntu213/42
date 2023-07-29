/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:27:27 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/21 16:14:30 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ***version modifiée : use : ft_countchars_int

char	*ft_itoa(int n)
{
	char	*str;
	size_t	strlen;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	strlen = ft_countchars_int(n, 1);
	str = malloc(sizeof(char) * (strlen + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	str[strlen] = '\0';
	strlen--;
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[strlen] = (n % 10) + 48;
		strlen--;
		n = n / 10;
	}
	return (str);
}

/*
 * Partie 2 - Fonctions supplémentaires
==== Description
Alloue (avec malloc(3)) et retourne une chaîne
de caractères représentant l’entier ’n’ reçu en
argument. Les nombres négatifs doivent être gérés.
7


===== Paramètres
n: L’entier à convertir.


===== Valeur de retour
La chaîne de caractères représentant l’entier.
NULL si l’allocation échoue.


===== Fonctions externes autorisées
malloc


*/
