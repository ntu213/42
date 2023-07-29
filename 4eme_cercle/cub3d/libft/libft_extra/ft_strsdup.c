/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:14:03 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/04 12:26:05 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// * duplique un char**  (tableau de char*)
// * CE N'EST PAS  ft_strdup !
char	**ft_strsdup(char **strs)
{
	int		i;
	char	**dup;

	if (!strs)
		return (NULL);
	i = 0;
	dup = malloc(sizeof(char *) * (ft_strs_size(strs) + 1));
	if (!dup)
		return (NULL);
	while (strs[i])
	{
		dup[i] = ft_strdup(strs[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
