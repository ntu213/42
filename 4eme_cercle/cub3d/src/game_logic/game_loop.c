/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/24 16:19:42 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	door_in_front_of_player(t_data *data)
{
	int	playerx;
	int	playery;

	playerx = (int) data->player.pos_x;
	playery = (int) data->player.pos_y;
	if (data->map->map_cells[playerx + 1][playery] == 'D')
		return (1);
	if (data->map->map_cells[playerx - 1][playery] == 'D')
		return (1);
	if (data->map->map_cells[playerx][playery + 1] == 'D')
		return (1);
	if (data->map->map_cells[playerx][playery - 1] == 'D')
		return (1);
	return (0);
}

int	game_loop(t_data *data)
{
	if (data->shooting > 0)
		data->shooting -= data->shooting / 4;
	handle_frames(data);
	handle_mouse(data);
	if (data->map->texture_floor && data->map->texture_ceil)
		render_floor_ceiling(data);
	else
		render_floor_ceiling_untextured(data);
	render_walls(data);
	render_sprites(data);
	render_minimap(data);
	if (data->map->texture_gun)
		render_gun(data);
	render_viseur(data);
	mlx_put_image_to_window(data->mlx, data->win, data->mlximg.img, 0, 0);
	render_hud_debug(data);
	render_hud(data);
	render_vgiraudo(data);
	return (0);
}
