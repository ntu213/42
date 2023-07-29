/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_keyboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/24 13:55:08 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	handle_key_sub_3(int keycode, t_data *data)
{
	if (keycode == data->config.key_minimap_toggle)
		minimap_toggle(data);
	else if (keycode == data->config.key_minimap_grow)
		minimap_change_size(data, 1);
	else if (keycode == data->config.key_minimap_shrink)
		minimap_change_size(data, -1);
	else
		return (0);
	return (1);
}

int	handle_key_sub_2(int keycode, t_data *data)
{
	double	pitch_speed;
	double	pos_z_speed;

	pitch_speed = 10;
	pos_z_speed = 20;
	if (keycode == data->config.key_look_down)
		player_look_up_down(data, -pitch_speed);
	else if (keycode == data->config.key_look_up)
		player_look_up_down(data, pitch_speed);
	else if (keycode == data->config.key_moove_up)
		player_up_down(data, pos_z_speed);
	else if (keycode == data->config.key_moove_down)
		player_up_down(data, -pos_z_speed);
	else if (keycode == data->config.key_open_door)
		open_door(data);
	else if (keycode == data->config.key_shoot)
		shoot(data);
	else if (keycode == KEY_ESC)
		game_quit(data);
	else
		return (handle_key_sub_3(keycode, data));
	return (1);
}

int	handle_key_sub_1(int keycode, t_data *data)
{
	double	rotation_speed;

	rotation_speed = 0.1;
	if (keycode == data->config.key_move_front)
		player_move(data, data->player.dir_x * data->config.speed_walk,
			data->player.dir_y * data->config.speed_walk);
	else if (keycode == data->config.key_move_back)
		player_move(data, -data->player.dir_x * data->config.speed_walk,
			-data->player.dir_y * data->config.speed_walk);
	else if (keycode == data->config.key_move_run)
		player_move(data, data->player.dir_x * data->config.speed_walk * 2,
			data->player.dir_y * data->config.speed_walk * 2);
	else if (keycode == data->config.key_step_right)
		player_move(data, data->player.plan_x * data->config.speed_walk,
			data->player.plan_y * data->config.speed_walk);
	else if (keycode == data->config.key_step_left)
		player_move(data, -data->player.plan_x * data->config.speed_walk,
			-data->player.plan_y * data->config.speed_walk);
	else if (keycode == data->config.key_rotate_right)
		player_rotate_right(data, rotation_speed);
	else if (keycode == data->config.key_rotate_left)
		player_rotate_left(data, rotation_speed);
	else
		return (handle_key_sub_2(keycode, data));
	return (1);
}

int	handle_key(int keycode, t_data *data)
{
	if (!handle_key_sub_1(keycode, data))
		ft_printf("key: %d\n", keycode);
	return (0);
}
