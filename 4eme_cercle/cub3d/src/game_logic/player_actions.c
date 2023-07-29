/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/22 16:59:00 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	open_door(t_data *data)
{
	if (data->selected_door_x > 0 && data->selected_door_y > 0)
		data->map->map_cells[data->selected_door_x]
		[data->selected_door_y] = '0';
}

void	shoot(t_data *data)
{
	int	i;

	i = 0;
	data->shooting = SHOOTING_HEIGHT;
	while (data->spritex[i])
	{
		if (data->spritex[i]->is_alive && data->spritex[i]->is_in_viseur)
		{
			data->spritex[i]->text_num = 3;
			data->spritex[i]->killed_timestamp = get_timestamp_ms();
			data->enemies_count--;
		}
		i++;
	}
}
