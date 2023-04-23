/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:09:05 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/17 15:27:54 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_ok_file(t_map *obj, t_check *check)
{
	char	*file;

	file = get_file(obj->fd);
	obj->map = ft_split(file, '\n');
	free(file);
	obj->height = ft_strrlen(obj->map);
	obj->width = ft_strlen(obj->map[0]);
	if (!ft_lines(obj->map, obj->width, obj->height) || !ft_ok_char(obj->map))
		return (0);
	if (!ft_ok_border(obj->map, obj->width, obj->height))
		return (0);
	if (!ft_is_possible(obj->map, obj->height, check))
		return (0);
	return (1);
}

t_player	*ft_init_player(int n)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->x = 0;
	player->y = 0;
	if (HP <= n - 1)
		player->hp = HP;
	else
		player->hp = n - 1;
	player->sword = 0;
	player->score = 0;
	player->onexit = 0;
	return (player);
}

void	ft_reset_player(t_data *data, t_player *player, int x, int y)
{
	int	useless1;
	int	useless2;

	player->x = x;
	player->y = y;
	player->sword = 0;
	player->onexit = 0;
	mlx_destroy_image(data->mlx, data->img->playerd);
	mlx_destroy_image(data->mlx, data->img->playera);
	data->img->playerd = mlx_xpm_file_to_image(data->mlx,
			"textures/playerd.xpm", &useless1, &useless2);
	data->img->playera = mlx_xpm_file_to_image(data->mlx,
			"textures/playera.xpm", &useless1, &useless2);
}

void	ft_img_init_2(t_imgg *new, t_data *data, int n1, int n2)
{
	new->weapon = mlx_xpm_file_to_image(data->mlx, "textures/weapon.xpm",
			&n1, &n2);
	new->hp = mlx_xpm_file_to_image(data->mlx, "textures/hp.xpm",
			&n1, &n2);
}

t_imgg	*ft_img_init(t_data *data)
{
	t_imgg	*new;
	int		useless1;
	int		useless2;

	new = malloc(sizeof(t_imgg));
	new->wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm",
			&useless1, &useless2);
	new->floor = mlx_xpm_file_to_image(data->mlx, "textures/floor.xpm",
			&useless1, &useless2);
	new->playerw = mlx_xpm_file_to_image(data->mlx, "textures/playerw.xpm",
			&useless1, &useless2);
	new->playera = mlx_xpm_file_to_image(data->mlx, "textures/playera.xpm",
			&useless1, &useless2);
	new->players = mlx_xpm_file_to_image(data->mlx, "textures/players.xpm",
			&useless1, &useless2);
	new->playerd = mlx_xpm_file_to_image(data->mlx, "textures/playerd.xpm",
			&useless1, &useless2);
	new->coll = mlx_xpm_file_to_image(data->mlx, "textures/collectible.xpm",
			&useless1, &useless2);
	new->exit = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm",
			&useless1, &useless2);
	new->mob = mlx_xpm_file_to_image(data->mlx, "textures/monster.xpm",
			&useless1, &useless2);
	ft_img_init_2(new, data, useless1, useless2);
	return (new);
}
