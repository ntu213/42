/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:21:07 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/17 10:22:43 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_direction(t_mob *mob, t_fstrct *fstrct, int n)
{
	if (n == 0 && ft_can_mob_move(mob->x, mob->y + 1, fstrct->map))
		ft_replace_mobs(mob, fstrct, mob->x, mob->y + 1);
	else if (n == 1 && ft_can_mob_move(mob->x, mob->y - 1, fstrct->map))
		ft_replace_mobs(mob, fstrct, mob->x, mob->y - 1);
	else if (n == 2 && ft_can_mob_move(mob->x + 1, mob->y, fstrct->map))
		ft_replace_mobs(mob, fstrct, mob->x + 1, mob->y);
	else if (n == 3 && ft_can_mob_move(mob->x - 1, mob->y, fstrct->map))
		ft_replace_mobs(mob, fstrct, mob->x - 1, mob->y);
	else
		ft_replace_mobs(mob, fstrct, mob->x, mob->y);
}

void	ft_rewrite_mobs(t_fstrct *fstrct, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (fstrct->mobs[i]->alive)
			ft_replace_mobs(fstrct->mobs[i], fstrct, fstrct->mobs[i]->x,
				fstrct->mobs[i]->y);
		i++;
	}
}

void	ft_mobs_move(t_fstrct *fstrct, t_mob **mobtab, int py)
{
	int	i;
	int	n;

	i = 0;
	while (i < fstrct->mcount)
	{
		if (mobtab[i]->alive)
		{
			n = ft_random(4, mobtab[i]->x + mobtab[i]->y * fstrct->mcount * py);
			ft_direction(mobtab[i], fstrct, n);
		}
		i++;
	}
	ft_is_on_mob(fstrct->player, fstrct->data, fstrct->mobs, fstrct->mcount);
}

int	ft_controls(int key, t_fstrct *fstrct)
{
	t_data		*data;
	t_map		*map;
	t_player	*player;

	data = fstrct->data;
	map = fstrct->map;
	player = fstrct->player;
	if (key == 119 || key == 65362 || key == 97 || key == 65361
		|| key == 115 || key == 65364 || key == 100 || key == 65363)
		ft_mobs_move(fstrct, fstrct->mobs, player->y);
	if (key == 65307)
		ft_exit(fstrct->data);
	else if (key == 119 || key == 65362)
		ft_up(player, map, data, fstrct);
	else if (key == 97 || key == 65361)
		ft_left(player, map, data, fstrct);
	else if (key == 115 || key == 65364)
		ft_down(player, map, data, fstrct);
	else if (key == 100 || key == 65363)
		ft_right(player, map, data, fstrct);
	ft_is_on_mob(player, data, fstrct->mobs, fstrct->mcount);
	ft_print_hp_score(data, player, player->score);
	ft_rewrite_mobs(fstrct, fstrct->mcount);
	return (0);
}

int	ft_mobs_count(t_map *map)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'M')
				n++;
			j++;
		}
		i++;
	}
	return (n);
}
