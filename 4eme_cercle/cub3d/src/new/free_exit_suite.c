/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit_suite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 11:38:36 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	destroy_imgs(t_data *data);
void	free_and_destroy_enemies(t_data *data);

int	free_and_exit_if_texture_not_found(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	destroy_imgs(data);
	free_and_destroy_enemies(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	return (free_data_and_exit(data));
}
