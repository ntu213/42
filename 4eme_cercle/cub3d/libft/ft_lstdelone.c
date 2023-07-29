/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:16:51 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/16 15:57:47 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

/*
* **************** FAUX - POSITIF ?????????

* Partie bonus
===== DESCRIPTION
Libère la mémoire de l’élément passé en argument en utilisant la
 fonction ’del’ puis avec free(3).
La mémoire de ’next’ ne doit pas être free.

===== Paramètres
lst: L’élément à free
del: L’adresse de la fonction permettant de supprimer le contenu de l’élément.

===== RETURN VALUE
Aucune

==== Fonctions externes autorisées
free

*/
