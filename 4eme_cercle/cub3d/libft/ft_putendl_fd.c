/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:35:50 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/06 15:07:05 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// * Partie 2 - Fonctions supplémentaires
void	ft_putendl_fd(char *s, int fd)
{	
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/*
==== Description

===== Paramètres

===== Valeur de retour

===== Fonctionsexternes autorisées

*/
