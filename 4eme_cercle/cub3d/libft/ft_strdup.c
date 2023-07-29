/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:45:14 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/12 18:22:00 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
* Partie 1 - Fonctions de la libc
* vous pourrez faire appel à la fonction malloc()
==== Description
The strdup() function returns a pointer to a new string which is a duplicate of
 the string s.
Memory for the new string is obtained with malloc, and can be freed with free.

===== Paramètres

===== Valeur de retour
On success, the strdup() function returns a pointer to the duplicated string.
It returns NULL if insufficient memory was available, with errno set to
 indicate the cause of the error.

===== Fonctionsexternes autorisées


*/
