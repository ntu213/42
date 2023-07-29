/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 11:50:48 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// * spr_enemy->x = y; // * oui, c'est inverse
static t_sprite	*create_ennemy(t_data *data, double x, double y)
{
	t_sprite	*spr_enemy;

	(void) data;
	spr_enemy = malloc(sizeof(t_sprite));
	spr_enemy->x = y;
	spr_enemy->y = x;
	spr_enemy->size_divizor = 1.0;
	spr_enemy->vertical_move = 0.0;
	spr_enemy->exist = 1;
	spr_enemy->text_num = 0;
	spr_enemy->is_in_viseur = 0;
	spr_enemy->is_alive = 1;
	spr_enemy->killed_timestamp = 0;
	return (spr_enemy);
}

static void	count_enemies(t_data *data)
{
	int	x;
	int	y;

	data->enemies_count = 0;
	y = 0;
	while (data->map->map_cells[y])
	{
		x = 0;
		while (data->map->map_cells[y][x])
		{
			if (data->map->map_cells[y][x] == 'Z')
				data->enemies_count ++;
			x++;
		}
		y++;
	}
	data->enemies_count_initial = data->enemies_count;
}

void	init_enemies(t_data *data)
{
	int	x;
	int	y;
	int	e;

	count_enemies(data);
	data->spritex = ft_calloc(data->enemies_count + 1, sizeof(t_sprite *));
	y = 0;
	e = 0;
	while (data->map->map_cells[y])
	{
		x = 0;
		while (data->map->map_cells[y][x])
		{
			if (data->map->map_cells[y][x] == 'Z')
			{
				data->spritex[e] = create_ennemy(data, x + 0.5, y + 0.5);
				data->map->map_cells[y][x] = '0';
				e++;
			}
			x++;
		}
		y++;
	}
}
