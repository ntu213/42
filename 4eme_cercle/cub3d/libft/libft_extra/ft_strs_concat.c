/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_concat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:14:03 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/04 12:26:05 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strs_concat(int strs_count, ...)
{
	va_list	args;
	size_t	total_len;
	char	*result_str;
	char	*current_str;
	int		i;

	va_start(args, strs_count);
	total_len = 0;
	i = 0;
	while (i++ < strs_count)
		total_len += ft_strlen(va_arg(args, char *));
	va_end(args);
	result_str = ft_calloc(sizeof(char), total_len + 1);
	if (!result_str)
		return (NULL);
	va_start(args, strs_count);
	i = 0;
	while (strs_count--)
	{
		current_str = va_arg(args, char *);
		ft_memcpy(&result_str[i], current_str, ft_strlen(current_str));
		i += ft_strlen(current_str);
	}
	va_end(args);
	return (result_str);
}
