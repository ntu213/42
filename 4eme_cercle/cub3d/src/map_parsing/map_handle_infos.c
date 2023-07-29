/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 11:51:17 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	print_map_info(t_map *map);

//* verifie que la map contient bien toutes les infos de textures/color
static void	map_check_infos_textures_or_exit(t_data *data)
{
	if (!data->map->texture_wall_n)
		free_exit_with_error(data, "Missing info on map : \"NO\" !");
	if (!data->map->texture_wall_w)
		free_exit_with_error(data, "Missing info on map : \"WE\" !");
	if (!data->map->texture_wall_e)
		free_exit_with_error(data, "Missing info on map : \"EA\" !");
	if (!data->map->texture_wall_s)
		free_exit_with_error(data, "Missing info on map : \"SO\" !");
	if (!data->map->texture_floor && !data->map->color_rgb_str_floor)
		free_exit_with_error(data, "Missing info on map: \"F\" or \"FLOOR\" !");
	if (!data->map->texture_ceil && !data->map->color_rgb_str_ceil)
		free_exit_with_error(data, "Missing info on map: \"C\" or \"CEIL\" !");
}

// ft_printf("DEBUG: %s|%s\n", split[0], split[1]);
static void	set_map_attr_or_exit(t_data *data, char **attribute, char **split)
{
	if (*attribute != NULL)
	{
		ft_printf(C_YEL"Duplicate entry : %s\n"C_NOR, split[0]);
		ft_strs_free(split);
		free_data_and_exit(data);
		exit (1);
	}
	else
	{
		*attribute = ft_strdup(split[1]);
		ft_strs_free(split);
	}
}

static void	map_set_infos_2(t_data *data, char **split)
{
	if (ft_str_equals(split[0], "SO"))
		set_map_attr_or_exit(data, &data->map->texture_wall_s, split);
	else if (ft_str_equals(split[0], "WE"))
		set_map_attr_or_exit(data, &data->map->texture_wall_w, split);
	else if (ft_str_equals(split[0], "EA"))
		set_map_attr_or_exit(data, &data->map->texture_wall_e, split);
	else if (ft_str_equals(split[0], "F"))
		set_map_attr_or_exit(data, &data->map->color_rgb_str_floor, split);
	else if (ft_str_equals(split[0], "C"))
		set_map_attr_or_exit(data, &data->map->color_rgb_str_ceil, split);
	else if (ft_str_equals(split[0], "DOOR"))
		set_map_attr_or_exit(data, &data->map->texture_door, split);
	else if (ft_str_equals(split[0], "FLOOR"))
		set_map_attr_or_exit(data, &data->map->texture_floor, split);
	else if (ft_str_equals(split[0], "CEIL"))
		set_map_attr_or_exit(data, &data->map->texture_ceil, split);
	else if (ft_str_equals(split[0], "GUN"))
		set_map_attr_or_exit(data, &data->map->texture_gun, split);
	else
	{
		print_error_message("Ligne inconnue: ");
		ft_printf(C_YEL"    %s \n "C_NOR, split[0]);
	}
}

static int	map_set_infos(t_data *data, int map_start_line_index)
{
	int		i;
	char	**split;

	i = 0;
	data->map->texture_floor = NULL;
	data->map->texture_ceil = NULL;
	data->map->texture_gun = NULL;
	while (i < map_start_line_index && data->map->mapfile_strs[i])
	{
		split = ft_split(data->map->mapfile_strs[i], ' ');
		if (ft_strs_size(split) < 2)
		{
			ft_strs_free(split);
			free_exit_with_error_x2(data, "Missing Info on line",
				data->map->mapfile_strs[i]);
		}
		else if (ft_str_equals(split[0], "NO"))
			set_map_attr_or_exit(data, &data->map->texture_wall_n, split);
		else
			map_set_infos_2(data, split);
		i++;
	}
	return (0);
}

void	map_handle_infos(t_data *data, int map_start_line_index)
{
	if (map_set_infos(data, map_start_line_index))
	{
		free_data_and_exit(data);
		exit(print_error_message("ERRROOORRRR 124 NARRIVE JAMAIS ?????"));
	}
	set_color_ceil_and_floor_from_rgb_or_exit(data);
	print_map_info(data->map);
	map_check_infos_textures_or_exit(data);
}
