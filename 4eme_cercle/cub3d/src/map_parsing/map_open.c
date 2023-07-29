/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 11:51:39 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	map_handle_infos(t_data *data, int map_start_line_index);
void	map_handle_desc(t_data *data);

t_map	*map_init(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	map->texture_wall_n = NULL;
	map->texture_wall_s = NULL;
	map->texture_wall_w = NULL;
	map->texture_wall_e = NULL;
	map->texture_door = NULL;
	map->texture_floor = NULL;
	map->texture_ceil = NULL;
	map->texture_gun = NULL;
	map->texture_enemy_1 = NULL;
	map->texture_enemy_2 = NULL;
	map->texture_enemy_target = NULL;
	map->texture_enemy_dead_1 = NULL;
	map->texture_enemy_dead_2 = NULL;
	map->color_rgb_str_floor = NULL;
	map->color_rgb_str_ceil = NULL;
	map->color_floor = -1;
	map->color_ceil = -1;
	map->mapfile_strs = NULL;
	map->mapfile_strs_desc = NULL;
	map->mapfile_strs_infos = NULL;
	return (map);
}

void	check_first_line_desc(t_data *data, int map_start_line_index)
{
	char	*trim;

	trim = ft_strtrim_white_space(
			data->map->mapfile_strs[map_start_line_index]);
	if (!trim)
	{
		ft_printf("Error 5785634\n");
		free(trim);
		free_data_and_exit(data);
	}
	if (trim[0] != '1')
	{
		print_error_message_x2("Error on line: ", trim);
		free(trim);
		free_data_and_exit(data);
	}
	free(trim);
}

void	open_map(t_data *data, char *filename)
{
	int	map_start_line_index;

	data->map = map_init();
	set_mapfile_strs_or_exit(data, filename);
	map_start_line_index = get_map_start_line_index_or_exit(data);
	check_first_line_desc(data, map_start_line_index);
	set_map_desc_strs(data, map_start_line_index);
	set_map_infos_strs(data, map_start_line_index);
	map_handle_infos(data, map_start_line_index);
	map_handle_desc(data);
}
