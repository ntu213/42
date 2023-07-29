/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_current_dir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:20:17 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/04 12:26:05 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

DIR	*ft_get_current_dir(void)
{
	char	current_dir[MAX_PATH_LEN];
	DIR		*dir;

	getcwd(current_dir, MAX_PATH_LEN);
	dir = opendir(current_dir);
	if (!dir)
		return (NULL);
	return (dir);
}
