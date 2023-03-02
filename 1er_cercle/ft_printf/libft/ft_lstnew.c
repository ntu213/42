/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 11:25:17 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/19 11:25:17 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*stct;

	stct = (t_list *)malloc(sizeof(t_list));
	if (!stct)
		return (NULL);
	(*stct).content = content;
	return (stct);
}
