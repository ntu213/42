/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/24 13:11:24 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_get_color(int x, int y);

void	minimap_change_size(t_data *data, int n)
{
	if (!data->config.minimap_size || (data->config.minimap_size == 1 && n < 0)
		|| (data->config.minimap_size >= 5 && n > 0))
		return ;
	data->config.minimap_size += n;
}

void	minimap_toggle(t_data *data)
{
	static int	mem = 1;

	if (!data->config.minimap_size)
		data->config.minimap_size = mem;
	else
	{
		mem = data->config.minimap_size;
		data->config.minimap_size = 0;
	}
}

static void	draw_mini_case(t_data *data, int x, int y, char chare)
{
	int	xx;
	int	yy;
	int	colr;
	int	size1;

	size1 = data->config.minimap_size;
	if (chare == 'D')
		colr = 0x0000FF00;
	else
		colr = ft_get_color(x, y);
	yy = 0;
	while (yy < size1)
	{
		xx = 0;
		while (xx < size1)
		{
			mlxx_put_pixel(data, x * size1 + xx, y * size1 + yy, colr);
			xx++;
		}
		yy++;
	}
}

static void	draw_mini_player(t_data *data, int x, int y, int size1)
{
	int	xx;
	int	yy;
	int	colr;

	colr = 0x00FF0000;
	yy = 0;
	while (yy < size1)
	{
		xx = 0;
		while (xx < size1)
		{
			mlxx_put_pixel(data, y * size1 + xx, x * size1 + yy, colr);
			xx++;
		}
		yy++;
	}
}

void	render_minimap(t_data *data)
{
	int	x;
	int	y;
	int	top;
	int	left;

	if (data->config.minimap_size < 1)
		return ;
	top = data->win_height / data->config.minimap_size - data->map->height - 10;
	left = data->win_width / data->config.minimap_size - data->map->width - 10;
	y = 0;
	while (data->map->map_cells[y])
	{
		x = 0;
		while (data->map->map_cells[y][x])
		{
			if (data->map->map_cells[y][x] == '1'
				|| data->map->map_cells[y][x] == 'D')
				draw_mini_case(data, x + left, y + top,
					data->map->map_cells[y][x]);
			x++;
		}
		y++;
	}
	draw_mini_player(data, data->player.pos_x + top, data->player.pos_y + left,
		data->config.minimap_size);
}
