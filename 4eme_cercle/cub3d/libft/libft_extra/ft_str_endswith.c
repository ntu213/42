/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_endswith.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:55:55 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/04 12:28:17 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_str_endswith(char *str, char *end)
{
	int	i;
	int	str_len;
	int	end_len;

	str_len = ft_strlen(str);
	end_len = ft_strlen(end);
	if (end_len > str_len)
		return (0);
	i = 0;
	while (end_len - i >= 0)
	{
		if (end[end_len - i] != str[str_len - i])
			return (0);
		i++;
	}
	return (1);
}
