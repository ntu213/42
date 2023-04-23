/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:12:59 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/17 10:13:09 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img->wall);
	mlx_destroy_image(data->mlx, data->img->floor);
	mlx_destroy_image(data->mlx, data->img->playerw);
	mlx_destroy_image(data->mlx, data->img->playera);
	mlx_destroy_image(data->mlx, data->img->players);
	mlx_destroy_image(data->mlx, data->img->playerd);
	mlx_destroy_image(data->mlx, data->img->coll);
	mlx_destroy_image(data->mlx, data->img->exit);
	mlx_destroy_image(data->mlx, data->img->mob);
	mlx_destroy_image(data->mlx, data->img->weapon);
	mlx_destroy_image(data->mlx, data->img->hp);
	mlx_loop_end(data->mlx);
	free(data->img);
	data->hasexit = 1;
}

int	ft_left_c(char **strr, int wid, int hei)
{
	int	x;
	int	y;

	y = 0;
	while (y < hei)
	{
		x = 0;
		while (x < wid)
		{
			if (strr[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_exitmove(t_map *map, t_player *player, t_data *data)
{
	if (!ft_left_c(map->map, map->width, map->height))
	{
		mlx_loop_end(data->mlx);
		return ;
	}
	player->onexit = 1;
}

void	ft_move_up(t_data *data, t_player *player, int wx, int wy)
{
	if (!player->onexit)
		mlx_put_image_to_window(data->mlx, data->win, data->img->floor,
			(player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit,
			(player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	mlx_put_image_to_window(data->mlx, data->win, data->img->playerw,
		(player->x + (wx / 2)) * 40, (--player->y + (wy / 2)) * 40);
}

void	ft_move_left(t_data *data, t_player *player, int wx, int wy)
{
	if (!player->onexit)
		mlx_put_image_to_window(data->mlx, data->win, data->img->floor,
			(player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit,
			(player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	mlx_put_image_to_window(data->mlx, data->win, data->img->playera,
		(--player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
}
