/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:58:48 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/13 10:05:05 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big && !len)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && i + j < len)
		{
			if (little[j + 1] == '\0')
			{
				return ((char *) big + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
* Partie 1 - Fonctions de la libc
=== NAME
strnstr - Find the first substring in a length-limited string

The strnstr() function locates the first occurrence of the null-terminated
 string little in the string big, where not more than len characters are
 searched.
Characters that appear after a `\0' character are not searched.
Since the strnstr() function is a FreeBSD specific API, it should only be used
 when portability is not a concern.

=== SYNOPSIS
char * strnstr(const char *  big , const char *  s2 , size_t  len );

=== ARGUMENTS
big		: The string to be searched
little	: The string to search for
len  	: the maximum number of characters to search

=== RETURN VALUES
If little is an empty string, big is returned;
if little occurs nowhere  in big, NULL is returned;
otherwise a pointer to the first character of the first occurrence of little 
 is returned.

*/
