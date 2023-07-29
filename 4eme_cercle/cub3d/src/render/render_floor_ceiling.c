/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_ceiling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:00:15 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/22 13:03:07 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

typedef struct s_ray_floor
{
	int		is_floor;
	float	dir_x0;
	float	dir_y0;
	float	dir_x1;
	float	dir_y1;
	float	floor_step_x;
	float	floor_step_y;
	float	floor_x;
	float	floor_y;
	int		cell_x;
	int		cell_y;
	int		py;
}	t_ray_floor;

static void	draw(t_data *data, t_ray_floor *ray, int y)
{
	int	x;
	int	color;
	int	tx;
	int	ty;

	x = 0;
	while (x < data->win_width)
	{
		ray->cell_x = (int)(ray->floor_x);
		ray->cell_y = (int)(ray->floor_y);
		tx = (int)(data->txtr_floor.width * (ray->floor_x - ray->cell_x))
			& (data->txtr_floor.width - 1);
		ty = (int)(data->txtr_floor.height * (ray->floor_y - ray->cell_y))
			& (data->txtr_floor.height - 1);
		ray->floor_x += ray->floor_step_x;
		ray->floor_y += ray->floor_step_y;
		if (ray->is_floor)
			color = data->txtr_floor.addr[data->txtr_floor.width * ty + tx];
		else
			color = data->txtr_ceil.addr[data->txtr_floor.width * ty + tx];
		mlxx_put_pixel(data, x, y, color);
		x++;
	}
}

void	render_floor_ceiling_sub_1(t_data *data, t_ray_floor *ray, int y)
{
	ray->dir_x0 = data->player.dir_x - data->player.plan_x;
	ray->dir_y0 = data->player.dir_y - data->player.plan_y;
	ray->dir_x1 = data->player.dir_x + data->player.plan_x;
	ray->dir_y1 = data->player.dir_y + data->player.plan_y;
	ray->is_floor = y > data->win_height / 2 + data->player.pitch_z;
	if (ray->is_floor)
		ray->py = y - data->win_height / 2 - data->player.pitch_z;
	else
		ray->py = data->win_height / 2 - y + data->player.pitch_z;
}

void	render_floor_ceiling(t_data *data)
{
	t_ray_floor	ray;
	int			y;
	float		cam_pos_z;
	float		row_distance;

	y = 0;
	while (y < data->win_height)
	{
		render_floor_ceiling_sub_1(data, &ray, y);
		if (ray.is_floor)
			cam_pos_z = 0.5 * data->win_height + data->player.pos_z;
		else
			cam_pos_z = 0.5 * data->win_height - data->player.pos_z;
		row_distance = cam_pos_z / ray.py;
		ray.floor_step_x = row_distance * (ray.dir_x1 - ray.dir_x0)
			/ data->win_width;
		ray.floor_step_y = row_distance * (ray.dir_y1 - ray.dir_y0)
			/ data->win_width;
		ray.floor_x = data->player.pos_x + row_distance * ray.dir_x0;
		ray.floor_y = data->player.pos_y + row_distance * ray.dir_y0;
		draw(data, &ray, y);
		y++;
	}
}
