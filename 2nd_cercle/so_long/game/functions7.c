/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:17:07 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/17 10:17:16 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_down(t_player *player, t_map *map, t_data *data, t_fstrct *fstrct)
{
	if (map->map[player->y][player->x] != 'E')
		player->onexit = 0;
	if (map->map[player->y + 1][player->x] == '1')
		return ;
	player->score++;
	if (map->map[player->y + 1][player->x] == 'S')
		ft_godmode(player, data);
	if (map->map[player->y + 1][player->x] == 'C')
		map->map[player->y + 1][player->x] = '0';
	ft_move_down(data, player, fstrct->wx, fstrct->wy);
	if (map->map[player->y][player->x] == 'E')
		ft_exitmove(map, player, data);
}

void	ft_right(t_player *player, t_map *map, t_data *data, t_fstrct *fstrct)
{
	if (map->map[player->y][player->x] != 'E')
		player->onexit = 0;
	if (map->map[player->y][player->x + 1] == '1')
		return ;
	player->score++;
	if (map->map[player->y][player->x + 1] == 'S')
		ft_godmode(player, data);
	if (map->map[player->y][player->x + 1] == 'C')
		map->map[player->y][player->x + 1] = '0';
	ft_move_right(data, player, fstrct->wx, fstrct->wy);
	if (map->map[player->y][player->x] == 'E')
		ft_exitmove(map, player, data);
}

int	ft_exit(t_data *data)
{
	data->hasexit = 1;
	mlx_loop_end(data->mlx);
	return (1);
}

int	ft_intlen(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n /= 10;
	}
	if (!i)
		i = 1;
	return (i);
}

void	ft_print_hp(t_data *data, t_player *player)
{
	int	i;

	i = 0;
	while (i < data->max_width - player->hp)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->wall,
			i * 40, 0);
		i++;
	}
	while (i < data->max_width)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->hp,
			i * 40, 0);
		i++;
	}
}
