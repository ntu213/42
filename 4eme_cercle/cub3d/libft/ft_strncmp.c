/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:59:44 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/12 17:56:01 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
* Partie 1 - Fonctions de la libc
==== Description
The  strcmp() function compares the two strings s1 and s2.
The locale is not taken into account.

It returns an integer less than, equal  to,  or  greater than zero 
if s1 is found, respectively, to be less than, to match, or be greater than s2.

The strncmp() function is similar, except it compares only the first 
(at most) n bytes of s1 and s2.

===== Paramètres

===== Valeur de retour
The  strcmp()  and strncmp() functions return an integer 
less than, equal to, or greater than zero if
s1 (or the first n bytes thereof) is found, 
respectively, to be less than, to match,  or  be  greater than s2.

===== Fonctionsexternes autorisées

*/
