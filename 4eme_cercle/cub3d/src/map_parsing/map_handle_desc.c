/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handle_desc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 11:19:26 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	invalid_char_in_desc(char *line)
{
	int	c;

	c = 0;
	while (line[c])
	{
		if (line[c] != '0' && line[c] != '1' && line[c] != ' '
			&& line[c] != '\n' && line[c] != 'N' && line[c] != 'S'
			&& line[c] != 'E' && line[c] != 'W' && line[c] != 'Z'
			&& line[c] != 'D')
			return (line[c]);
		c++;
	}
	return (0);
}

void	set_map_size(t_map *map)
{
	int	x;
	int	y;

	map->width = 0;
	map->height = 0;
	y = 0;
	while (map->map_cells[y])
	{
		x = 0;
		while (map->map_cells[y][x])
		{
			x++;
			if (map->width < x)
				map->width = x;
		}
		y++;
	}
	map->height = y;
}

int	print_map_desc_and_check_chars_or_exit(t_data *data)
{
	int		d;
	int		has_error;
	char	invalid_char;

	ft_printf("MAP_DESC:\n");
	ft_printf("-------------------------------------------------------\n"C_GRE);
	d = 0;
	has_error = 0;
	while (data->map->mapfile_strs_desc[d])
	{
		invalid_char = invalid_char_in_desc(data->map->mapfile_strs_desc[d]);
		if (invalid_char)
		{
			ft_printf(C_WHI""B_RED"%s"C_NOR, data->map->mapfile_strs_desc[d]);
			ft_printf(C_RED" << invalid char '%c'\n"C_NOR, invalid_char);
			has_error = 1;
		}
		else
			ft_printf(C_GRE"%s\n"C_NOR, data->map->mapfile_strs_desc[d]);
		d++;
	}
	ft_printf(C_NOR"-------------------------------------------------------\n");
	if (has_error)
		free_exit_with_error(data, "Invalid char in desc");
	return (0);
}

void	map_handle_desc(t_data *data)
{
	print_map_desc_and_check_chars_or_exit(data);
	if (!is_wall_ok(data->map->mapfile_strs_desc))
	{
		print_error_message("Unclosed wall !");
		free_data_and_exit(data);
	}
	if (!is_player_ok(data->map->mapfile_strs_desc))
	{
		print_error_message("one and only one player needed!");
		free_data_and_exit(data);
	}
	data->map->map_cells = data->map->mapfile_strs_desc;
	set_map_size(data->map);
}

void	print_map_info(t_map *map)
{
	ft_printf("MAP_INFO:\n");
	ft_printf("-------------------------------------------------------\n"C_CYA);
	ft_printf("map->texture_wall_n: %s\n", map->texture_wall_n);
	ft_printf("map->texture_wall_s: %s\n", map->texture_wall_s);
	ft_printf("map->texture_wall_w: %s\n", map->texture_wall_w);
	ft_printf("map->texture_wall_e: %s\n", map->texture_wall_e);
	ft_printf("map->color_rgb_str_floor:    %s\n", map->color_rgb_str_floor);
	ft_printf("map->color_rgb_str_ceil:  %s\n", map->color_rgb_str_ceil);
	ft_printf("map->texture_floor:  %s\n", map->texture_floor);
	ft_printf("map->texture_ceil:  %s\n", map->texture_ceil);
	ft_printf("map->texture_gun:  %s\n", map->texture_gun);
	ft_printf(C_NOR"-------------------------------------------------------\n");
}
