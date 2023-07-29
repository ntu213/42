/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:16:47 by dfleury           #+#    #+#             */
/*   Updated: 2023/02/10 12:03:33 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

/*
* Partie bonus
===== DESCRIPTION


===== Paramètres
lst: Le début de la liste.

===== RETURN VALUE
Dernier élément de la liste

==== Fonctions externes autorisées
Renvoie le dernier élément de la liste.

*/
