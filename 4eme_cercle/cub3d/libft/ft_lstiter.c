/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:16:27 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/10 13:57:43 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
* Partie bonus
===== DESCRIPTION
Itère sur la liste ’lst’ et applique la fonction ’f’ au contenu chaque élément.

===== Paramètres
lst: L’adresse du pointeur vers un élément.
f: L’adresse de la fonction à appliquer.

===== RETURN VALUE
Aucune

==== Fonctions externes autorisées
Aucune

*/
