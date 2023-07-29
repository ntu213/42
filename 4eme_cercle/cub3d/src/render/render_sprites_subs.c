/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites_subs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:48:59 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/24 16:12:02 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	swap_sprites(t_sprite *sprite1, t_sprite *sprite2)
{
	t_sprite	tmp_sprite;

	tmp_sprite = *sprite1;
	*sprite1 = *sprite2;
	*sprite2 = tmp_sprite;
}

//sort sprites from far to close
static void	sort_sprites(t_sprite **sprites)
{
	int	change;
	int	i;

	change = 1;
	while (change)
	{
		change = 0;
		i = 0;
		while (sprites[i] && sprites[i + 1])
		{
			if (sprites[i]->sprite_distance < sprites[i + 1]->sprite_distance)
			{
				change = 1;
				swap_sprites(sprites[i], sprites[i + 1]);
			}
			i++;
		}
	}
}

void	render_sprites_sub_2(t_data *data, t_ray_sprite *ray, int i)
{
	ray->sprite_x = data->spritex[i]->x - data->player.pos_x;
	ray->sprite_y = data->spritex[i]->y - data->player.pos_y;
	ray->inv_det = 1.0 / (data->player.plan_x * data->player.dir_y
			- data->player.dir_x * data->player.plan_y);
	ray->transform_x = ray->inv_det * (data->player.dir_y * ray->sprite_x
			- data->player.dir_x * ray->sprite_y);
	ray->transform_y = ray->inv_det * (-data->player.plan_y * ray->sprite_x
			+ data->player.plan_x * ray->sprite_y);
	ray->sprite_screen_x = (int)((data->win_width / 2)
			* (1 + ray->transform_x / ray->transform_y));
	ray->v_move_screen = (int)(data->spritex[i]->vertical_move
			/ ray->transform_y);
	ray->sprite_height = abs((int)(data->win_height / (ray->transform_y)))
		/ data->spritex[i]->size_divizor;
	ray->draw_start_y = -ray->sprite_height / 2 + data->win_height / 2
		+ ray->v_move_screen;
	if (ray->draw_start_y < 0)
		ray->draw_start_y = 0;
	ray->draw_end_y = ray->sprite_height / 2 + data->win_height / 2
		+ ray->v_move_screen;
	if (ray->draw_end_y >= data->win_height)
		ray->draw_end_y = data->win_height - 1;
}

void	render_sprites_sub_1_sort(t_data *data)
{
	int	i;

	i = 0;
	while (data->spritex[i])
	{
		data->spritex[i]->sprite_distance = ((data->player.pos_x
					- data->spritex[i]->x) * (data->player.pos_x
					- data->spritex[i]->x)
				+ (data->player.pos_y - data->spritex[i]->y)
				* (data->player.pos_y - data->spritex[i]->y));
		i++;
	}
	sort_sprites(data->spritex);
}
