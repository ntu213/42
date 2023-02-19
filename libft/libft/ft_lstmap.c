/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:25:24 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/19 11:25:24 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;

	res->content = malloc(sizeof(f(lst->content)));
	if (!res->content)
	res->content = f(lst->content);
	if (!(lst->next))
		res->next = NULL;
	else
		res->next = ft_lstmap(res, f, del);
	return (res);
}

//non terminee