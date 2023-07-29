/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:28:27 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/13 12:12:30 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&(s[i]));
		i++;
	}
	if (s[i] == c)
		return ((char *)&(s[i]));
	return (NULL);
}

/*
* Partie 1 - Fonctions de la libc
===== NAME
strchr, strrchr, strchrnul - locate character in string

===== DESCRIPTION
The strchr() function returns a pointer to the first occurrence of the
 character c in the string s.

Here "character" means "byte"; these functions do not work with wide or
 multibyte characters.

===== RETURN VALUE
The strchr() and strrchr() functions return a pointer to the matched
 character or NULL if the character is not found.
The  terminating null byte is considered part of the string, so that
 if c is specified as '\0', these functions return a pointer to the terminator.

The strchrnul() function returns a pointer to the matched character,
 or a pointer to the null byte at the end of s(i.e., s+strlen(s))
 if the character is not found.
*/
