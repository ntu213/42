/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:26:12 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/19 11:26:12 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*stct;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		stct = ft_lstlast(*(lst));
		(*stct).next = new;
	}
}
