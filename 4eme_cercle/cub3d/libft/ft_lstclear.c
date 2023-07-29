/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:16:29 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/10 14:16:23 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;

	if (lst)
	{
		while (*lst)
		{
			elem = (*lst)->next;
			ft_lstdelone(*lst, del);
			(*lst) = elem;
		}
	}
}

/*
* Partie bonus
===== DESCRIPTION
Supprime et libère la mémoire de l’élément passé en paramètre,
 et de tous les éléments qui suivent, à l’aide de ’del’ et de free(3)

Enfin, le pointeur initial doit être mis à NULL.

===== Paramètres
lst: L’adresse du pointeur vers un élément.
del: L’adresse de la fonction permettant de supprimer le contenu d’un élément.

===== RETURN VALUE
Aucune

==== Fonctions externes autorisées
free

*/
