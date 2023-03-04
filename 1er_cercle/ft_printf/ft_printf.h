/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:05:38 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/04 18:48:04 by vgiraudo         ###   ########.fr       */
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
int		ft_count(const char *origin);
int		ft_comp(char orig, char *str);
int		ft_midverif(t_obj *item, char c);
void	ft_int_writer(int nbr, t_obj *item);
void	ft_unsint_writer(unsigned int nbr, t_obj *item);
int		ft_error(int i, t_obj *item);
int		ft_tester_2(va_list *arg, const char *origin, int i, t_obj *item);
int		ft_tester(va_list *arg, const char *origin, int i, t_obj *item);
void	ft_item_reset(t_obj *item);
int		ft_printf(const char *origin, ...);

#endif