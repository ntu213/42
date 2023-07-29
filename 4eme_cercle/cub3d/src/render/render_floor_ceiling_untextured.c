/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_ceiling_untextured.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:00:15 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/22 13:02:59 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// ** draw  plafond et sol sans textures:
void	render_floor_ceiling_untextured(t_data *data)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < data->win_width)
	{
		y = 0;
		while (y < data->win_height)
		{
			if (y < data->win_height / 2 + data->player.pitch_z)
				color = data->map->color_ceil;
			else
				color = data->map->color_floor;
			mlxx_put_pixel(data, x, y, color);
			y++;
		}
		x++;
	}
}
