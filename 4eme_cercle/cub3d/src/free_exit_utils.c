/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/24 16:08:43 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	free_exit_with_error(t_data *data, char *msg)
{
	print_error_message(msg);
	return (free_data_and_exit(data));
}

int	free_exit_with_error_x2(t_data *data, char *msg, char *msg2)
{
	print_error_message_x2(msg, msg2);
	return (free_data_and_exit(data));
}

void	free_strs_if_exist(char **strs)
{
	if (strs)
		ft_strs_free(strs);
}

void	free_str_if_exist(char *str)
{
	if (str)
		free(str);
}
