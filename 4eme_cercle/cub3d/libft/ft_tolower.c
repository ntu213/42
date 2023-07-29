/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:59:11 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/15 13:05:57 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
int	*ft_tolower(int *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
*/

/*
* Partie 1 - Fonctions de la libc
    int toupper(int c);
    int tolower(int c);

DESCRIPTION
       These functions convert lowercase letters to uppercase, and vice versa.

       If  c  is a lowercase letter, toupper() returns its uppercase 
	   equivalent, 	   if an uppercase representation exists in the current 
	   locale.  Otherwise, it returns c.  The toupper_l() function performs 
	   the same task, but uses the locale referred to  by  the  locale
       handle locale.

       If  c  is an uppercase letter, tolower() returns its lowercase 
	   equivalent, if a lowercase representation exists in the current 
	   locale.  Otherwise, it returns c.  The tolower_l() function performs 
	   the same task, but uses the locale referred to  by  the  locale
       handle locale.

       If c is neither an unsigned char value nor EOF, the behavior of these 
	   functions is undefined.

       The  behavior  of  toupper_l()  and  tolower_l()  is undefined if 
	   locale is the special locale object LC_GLOBAL_LOCALE (see duplo‐
       cale(3)) or is not a valid locale object handle.

RETURN VALUE
       The value returned is that of the converted letter, or c if 
	   the conversion was not possible.


*/
