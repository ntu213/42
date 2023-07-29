/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:24:30 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/13 12:17:05 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	if (!size && !dst)
		return (0);
	dst_len = ft_strlen(dst);
	if (!size)
		return (ft_strlen(src));
	if (size < dst_len)
		return (size + ft_strlen(src));
	i = 0;
	while (dst[i] && i < size)
		i++;
	j = 0;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < size)
		dst[i] = '\0';
	return (ft_strlen(src) + dst_len);
}

/*
 * Partie 1 - Fonctions de la libc

==== DESCRIPTION
The strlcpy() and strlcat() functions copy and concatenate strings respectively.
strlcpy() and strlcat() take the full size of the buffer (not just the length)
and guarantee to NUL-terminate the result 
 (as long as size is larger than 0 or, in the case of strlcat(), 
 as long as there is at least one byte free in dst).  
 
 Note that a byte for the NUL should be included in size.  
 Also note that strlcpy() and strlcat() only operate on true “C” strings.  
 This means that for strlcat() both src and dst must be NUL-terminated
   // and  for strlcpy() src must be NUL-terminated.

// The strlcpy() function copies up to size - 1 characters from 
// the NUL-terminated string src to dst, NUL-terminating the result.

The strlcat() function appends the NUL-terminated string src to the end of dst.
It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.


==== RETURN VALUES
The strlcpy() and strlcat() functions return the total length of the string
they tried to create.  
// For strlcpy() that means the length of src.  
For strlcat() that means the initial length of dst plus the length of src.  
While this may seem somewhat confusing, it was done to make truncation 
detection simple.

if strlcat() traverses size characters without finding a NUL, 
the length of the string is considered to be size
     and the destination string will not be NUL-terminated (since there was no 
	 space for the NUL).  

This keeps strlcat() from running off the end of a string.  
In practice this should not happen 
(as it means that either size is incorrect or 
that dst is not a proper “C” string).
The check exists to prevent potential security problems in incorrect code.



*/
