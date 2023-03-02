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
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	temp = ft_lstnew(NULL);
	if (!temp)
		return (NULL);
	res = temp;
	while (lst)
	{
		res->content = f(lst->content);
		if (lst->next)
		{
			res->next = ft_lstnew(NULL);
			if (!res)
			{
				ft_lstclear(&temp, del);
				return (NULL);
			}
			res = res->next;
		}
		lst = lst->next;
	}
	return (temp);
}
