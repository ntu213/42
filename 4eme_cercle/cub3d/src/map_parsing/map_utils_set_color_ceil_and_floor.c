/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_set_color_ceil_and_floor.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 11:19:42 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	str_rgb_to_int_or_exit(t_data *data, char *rgb)
{
	int	value;

	value = ft_str_rgb_to_int(rgb);
	if (value == -1)
		return (free_exit_with_error(data, "error with rgb color"));
	return (value);
}

void	set_color_ceil_and_floor_from_rgb_or_exit(t_data *data)
{
	if (data->map->color_rgb_str_floor)
		data->map->color_floor = str_rgb_to_int_or_exit(data,
				data->map->color_rgb_str_floor);
	if (data->map->color_rgb_str_ceil)
		data->map->color_ceil = str_rgb_to_int_or_exit(data,
				data->map->color_rgb_str_ceil);
}
