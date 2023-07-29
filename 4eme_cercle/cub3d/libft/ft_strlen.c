/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:37:19 by dfleury           #+#    #+#             */
/*   Updated: 2023/05/18 10:49:49 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//* Modif : protection

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

/*

* Partie 1 - Fonctions de la libc
NAMEsize_t
       strlen - calculate the length of a string

       size_t strlen(const char *s);

DESCRIPTION
       The strlen() function calculates the length of the string 
	   pointed to by s, excluding the terminating null byte ('\0').

RETURN VALUE
       The strlen() function returns the number of bytes in the string 
	   pointed to by s.



*/
