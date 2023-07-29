/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:30:01 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/06 12:46:48 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// * Partie 2 - Fonctions supplémentaires
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
==== Description

Applique la fonction ’f’ à chaque caractère de la
chaîne de caractères transmise comme argument,
et en passant son index comme premier argument.


Chaque caractère est transmis par adresse à ’f’
afin d’être modifié si nécessaire.


===== Paramètres

s: La chaîne de caractères sur laquelle itérer.
f: La fonction à appliquer à chaque caractère.

===== Valeur de retour

Aucune

===== Fonctionsexternes autorisées

Aucune


*/
