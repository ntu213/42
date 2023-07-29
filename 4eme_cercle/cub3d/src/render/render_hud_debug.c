/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud_debug.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleuty           #+#    #+#             */
/*   Updated: 2023/07/22 14:12:40 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	render_hud_debug_sub_1(t_data *data, t_canvas *canvas)
{
	mlxx_put_str_double(data, canvas, "mousex  : ", data->mousex);
	canvas->top += 20;
	mlxx_put_str_double(data, canvas, "mousey  : ", data->mousey);
	canvas->top += 20;
	canvas->top += 20;
	mlxx_put_str_double(data, canvas, "frame_rate  : ", data->frame_rate);
	canvas->top += 20;
	canvas->top += 20;
	mlxx_put_str_double(data, canvas, "map->width  : ", data->map->width);
	canvas->top += 20;
	mlxx_put_str_double(data, canvas, "map->height  : ", data->map->height);
	canvas->top += 20;
	canvas->top += 20;
	mlxx_put_str_double(data, canvas, "sel_door_x  : ", data->selected_door_x);
	mlxx_put_str_double(data, canvas, "sel_door_y  : ", data->selected_door_y);
}

void	render_hud_debug(t_data *data)
{
	t_canvas	canvas;

	if (!data->config.debug_show_hud)
		return ;
	canvas.left = 10;
	canvas.top = 20;
	canvas.color = 0x00FF5500;
	mlxx_set_font_size(data, 18);
	mlxx_put_str_double(data, &canvas, "pos_x  : ", data->player.pos_x);
	canvas.top += 20;
	mlxx_put_str_double(data, &canvas, "pos_y  : ", data->player.pos_y);
	canvas.top += 20;
	canvas.top += 20;
	mlxx_put_str_double(data, &canvas, "dir_x  : ", data->player.dir_x);
	canvas.top += 20;
	mlxx_put_str_double(data, &canvas, "dir_y  : ", data->player.dir_y);
	canvas.top += 20;
	canvas.top += 20;
	mlxx_put_str_double(data, &canvas, "pitch_z  : ", data->player.pitch_z);
	canvas.top += 20;
	mlxx_put_str_double(data, &canvas, "pos_z  : ", data->player.pos_z);
	canvas.top += 20;
	canvas.top += 20;
	render_hud_debug_sub_1(data, &canvas);
}
