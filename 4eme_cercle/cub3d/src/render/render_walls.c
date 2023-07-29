/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/22 10:24:20 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	render_walls_sub_3_dda(t_ray_wall	*ray);
void	render_walls_sub_4_dda(t_data *data, t_ray_wall	*ray, int x);
void	render_walls_sub_5(t_data *data, t_ray_wall	*ray);
void	render_walls_sub_6(t_data *data, t_ray_wall	*ray, int x);

void	render_walls_sub_1(t_data *data, t_ray_wall	*ray, int x)
{
	ray->camerax = 2 * x / (double) data->win_width - 1;
	ray->raydirx = data->player.dir_x + data->player.plan_x * ray->camerax;
	ray->raydiry = data->player.dir_y + data->player.plan_y * ray->camerax;
	ray->mapx = (int)(data->player.pos_x);
	ray->mapy = (int)(data->player.pos_y);
	ray->delta_distx = 999999;
	ray->delta_disty = 999999;
	if (ray->raydirx != 0)
		ray->delta_distx = ft_math_abs_double(1 / (ray->raydirx));
	if (ray->raydiry != 0)
		ray->delta_disty = ft_math_abs_double(1 / (ray->raydiry));
	ray->hit = 0;
}

void	render_walls_sub_2(t_data *data, t_ray_wall	*ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->side_distx = (data->player.pos_x - ray->mapx) * ray->delta_distx;
	}
	else
	{
		ray->stepx = 1;
		ray->side_distx = (ray->mapx + 1.0 - data->player.pos_x)
			* ray->delta_distx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->side_disty = (data->player.pos_y - ray->mapy) * ray->delta_disty;
	}
	else
	{
		ray->stepy = 1;
		ray->side_disty = (ray->mapy + 1.0 - data->player.pos_y)
			* ray->delta_disty;
	}
}

void	render_walls(t_data *data)
{
	t_ray_wall	ray;
	int			x;

	data->selected_door_x = -1;
	data->selected_door_y = -1;
	x = 0;
	while (x < data->win_width)
	{
		render_walls_sub_1(data, &ray, x);
		render_walls_sub_2(data, &ray);
		while (ray.hit == 0)
		{
			render_walls_sub_3_dda(&ray);
			render_walls_sub_4_dda(data, &ray, x);
		}
		render_walls_sub_5(data, &ray);
		render_walls_sub_6(data, &ray, x);
		data->z_buffer[x] = ray.perp_wall_dist;
		x++;
	}
}
