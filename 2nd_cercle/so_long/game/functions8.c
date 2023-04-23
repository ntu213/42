/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:18:35 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/17 10:19:26 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_hp_score(t_data *data, t_player *player, int score)
{
	char	*str;
	int		posx;

	str = ft_itoa(score);
	ft_print_hp(data, player);
	mlx_string_put(data->mlx, data->win, 5, 18, 0x00FFFFFF, "Score:");
	posx = 20 - ((ft_intlen(score) * 5) / 2);
	mlx_string_put(data->mlx, data->win, posx, 32, 0x00FFFFFF, str);
	free(str);
}

void	ft_is_on_mob(t_player *player, t_data *data, t_mob **mobtab,
	int mcount)
{
	int	i;

	i = 0;
	while (i < mcount)
	{
		if (mobtab[i]->alive == 1 && mobtab[i]->x == player->x
			&& mobtab[i]->y == player->y && !player->sword)
			player->hp--;
		else if (mobtab[i]->alive == 1 && mobtab[i]->x == player->x
			&& mobtab[i]->y == player->y)
			mobtab[i]->alive = 0;
		i++;
	}
	if (player->hp < 1)
		mlx_loop_end(data->mlx);
}

int	ft_can_mob_move(int x, int y, t_map *map)
{
	if (map->map[y][x] == '1'
		|| map->map[y][x] == 'I'
		|| map->map[y][x] == 'C'
		|| map->map[y][x] == 'E'
		|| map->map[y][x] == 'S')
		return (0);
	return (1);
}

int	ft_random(int n, unsigned long int next)
{
	int	res;

	if (!n)
		n = 10;
	if (!next)
		next = 1132045;
	next = next * 1103515245 + (n + (next / 5) / (50 * 7))
		* (next % 957473) + 1;
	if (next <= 0)
		next = (next % 957473) + 1;
	res = (next / 65536) % n;
	return (res);
}

void	ft_replace_mobs(t_mob *mob, t_fstrct *fstrct, int x, int y)
{
	mlx_put_image_to_window(fstrct->data->mlx, fstrct->data->win,
		fstrct->data->img->floor,
		((fstrct->wx / 2) + mob->x) * 40, ((fstrct->wy / 2) + mob->y) * 40);
	mob->x = x;
	mob->y = y;
	mlx_put_image_to_window(fstrct->data->mlx, fstrct->data->win,
		fstrct->data->img->mob,
		((fstrct->wx / 2) + mob->x) * 40, ((fstrct->wy / 2) + mob->y) * 40);
}
