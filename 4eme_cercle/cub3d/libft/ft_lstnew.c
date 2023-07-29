/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:28:27 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/10 14:30:50 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tl;

	tl = malloc(sizeof(t_list));
	if (!tl)
		return (NULL);
	tl->content = content;
	tl->next = NULL;
	return (tl);
}

/*
* Partie bonus
===== DESCRIPTION
Alloue (avec malloc(3)) et renvoie un nouvel élément. 
La variable membre ’content’ est initialisée à l’aide de la valeur du paramètre
’content’.
La variable ’next’ est initialisée à NULL.


===== Paramètres
content: Le contenu du nouvel élément.

===== RETURN VALUE
Le nouvel élément


==== Fonctions externes autorisées
malloc


*/
