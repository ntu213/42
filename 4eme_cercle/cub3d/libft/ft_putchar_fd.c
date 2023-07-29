/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:59:00 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/06 15:07:10 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// * Partie 2 - Fonctions supplémentaires
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
==== Description


===== Paramètres


===== Valeur de retour

===== Fonctionsexternes autorisées

*/
