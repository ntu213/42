/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:46:39 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/02/06 18:46:39 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr(const char *src, const char *obj, size_t n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (obj == 0 || src == 0)
		return (0);
	while (n > 0 && src[i] && obj[i])
	{
		while (n > 0 && src[i + j] && obj[i + j] == *src)
		{
			if (obj[i + j + 1] == '\0')
				return (i);
			j++;
			n--;
		}
		i += j;
		i++;
		n--;
		j = 0;
	}
	return (0);
}
