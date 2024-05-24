/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:25:43 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/19 11:25:43 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lsti;
	t_list	*next;

	if (!lst || !del)
		return ;
	lsti = *lst;
	while (lsti)
	{
		next = (*lsti).next;
		del((*lsti).content);
		free(lsti);
		lsti = next;
	}
	*lst = NULL;
}
