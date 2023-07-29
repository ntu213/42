/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 11:42:14 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_textures_enemies(t_data *data)
{
	int	i;

	i = 0;
	while (data->spritex[i])
	{
		create_texture(data, &data->spritex[i]->texture[0],
			data->map->texture_enemy_1);
		create_texture(data, &data->spritex[i]->texture[1],
			data->map->texture_enemy_2);
		create_texture(data, &data->spritex[i]->texture[2],
			data->map->texture_enemy_target);
		create_texture(data, &data->spritex[i]->texture[3],
			data->map->texture_enemy_dead_1);
		create_texture(data, &data->spritex[i]->texture[4],
			data->map->texture_enemy_dead_2);
		i++;
	}
}

/*
"./maps/textures/zomb0.xpm"
"./maps/textures/zomb1.xpm"
"./maps/textures/zomb2.xpm"
"./maps/textures/zomb3.xpm"
*/
void	set_defaut_textures_names(t_data *data)
{
	if (!data->map->texture_door)
		data->map->texture_door = ft_strdup("./textures/debug/door.xpm");
	if (!data->map->texture_enemy_1)
		data->map->texture_enemy_1 = ft_strdup("./textures/val/mob_idle_0.xpm");
	if (!data->map->texture_enemy_2)
		data->map->texture_enemy_2 = ft_strdup("./textures/val/mob_idle_1.xpm");
	if (!data->map->texture_enemy_target)
		data->map->texture_enemy_target = ft_strdup(
				"./textures/val/mob_aim.xpm");
	if (!data->map->texture_enemy_dead_1)
		data->map->texture_enemy_dead_1 = ft_strdup(
				"./textures/val/mob_death.xpm");
	if (!data->map->texture_enemy_dead_2)
		data->map->texture_enemy_dead_2 = ft_strdup(
				"./textures/val/mob_death_2.xpm");
}

void	set_defaut_textures_null(t_data *data)
{
	data->txtr_walls[0].img = NULL;
	data->txtr_walls[1].img = NULL;
	data->txtr_walls[2].img = NULL;
	data->txtr_walls[3].img = NULL;
	data->txtr_walls[4].img = NULL;
	data->txtr_floor.img = NULL;
	data->txtr_ceil.img = NULL;
	data->gun.img = NULL;
}

void	init_textures(t_data *data)
{
	set_defaut_textures_null(data);
	set_defaut_textures_names(data);
	create_texture(data, &data->txtr_walls[0], data->map->texture_wall_n);
	create_texture(data, &data->txtr_walls[1], data->map->texture_wall_e);
	create_texture(data, &data->txtr_walls[2], data->map->texture_wall_s);
	create_texture(data, &data->txtr_walls[3], data->map->texture_wall_w);
	create_texture(data, &data->txtr_walls[4], data->map->texture_door);
	if (data->map->texture_floor)
		create_texture(data, &data->txtr_floor, data->map->texture_floor);
	if (data->map->texture_ceil)
		create_texture(data, &data->txtr_ceil, data->map->texture_ceil);
	if (data->map->texture_gun)
		create_texture(data, &data->gun, data->map->texture_gun);
	init_textures_enemies(data);
}
