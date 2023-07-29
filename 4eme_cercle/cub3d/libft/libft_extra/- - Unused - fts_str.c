/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   - - Unused - fts_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:14:03 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/04 12:26:05 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
int	first_word_is(char *str, char *start)
{
	return (ft_str_startswith(str, start)
		&& (!str[ft_strlen(start)] || str[ft_strlen(start)] == ' '));
}
*/

/*
size_t	first_word_len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != ' ')	// todo : white spaces
		i++;
	return (i);
}
*/

/*
int	get_index_next_sep_for_word(const char *str, int start_index)
{
	int	i;

	while (str[start_index] && !ft_is_white_space(str[start_index]))
		start_index++;
	if (str[start_index] && ft_is_white_space(str[start_index]))
		return (start_index);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/
