/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 11:49:36 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	free_and_destroy_enemies(t_data *data)
{
	int	i;

	i = 0;
	while (data->spritex[i])
	{
		if (data->spritex[i]->texture[0].img)
			mlx_destroy_image(data->mlx, data->spritex[i]->texture[0].img);
		if (data->spritex[i]->texture[1].img)
			mlx_destroy_image(data->mlx, data->spritex[i]->texture[1].img);
		if (data->spritex[i]->texture[2].img)
			mlx_destroy_image(data->mlx, data->spritex[i]->texture[2].img);
		if (data->spritex[i]->texture[3].img)
			mlx_destroy_image(data->mlx, data->spritex[i]->texture[3].img);
		if (data->spritex[i]->texture[4].img)
			mlx_destroy_image(data->mlx, data->spritex[i]->texture[4].img);
		free (data->spritex[i]);
		i++;
	}
}

/*
	ft_printf("%p|%p|%p\n", data->mlx, data->txtr_floor.img, data->mlx,
		data->txtr_floor.img, data->mlx, data->gun.img);
*/
void	destroy_imgs(t_data *data)
{
	if (data->mlximg.img)
		mlx_destroy_image(data->mlx, data->mlximg.img);
	if (data->txtr_walls[0].img)
		mlx_destroy_image(data->mlx, data->txtr_walls[0].img);
	if (data->txtr_walls[1].img)
		mlx_destroy_image(data->mlx, data->txtr_walls[1].img);
	if (data->txtr_walls[2].img)
		mlx_destroy_image(data->mlx, data->txtr_walls[2].img);
	if (data->txtr_walls[3].img)
		mlx_destroy_image(data->mlx, data->txtr_walls[3].img);
	if (data->txtr_walls[4].img)
		mlx_destroy_image(data->mlx, data->txtr_walls[4].img);
	if (data->txtr_floor.img)
		mlx_destroy_image(data->mlx, data->txtr_floor.img);
	if (data->txtr_ceil.img)
		mlx_destroy_image(data->mlx, data->txtr_ceil.img);
	if (data->gun.img)
		mlx_destroy_image(data->mlx, data->gun.img);
}

//// free_strs_if_exist(map->map_cells); // !! CE NEST PAS UNE DEEP COPIE !!
void	free_map(t_map *map)
{
	if (!map)
		return ;
	free_strs_if_exist(map->mapfile_strs);
	free_strs_if_exist(map->mapfile_strs_desc);
	free_strs_if_exist(map->mapfile_strs_infos);
	free_str_if_exist(map->texture_wall_n);
	free_str_if_exist(map->texture_wall_s);
	free_str_if_exist(map->texture_wall_w);
	free_str_if_exist(map->texture_wall_e);
	free_str_if_exist(map->texture_floor);
	free_str_if_exist(map->texture_ceil);
	free_str_if_exist(map->texture_door);
	free_str_if_exist(map->texture_gun);
	free_str_if_exist(map->texture_enemy_1);
	free_str_if_exist(map->texture_enemy_2);
	free_str_if_exist(map->texture_enemy_target);
	free_str_if_exist(map->texture_enemy_dead_1);
	free_str_if_exist(map->texture_enemy_dead_2);
	free_str_if_exist(map->color_rgb_str_floor);
	free_str_if_exist(map->color_rgb_str_ceil);
	free(map);
}

int	free_data_and_exit(t_data *data)
{
	if (data)
	{
		if (data->map)
			free_map(data->map);
		if (data->z_buffer)
			free (data->z_buffer);
		if (data->spritex)
			free(data->spritex);
	}
	exit (0);
}

int	game_quit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	destroy_imgs(data);
	free_and_destroy_enemies(data);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	return (free_data_and_exit(data));
}
