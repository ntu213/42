/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/24 17:09:39 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	set_player_orientation(t_data *data, char orientation)
{
	data->player.dir_x = 0;
	data->player.dir_y = 0;
	data->player.plan_x = 0;
	data->player.plan_y = 0;
	if (orientation == 'N')
	{
		data->player.dir_x = -1;
		data->player.plan_y = data->config.fov;
	}
	else if (orientation == 'S')
	{
		data->player.dir_x = 1;
		data->player.plan_y = -data->config.fov;
	}
	else if (orientation == 'E')
	{
		data->player.dir_y = 1;
		data->player.plan_x = data->config.fov;
	}
	else if (orientation == 'W')
	{
		data->player.dir_y = -1;
		data->player.plan_x = -data->config.fov;
	}
}

static void	set_player(t_data *data, int x, int y, char orientation)
{
	ft_printf("x=%d    y=%d  orientation=%c \n", x, y, orientation);
	data->player.pos_x = y + 0.54321;
	data->player.pos_y = x + 0.54321;
	data->map->map_cells[y][x] = '0' ;
	set_player_orientation(data, orientation);
}

void	player_init(t_data *data)
{
	int	y;
	int	x;

	data->player.pitch_z = 0;
	data->player.pos_z = 0;
	y = 0;
	while (data->map->map_cells[y])
	{
		x = 0;
		while (y < data->map->map_cells[y][x])
		{
			if (data->map->map_cells[y][x] == 'N'
				|| data->map->map_cells[y][x] == 'S'
				|| data->map->map_cells[y][x] == 'E'
				|| data->map->map_cells[y][x] == 'W')
			{
				set_player(data, x, y, data->map->map_cells[y][x]);
				break ;
			}
			x++;
		}
		y++;
	}
}
