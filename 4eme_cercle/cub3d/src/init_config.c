/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 12:40:58 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	load_config_small_def(t_data *data)
{
	data->config.screen_width = 980;
	data->config.screen_height = 500;
	data->config.fov = 0.66 ;
	data->config.gun_width = data->config.screen_width / 6;
}

void	load_config_full_screen(t_data *data)
{
	data->config.screen_width = 3820;
	data->config.screen_height = 2100;
	data->config.fov = 0.66 ;
	data->config.gun_width = data->config.screen_width / 6;
}

void	load_config_azerty(t_data *data)
{
	data->config.key_rotate_left = KEY_Q;
	data->config.key_look_up = KEY_Z;
}

// data->config.gun_height = data->config.screen_height / 6; // *ratio
void	load_config_default(t_data *data)
{
	data->config.screen_width = 2250;
	data->config.screen_height = 900;
	data->config.speed_walk = 0.08;
	data->config.speed_mouse_x = 0.002;
	data->config.speed_mouse_y = 0.8;
	data->config.fov = 0.99;
	data->config.minimap_size = 5;
	data->config.gun_width = data->config.screen_width / 6;
	data->config.gun_shoot_height = 40;
	data->config.key_move_front = KEY_W;
	data->config.key_move_back = KEY_S;
	data->config.key_step_left = KEY_A;
	data->config.key_step_right = KEY_D;
	data->config.key_rotate_left = KEY_LEFT;
	data->config.key_rotate_right = KEY_RIGHT;
	data->config.key_look_up = KEY_UP;
	data->config.key_look_down = KEY_DOWN;
	data->config.key_moove_up = KEY_C;
	data->config.key_moove_down = KEY_V;
	data->config.key_open_door = KEY_E;
	data->config.key_shoot = KEY_SPACE;
	data->config.key_minimap_toggle = KEY_M;
	data->config.key_minimap_grow = KEY_N;
	data->config.key_minimap_shrink = KEY_B;
	data->config.key_move_run = KEY_Q;
}

// * Ajouter une ou +r de ces lignes a la fin
// load_config_azerty(data);
// load_config_small_def(data);
// load_config_full_screen(data);

void	init_config(t_data *data)
{
	data->config.debug_show_hud = 0;
	load_config_default(data);
}
