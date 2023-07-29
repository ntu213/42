/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:09:13 by dfleury           #+#    #+#             */
/*   Updated: 2023/03/10 15:13:10 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"

/*
 * 	plus, space, left, zero, dot, sharp ==> BOOLEAN
 *	left		//	flag '-'
 *	typ			//	'c|d|i....'
 *	len;		//	nbre de char dans le flag : "%+3i" => 4
 *	prefix;		//	"+|-| |0x|0X"
 *	digit_len;	//	sans le signe !!!!!
 *
 */
typedef struct s_flag
{
	int		plus;
	int		space;
	int		left;
	int		zero;
	int		dot;
	int		sharp;
	int		precision;
	int		width;
	char	typ;
	int		len;
	int		leading_spaces_len;
	char	*prefix;
	int		zeros_len;
	int		digit_len;
	int		ending_spaces_len;
}		t_flag;

int		ft_printf(const char *str, ...);

int		handle_c(char c, t_flag *flag);
int		handle_s(char *str, t_flag *flag);
int		handle_id(int nbr, t_flag *flag);
int		handle_p(unsigned long nbr, t_flag *flag);
int		handle_u(unsigned int nbr, t_flag *flag);
int		handle_x(unsigned int nbr, t_flag *flag, int upcase);

#endif
