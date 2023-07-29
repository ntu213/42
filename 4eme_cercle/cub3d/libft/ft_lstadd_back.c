/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:16:55 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/13 12:07:30 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	new->next = NULL;
	if (!lst[0])
		lst[0] = new;
	else if (!lst[0]->next)
		lst[0]->next = new;
	else
	{
		last = ft_lstlast(lst[0]);
		last->next = new;
	}
}

/*
* Partie bonus
===== DESCRIPTION
Ajoute l’élément ’new’ à la fin de la liste.

===== Paramètres
lst: L’adresse du pointeur vers le premier élément de la liste.
new: L’adresse du pointeur vers l’élément à rajouter à la liste.

===== RETURN VALUE


==== Fonctions externes autorisées

*/
