/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:17:01 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/10 12:03:05 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*
* Partie bonus
===== DESCRIPTION


===== Paramètres
lst: Le début de la liste.

===== RETURN VALUE
Taille de la liste

==== Fonctions externes autorisées
Compte le nombre d’éléments de la liste.

*/
