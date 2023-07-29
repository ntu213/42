/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 14:43:45 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/16 16:05:40 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/*
* Partie 1 - Fonctions de la libc
	isalpha()

	int isalpha(int c);


    checks  for  an alphabetic character; in the standard "C" locale, 
	it is equivalent to (isupper(c) || islower(c)).
    In some locales, there may be additional characters for which isalpha() 
	is true—letters which are neither  uppercase nor lowercase.

===== Paramètres



===== Valeur de retour



===== Fonctionsexternes autorisées


===== RETURN VALUE
       The values returned are nonzero if the character c falls 
	   into the tested class, and zero if not.

*/