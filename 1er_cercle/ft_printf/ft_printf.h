/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:05:38 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/04 18:17:27 by vgiraudo         ###   ########.fr       */
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
int	total:		le nombre total de caracteres ecrits
*/

typedef struct s_obj
{
	int	hash;
	int	space;
	int	plus;
	int	total;
}	t_obj;

char	*int_base(int n, char *base, t_obj *item);
void	ft_ptochar(void *p, char *base, t_obj *item);
void	ft_reverse(char *str);

#endif