/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:16:23 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/13 10:40:37 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newelem;

	if (!lst || !f)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		newelem = ft_lstnew(f(lst->content));
		if (!newelem)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newelem);
		lst = lst->next;
	}
	return (newlst);
}

/*
* Partie bonus
===== DESCRIPTION
Itère sur la liste ’lst’ et
applique la fonction ’f ’au contenu de chaque élément.

Crée une nouvelle liste résultant des applications successives de ’f’.
La fonction ’del’ est là pour détruire le contenu d’un élément si nécessaire.

===== Paramètres
lst: L’adresse du pointeur vers un élément.
f: L’adresse de la fonction à appliquer.
del: L’adresse de la fonction permettant de supprimer le contenu d’un élément.

===== RETURN VALUE
La nouvelle liste.
NULL si l’allocation échoue

==== Fonctions externes autorisées
malloc, free

==== Notes persos:

on copie la liste

on apllique f a la nouvelle liste (l'original n'est pas modifiee)

del : si le malloc echoue.


*/
