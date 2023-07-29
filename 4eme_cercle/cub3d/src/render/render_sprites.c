/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:48:59 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/24 16:11:46 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	render_sprites_sub_1_sort(t_data *data);
void	render_sprites_sub_2(t_data *data, t_ray_sprite *ray, int i);

void	render_sprites_sub_3(t_data *data, t_ray_sprite *ray, int i)
{
	ray->sprite_width = abs((int)(data->win_height / (ray->transform_y)))
		/ data->spritex[i]->size_divizor;
	ray->draw_start_x = -ray->sprite_width / 2 + ray->sprite_screen_x;
	if (ray->draw_start_x < 0)
		ray->draw_start_x = 0;
	ray->draw_end_x = ray->sprite_width / 2 + ray->sprite_screen_x;
	if (ray->draw_end_x >= data->win_width)
		ray->draw_end_x = data->win_width - 1;
}

void	set_ray_tex_x(t_data *data, t_ray_sprite *ray, int i, int stripe)
{
	ray->tex_x = (int)(256 * (stripe - (-ray->sprite_width / 2 + ray
					->sprite_screen_x)) * data->spritex[i]->texture[data
			->spritex[i]->text_num].width / ray->sprite_width) / 256;
}

int	render_sprites_sub_5(t_data *data, t_ray_sprite *ray, int i, int d)
{
	int	color;

	ray->tex_y = ((d * data->spritex[i]->texture[data->spritex[i]->text_num]
				.height) / ray->sprite_height) / 256;
	color = data->spritex[i]->texture[data->spritex[i]->text_num].addr[data
		->spritex[i]->texture[data->spritex[i]->text_num].width
		* ray->tex_y + ray->tex_x];
	return (color);
}

void	render_sprites_sub_4(t_data *data, t_ray_sprite *ray, int i, int stripe)
{
	int	y;
	int	d;
	int	color;

	set_ray_tex_x(data, ray, i, stripe);
	if (ray->transform_y > 0 && stripe > 0 && stripe < data->win_width
		&& ray->transform_y < data->z_buffer[stripe])
	{
		y = ray->draw_start_y;
		while (y < ray->draw_end_y)
		{
			if (stripe == data->win_width / 2)
				data->spritex[i]->is_in_viseur = 1;
			d = (y - ray->v_move_screen) * 256 - data->win_height * 128
				+ ray->sprite_height * 128;
			color = render_sprites_sub_5(data, ray, i, d);
			if ((color & 0x00FFFFFF) != 0)
				mlxx_put_pixel(data, stripe, y
					+ data->player.pitch_z
					+ data->player.pos_z / ray->transform_y, color);
			y++;
		}
	}
}

void	render_sprites(t_data *data)
{
	t_ray_sprite	ray;
	int				i;
	int				stripe;

	render_sprites_sub_1_sort(data);
	i = 0;
	while (data->spritex[i])
	{
		if (data->spritex[i]->is_alive)
		{
			data->spritex[i]->is_in_viseur = 0;
			render_sprites_sub_2(data, &ray, i);
			render_sprites_sub_3(data, &ray, i);
			stripe = ray.draw_start_x;
			while (stripe < ray.draw_end_x)
			{
				render_sprites_sub_4(data, &ray, i, stripe);
				stripe++;
			}
		}
		i++;
	}
}
