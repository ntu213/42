/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   - - - ft_str_modify_and_free.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:14:03 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/04 12:25:39 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// * free str et lui attribue une nouvelle valeur
char	*ft_str_modify_and_free(char *str, char *newstr)
{
	char	*tmp;

	tmp = ft_strdup(newstr);
	free(str);
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}
