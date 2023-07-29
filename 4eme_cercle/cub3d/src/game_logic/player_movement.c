/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/22 14:46:22 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	player_move(t_data *data, double dirx, double diry)
{
	double	newx;
	double	newy;

	newx = data->player.pos_x + dirx;
	newy = data->player.pos_y + diry;
	if (data->map->map_cells[(int) newx][(int)data->player.pos_y] == '0')
		data->player.pos_x = newx;
	if (data->map->map_cells[(int) data->player.pos_x][(int) newy] == '0')
		data->player.pos_y = newy;
}

void	player_rotate_left(t_data *data, double rotation_speed)
{
	double	old_dirx;
	double	old_planx;

	old_dirx = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(rotation_speed)
		- data->player.dir_y * sin(rotation_speed);
	data->player.dir_y = old_dirx * sin(rotation_speed)
		+ data->player.dir_y * cos(rotation_speed);
	old_planx = data->player.plan_x;
	data->player.plan_x = data->player.plan_x * cos(rotation_speed)
		- data->player.plan_y * sin(rotation_speed);
	data->player.plan_y = old_planx * sin(rotation_speed)
		+ data->player.plan_y * cos(rotation_speed);
}

void	player_rotate_right(t_data *data, double rotation_speed)
{
	player_rotate_left(data, -rotation_speed);
}

void	player_up_down(t_data *data, double speed)
{
	data->player.pos_z += speed;
	if (data->player.pos_z > data->win_height / 2 - 50)
		data->player.pos_z = data->win_height / 2 - 50;
	if (data->player.pos_z < -data->win_height / 2 + 50)
		data->player.pos_z = -data->win_height / 2 + 50;
}

void	player_look_up_down(t_data *data, double speed)
{
	data->player.pitch_z += speed;
	if (data->player.pitch_z > data->win_height / 3 * 2)
		data->player.pitch_z = data->win_height / 3 * 2;
	if (data->player.pitch_z < -data->win_height / 3 * 2)
		data->player.pitch_z = -data->win_height / 3 * 2;
}
