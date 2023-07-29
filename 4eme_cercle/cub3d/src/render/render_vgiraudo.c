/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_vgiraudo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/24 16:19:31 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	render_vgiraudo(t_data *data)
{
	t_canvas	canvas;

	canvas.left = data->win_width -300;
	canvas.top = 40;
	canvas.color = 0x0000FFFF;
	mlxx_set_font_size(data, 18);
	mlxx_put_str(data, &canvas, " -------- Controls -------- ");
	canvas.top += 20;
	mlxx_put_str(data, &canvas, "Shoot          [MOUSE_CLICK]");
	canvas.top += 20;
	mlxx_put_str(data, &canvas, "Give Up        [ESC]");
	canvas.top += 20;
	mlxx_put_str(data, &canvas, "Move           [W] [A] [S] [D]");
	canvas.top += 20;
	mlxx_put_str(data, &canvas, "Sprint         [Q]");
	canvas.top += 20;
	mlxx_put_str(data, &canvas, "Shrek Mode     [C]");
	canvas.top += 20;
	mlxx_put_str(data, &canvas, "Gremlin Mode   [V]");
	canvas.top += 20;
	mlxx_put_str(data, &canvas, "Enable Minimap [M]");
	canvas.top += 20;
	mlxx_put_str(data, &canvas, "Minimap Zoom+  [N]");
	canvas.top += 20;
	mlxx_put_str(data, &canvas, "Minimap Zoom-  [B]");
}
