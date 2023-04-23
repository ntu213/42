/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:10:36 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/17 10:10:45 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_new_win(t_data *data)
{
	if (data->max_height != 0 && data->max_width != 0)
		data->win = mlx_new_window(data->mlx, data->max_width * 40,
				data->max_height * 40, "Spaghetti");
	else
		data->win = mlx_new_window(data->mlx, 400,
				400, "Spaghetti");
}

t_data	*ft_init_data(t_map **map, int j)
{
	t_data	*data;
	int		i;

	i = 0;
	data = malloc(sizeof(t_data));
	data->max_width = 0;
	data->max_height = 0;
	while (i < j)
	{
		if (map[i]->height > data->max_height && map[i]->ok)
			data->max_height = map[i]->height;
		if (map[i]->width > data->max_width && map[i]->ok)
			data->max_width = map[i]->width;
		i++;
	}
	data->mlx = mlx_init();
	data->img = ft_img_init(data);
	ft_new_win(data);
	return (data);
}

void	ft_reset_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->max_height)
	{
		j = 0;
		while (j < data->max_width)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->img->wall,
				j * 40, i * 40);
			j++;
		}
		i++;
	}
}

void	ft_put_img(t_data *data, char c, int i, int j)
{
	if (c == '1' || c == 'I')
		mlx_put_image_to_window(data->mlx, data->win, data->img->wall,
			j * 40, i * 40);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img->floor,
			j * 40, i * 40);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img->playerd,
			j * 40, i * 40);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img->coll,
			j * 40, i * 40);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit,
			j * 40, i * 40);
	else if (c == 'M')
		mlx_put_image_to_window(data->mlx, data->win, data->img->mob,
			j * 40, i * 40);
	else if (c == 'S')
		mlx_put_image_to_window(data->mlx, data->win, data->img->weapon,
			j * 40, i * 40);
}

void	ft_place_map(t_data *data, t_map *map, int wx, int wy)
{
	int	i;
	int	j;

	i = wy / 2;
	while (i - (wy / 2) < map->height)
	{
		j = wx / 2;
		while (j - (wx / 2) < map->width)
		{
			ft_put_img(data, map->map[i - (wy / 2)][j - (wx / 2)], i, j);
			j++;
		}
		i++;
	}
}
