/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:53:48 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/27 13:19:08 by vgiraudo         ###   ########.fr       */
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
	
}

void	*ft_second(t_map **str, t_check *check, int j)
{
	t_player	*player;
	t_data		*data;
	int	i;

	i = 0;
	data = ft_init_data(str, j);
	while (i < j)
	{
		if (str[i]->width > 96 || str[i]->height >= 54)
			ft_printf("[Warning] %s: Big map\n", str[i]->name);
		player = ft_init_player(check->pposx, check->pposy, 0);
		ft_third(player, str[i], data);
		free(player);
		i++;
ft_printf("%s: (temp) File OK\n", str[i]->name);
	}
}

void	ft_first(t_map **str, int j)
{
	t_check		*check;
	int			i;

	i = 0;
	ft_printf("%d\n", j);
	while (i < j)
	{
		check = ft_check_init();
		if (!ft_ok_file(str[i], check))
			ft_printf("[Error] %s: Invalid file format\n", str[i]->name);
		else
			str[i]->ok = 1;
		i++;
		free(check);
	}
	ft_second(str, check, j);
}
