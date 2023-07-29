/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_gun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleuty           #+#    #+#             */
/*   Updated: 2023/07/25 12:48:30 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	render_gun(t_data *data)
{
	t_canvas	canvas;

	canvas.width = data->config.gun_width;
	canvas.height = data->gun.height / data->gun.width * canvas.width;
	canvas.left = data->win_width / 2 - canvas.width / 3;
	canvas.top = data->win_height - canvas.height - data->shooting
		+ data->config.gun_shoot_height + 100;
	canvas.transparency_color = 0x0000FF00;
	render_sprite(data, &data->gun, &canvas);
}
