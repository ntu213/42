/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:14:23 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/17 10:14:31 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_down(t_data *data, t_player *player, int wx, int wy)
{
	if (!player->onexit)
		mlx_put_image_to_window(data->mlx, data->win, data->img->floor,
			(player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit,
			(player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	mlx_put_image_to_window(data->mlx, data->win, data->img->players,
		(player->x + (wx / 2)) * 40, (++player->y + (wy / 2)) * 40);
}

void	ft_move_right(t_data *data, t_player *player, int wx, int wy)
{
	if (!player->onexit)
		mlx_put_image_to_window(data->mlx, data->win, data->img->floor,
			(player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit,
			(player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	mlx_put_image_to_window(data->mlx, data->win, data->img->playerd,
		(++player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
}

void	ft_godmode(t_player *player, t_data *data)
{
	int	useless1;
	int	useless2;

	player->sword = 1;
	mlx_destroy_image(data->mlx, data->img->playerd);
	mlx_destroy_image(data->mlx, data->img->playera);
	data->img->playerd = mlx_xpm_file_to_image(data->mlx,
			"textures/playerd2.xpm", &useless1, &useless2);
	data->img->playera = mlx_xpm_file_to_image(data->mlx,
			"textures/playera2.xpm", &useless1, &useless2);
}

void	ft_up(t_player *player, t_map *map, t_data *data, t_fstrct *fstrct)
{
	if (map->map[player->y][player->x] != 'E')
		player->onexit = 0;
	if (map->map[player->y - 1][player->x] == '1')
		return ;
	player->score++;
	if (map->map[player->y - 1][player->x] == 'S')
		ft_godmode(player, data);
	if (map->map[player->y - 1][player->x] == 'C')
		map->map[player->y - 1][player->x] = '0';
	ft_move_up(data, player, fstrct->wx, fstrct->wy);
	if (map->map[player->y][player->x] == 'E')
		ft_exitmove(map, player, data);
}

void	ft_left(t_player *player, t_map *map, t_data *data, t_fstrct *fstrct)
{
	if (map->map[player->y][player->x] != 'E')
		player->onexit = 0;
	if (map->map[player->y][player->x - 1] == '1')
		return ;
	player->score++;
	if (map->map[player->y][player->x - 1] == 'S')
		ft_godmode(player, data);
	if (map->map[player->y][player->x - 1] == 'C')
		map->map[player->y][player->x - 1] = '0';
	ft_move_left(data, player, fstrct->wx, fstrct->wy);
	if (map->map[player->y][player->x] == 'E')
		ft_exitmove(map, player, data);
}
