/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls_subs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/22 13:03:44 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	render_walls_sub_3_dda(t_ray_wall	*ray)
{
	if (ray->side_distx < ray->side_disty)
	{
		ray->side_distx += ray->delta_distx;
		ray->mapx += ray->stepx;
		ray->side = 0;
		if (ray->stepx < 0)
			ray->wall_orientation = NORTH;
		else
			ray->wall_orientation = SOUTH;
	}
	else
	{
		ray->side_disty += ray->delta_disty;
		ray->mapy += ray->stepy;
		ray->side = 1;
		if (ray->stepy < 0)
			ray->wall_orientation = WEST;
		else
			ray->wall_orientation = EAST;
	}
}

void	render_walls_sub_4_dda(t_data *data, t_ray_wall	*ray, int x)
{
	if (ray->mapx >= 0 && ray->mapy >= 0 && data->map->map_cells[ray->mapx]
		&& data->map->map_cells[ray->mapx][ray->mapy])
	{
		if (ray->side == 0)
			ray->perp_wall_dist = (ray->side_distx - ray->delta_distx);
		else
			ray->perp_wall_dist = (ray->side_disty - ray->delta_disty);
		if (data->map->map_cells[ray->mapx][ray->mapy] == '1')
			ray->hit = 1;
		else if (data->map->map_cells[ray->mapx][ray->mapy] == 'D')
		{
			ray->hit = 2;
			if (x == data->win_width / 2 && ray->perp_wall_dist < 1.5)
			{
				data->selected_door_x = ray->mapx;
				data->selected_door_y = ray->mapy;
			}
		}
	}
}

void	render_walls_sub_5(t_data *data, t_ray_wall	*ray)
{
	ray->line_height = (int)(data->win_height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + data->win_height / 2
		+ data->player.pitch_z + (data->player.pos_z / ray->perp_wall_dist);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + data->win_height / 2
		+ data->player.pitch_z + (data->player.pos_z / ray->perp_wall_dist);
	if (ray->draw_end >= data->win_height)
		ray->draw_end = data->win_height - 1;
	if (ray->side == 0)
		ray->wall_x = data->player.pos_y + ray->perp_wall_dist * ray->raydiry;
	else
		ray->wall_x = data->player.pos_x + ray->perp_wall_dist * ray->raydirx;
	ray->wall_x -= floor((ray->wall_x));
}

void	render_walls_sub_6(t_data *data, t_ray_wall	*ray, int x)
{
	int		y;
	int		color;

	ray->tex_id = ray->wall_orientation;
	if (ray->hit == 2)
		ray->tex_id = 4;
	ray->tex_x = (int)(ray->wall_x
			* (double)(data->txtr_walls[ray->tex_id].width));
	if (ray->wall_orientation == WEST || ray->wall_orientation == SOUTH)
		ray->tex_x = data->txtr_walls[ray->tex_id].width - ray->tex_x - 1;
	ray->step = 1.0 * data->txtr_walls[ray->tex_id].height / ray->line_height;
	ray->tex_pos = (ray->draw_start - data->player.pitch_z
			- (data->player.pos_z / ray->perp_wall_dist) - data->win_height / 2
			+ ray->line_height / 2) * ray->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos
			& (data->txtr_walls[ray->tex_id].height - 1);
		ray->tex_pos += ray->step;
		color = data->txtr_walls[ray->tex_id].addr[ray->tex_y
			* data->txtr_walls[ray->tex_id].line_length / 4 + ray->tex_x];
		mlxx_put_pixel(data, x, y, color);
		y++;
	}
}
