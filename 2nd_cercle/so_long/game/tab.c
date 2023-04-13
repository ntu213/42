/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:53:48 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/13 19:17:59 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*

	void	*mlx;
	void	*win;
	void	*win2;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	win2 = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	(void)win;
	(void)win2;
*/

void	*ft_third(t_player *player, t_map *map, t_data *data)
{
	t_fstrct	fstrct;

	fstrct.wx = data->max_width - map->width;
	fstrct.wy = data->max_height - map->height;
	fstrct.data = data;
	fstrct.player = player;
	fstrct.map = map;
	ft_reset_map(data);
	mlx_hook(data->win, 17, 1L << 0, ft_destroy, data);
	mlx_hook(data->win, 2, 1L << 0, ft_controls, &fstrct);
	ft_place_map(data, map, fstrct.wx, fstrct.wy);

	mlx_loop(data->mlx);
}

void	ft_end_sec(t_data *data, t_player *player)
{
	if (!data->hasexit)
		ft_printf("\e[4;1;34mGame ended, GG!\e[0;37m\n");
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	free(player);
}

int	ft_hasexit(int n, int score, char *name, int i)
{
	if (!n)
		return (0);
	else if (n == 1)
		ft_printf("[\e[0;31mGame Exit\e[0;37m] Total Score: %d\n", score);
	else if (n == 2)
		ft_printf("[\e[0;32mWin\e[0;37m] Level %d: %s %s of %d\n", i + 1,
			name, "finished with a total score", score);
	return (1);
}

void	ft_clear_check(t_check **check, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(check[i++]);
	free(check);
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

void	*ft_second(t_map **str, t_check **check, int j)
{
	t_player	*player;
	t_data		*data;
	int	i;

	i = 0;
	data = ft_init_data(str, j);
	data->hasexit = 0;
	player = ft_init_player();
	while (i < j)
	{
		if (str[i]->width > 96 || str[i]->height >= 54)
			ft_printf("[\e[0;33mWarning\e[0;37m] %s: Big map\n", str[i]->name);
		ft_reset_player(player, check[i]->pposx, check[i]->pposy);
		if (str[i]->ok)
			ft_third(player, str[i], data);
		if (ft_hasexit(data->hasexit, player->score, "", ft_get_level_count(str, i)))
			break ;
		else if (str[i]->ok)
			ft_hasexit(2, player->score, str[i]->name, ft_get_level_count(str, i));
		i++;
	}
	ft_clear_check(check, j);
	if (!data->hasexit)
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
