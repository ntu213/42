/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:59:00 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/21 18:02:34 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// !! renvoi toujour 1, meme pour '\0'
int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/*

==== Description


===== Paramètres


===== Valeur de retour

===== Fonctionsexternes autorisées

*/
