/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:14:03 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/04 12:26:05 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_str_replace(char *origin, char *srch, char *replace)
{
	int		i;
	int		start;
	char	*prefix;
	char	*suffix;
	char	*return_str;

	i = 0;
	start = 0;
	while (origin[i])
	{
		if (!ft_strncmp(origin + i, srch, ft_strlen(srch)))
		{
			prefix = ft_substr(origin, start, i - start);
			suffix = ft_substr(origin, i + ft_strlen(srch), ft_strlen(origin));
			return_str = ft_strs_concat(3, prefix, (replace), suffix);
			free(prefix);
			free(suffix);
			start = i;
			return (return_str);
		}
		i++;
	}
	return (ft_strdup(origin));
}
