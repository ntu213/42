/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:53:48 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/17 10:02:17 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_third(t_player *player, t_map *map, t_data *data)
{
	t_fstrct	fstrct;
	t_mob		**mobtab;
	int			mcount;

	fstrct.wx = data->max_width - map->width;
	fstrct.wy = data->max_height - map->height;
	fstrct.data = data;
	fstrct.player = player;
	fstrct.map = map;
	ft_reset_map(data);
	mlx_hook(data->win, 17, 1L << 0, ft_exit, data);
	mlx_hook(data->win, 2, 1L << 0, ft_controls, &fstrct);
	ft_place_map(data, map, fstrct.wx, fstrct.wy);
	ft_print_hp_score(data, player, player->score);
	mobtab = ft_place_mobs(map, &mcount);
	fstrct.mobs = mobtab;
	fstrct.mcount = mcount;
	mlx_loop(data->mlx);
	ft_free_mobs(mobtab, mcount);
}

int	ft_get_level_count(t_map **map, int n)
{
	int	i;

	i = 0;
	while (n)
	{
		if (map[--n]->ok)
			i++;
	}
	return (i);
}

int	ft_true_hasexit(t_data *data, t_map **str, t_player *player, int i)
{
	if (ft_hasexit(data->hasexit, player->score, "",
			ft_get_level_count(str, i)))
		return (1);
	else if (str[i]->ok && player->hp > 0)
		ft_hasexit(2, player->score, str[i]->name, ft_get_level_count(str, i));
	else if (str[i]->ok)
		ft_hasexit(3, player->score, str[i]->name, ft_get_level_count(str, i));
	return (0);
}

void	ft_second(t_map **str, t_check **check, int j)
{
	t_player	*player;
	t_data		*data;
	int			i;

	i = 0;
	data = ft_init_data(str, j);
	data->hasexit = 0;
	player = ft_init_player(data->max_width);
	while (i < j && data->max_height && data->max_width && player->hp > 0)
	{
		if (str[i]->width > 96 || str[i]->height >= 54)
			ft_printf("[\e[0;33mWarning\e[0;37m] %s: Big map\n", str[i]->name);
		ft_reset_player(data, player, check[i]->pposx, check[i]->pposy);
		if (str[i]->ok)
			ft_third(player, str[i], data);
		if (ft_true_hasexit(data, str, player, i))
			break ;
		i++;
	}
	ft_clear_check(check, j);
	ft_destroy(data);
	ft_end_sec(data, player);
}

void	ft_first(t_map **str, int j)
{
	t_check		**check;
	int			i;

	i = 0;
	check = malloc(sizeof(t_check *) * j);
	while (i < j)
	{
		check[i] = ft_check_init();
		if (!ft_ok_file(str[i], check[i]))
			ft_printf("[\e[0;31mError\e[0;37m] %s: Invalid map format\n",
				str[i]->name);
		else
			str[i]->ok = 1;
		i++;
	}
	ft_second(str, check, j);
}
