/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleuty           #+#    #+#             */
/*   Updated: 2023/07/24 11:11:14 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	render_hud_enemies_left(t_data *data)
{
	t_canvas	canvas;

	if (data->enemies_count_initial < 1)
		return ;
	canvas.left = data->win_width / 2 - 100;
	canvas.top = 40;
	canvas.color = 0x00FFFFFF;
	mlxx_set_font_size(data, 32);
	mlxx_put_str_int(data, &canvas,
		"Enemies left: ", data->enemies_count);
}

static void	render_hud_you_won(t_data *data)
{
	t_canvas	canvas;

	if (data->enemies_count_initial < 1 || data->enemies_count > 0)
		return ;
	canvas.left = data->win_width / 2 - 200;
	canvas.top = data->win_height / 2 + 30;
	canvas.color = 0x0000FF00;
	mlxx_set_font_size(data, 24);
	mlxx_put_str(data, &canvas, "--- YOU WON - Press [escape]--- ");
}

static void	render_hud_open_door(t_data *data)
{
	t_canvas	canvas;

	if (data->selected_door_x > 0 && data->selected_door_y > 0)
	{
		canvas.left = data->win_width / 2 - 300;
		canvas.top = data->win_height / 2 + 30;
		canvas.color = 0x00FF0000;
		mlxx_set_font_size(data, 32);
		mlxx_put_str(data, &canvas, "PRESS [E] TO ANNIHILATE THE DOOR");
	}
}

void	render_hud(t_data *data)
{
	render_hud_enemies_left(data);
	render_hud_you_won(data);
	render_hud_open_door(data);
}
