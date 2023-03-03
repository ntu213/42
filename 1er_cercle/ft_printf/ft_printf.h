/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:05:38 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/03 18:14:13 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

/*
int	hash:		ajouter "0x" devant pour %X et %x
int	space:		met un espace avant
int	plus:		si int positif, afficher '+'
*/

typedef struct s_obj
{
	int	hash;
	int	space;
	int	plus;
}	t_obj;

char	*int_base(int n, char *base);
char	*ft_ptochar(void *p, char *base);
void	ft_reverse(char *str);

#endif