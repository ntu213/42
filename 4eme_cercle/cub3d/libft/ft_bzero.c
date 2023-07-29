/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:53:50 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/13 12:31:13 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s,	size_t n)
{
	size_t	i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

/*
* Partie 1 - Fonctions de la libc
void ft_bzero(void *s, size_t n);

== DESCRIPTION
La fonction bzero() met à 0 (octets contenant « \0 »)
les n premiers octets du bloc pointé par s.


== DESCRIPTION
       The bzero() function erases the data in the n bytes of the memory
       starting at the location pointed to by s, by writing zeros (bytes
       containing '\0') to that area.


== RETURN VALUE
       None.

*/
