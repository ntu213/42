/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:05:09 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/13 18:06:22 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strnstr(const char *src, const char *obj, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!src && !obj)
		return (0);
	if (!obj[0])
		return (0);
	while (n > i && src[i])
	{
		j = 0;
		while (n > i + j && src[i + j] && obj[j] == src[i + j])
		{
			j++;
			if (!obj[j])
				return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2, int freee)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j++])
		str[i + j - 1] = s2[j - 1];
	str[i + j - 1] = 0;
	if (freee == 1 || freee == 3)
		free(s1);
	if (freee == 2 || freee == 3)
		free(s2);
	return (str);
}

int	ft_strrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * sign);
}

char	*get_file(int fd)
{
	int		size;
	int		index;
	char	*res;
	char	*true_res;

	size = 15000;
	res = malloc(size + 1);
	index = read(fd, res, size);
	res[index] = 0;
	true_res = ft_strdup(res);
	free(res);
	return (true_res);
}

int	ft_lines(char **file, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < y)
	{
		while (file[j][i])
		{
			i++;
			if (i > x)
				return (0);
		}
		if (i < x)
			return (0);
		j++;
		i = 0;
	}
	if (j < 3 || x < 3 || (x * y) < 15)
		return (0);
	return (1);
}

int	ft_ok_char(char **file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[j])
	{
		while (file[j][i])
		{
			if (!(file[j][i] == '0' || file[j][i] == '1'
					|| file[j][i] == 'P' || file[j][i] == 'C'
					|| file[j][i] == 'E' || file[j][i] == 'M'
					|| file[j][i] == 'I'))
				return (0);
			i++;
		}
		j++;
		i = 0;
	}
	return (1);
}

int	ft_ok_border(char **file, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i])
	{
		if (i == 0 || i == y - 1)
		{
			while (file[i][j])
			{
				if (file[i][j] != '1')
					return (0);
				j++;
			}
		}
		if (file[i][0] != '1' || file[i][x - 1] != '1')
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

char	**ft_strrdup(char **strr, int size)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * (size + 1));
	while (strr[i])
	{
		new[i] = ft_strdup(strr[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	ft_char_type(char c, t_check *check, int x, int y)
{
	if (c == 'M')
		check->m++;
	else if (c == 'P')
	{
		check->pposx = x;
		check->pposy = y;
		check->p++;
	}
	else if (c == 'C')
		check->c++;
	else if (c == 'E')
		check->e++;
}

t_check	*ft_check_init(void)
{
	t_check	*new;

	new = malloc(sizeof(t_check));
	new->p = 0;
	new->m = 0;
	new->e = 0;
	new->c = 0;
	new->pposx = 0;
	new->pposy = 0;
	return (new);
}

int	ft_map_check(t_check *check, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_char_type(map[i][j], check, j, i);
			j++;
		}
		i++;
	}
	if (check->p != 1 || check->c < 1 || check->e != 1)
		return (0);
	return (1);
}

void	ft_ok_recursive(char **map, t_check *check, int x, int y)
{
	if (map[y][x] == '1')
		return ;
	else
		ft_char_type(map[y][x], check, x, y);
	map[y][x] = '1';
	if (map[y + 1])
		ft_ok_recursive(map, check, x, y + 1);
	if (y)
		ft_ok_recursive(map, check, x, y - 1);
	if (map[y][x + 1])
		ft_ok_recursive(map, check, x + 1, y);
	if (x)
		ft_ok_recursive(map, check, x - 1, y);
}

int	ft_check_compare(t_check *c1, t_check *c2)
{
	if (c1->c != c2->c || c1->e != c2->e || c1->p != c2->p)
		return (0);
	return (1);
}

int	ft_is_possible(char **map, int size, t_check *check)
{
	char	**dup;
	int		i;
	int		res;
	t_check	*check2;

	i = 0;
	res = 1;
	dup = ft_strrdup(map, size);
	check2 = ft_check_init();
	if (!ft_map_check(check, dup))
		res = 0;
	ft_ok_recursive(dup, check2, check->pposx, check->pposy);
	if (!ft_check_compare(check, check2))
		res = 0;
	while (dup[i])
	{
		free(dup[i]);
		i++;
	}
	free(dup);
	free(check2);
	return (res);
}

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

t_player	*ft_init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	player->x = 0;
	player->y = 0;
	player->hp = HP;
	player->sword = 0;
	player->score = 0;
	player->onexit = 0;
	return (player);
}

void	ft_reset_player(t_player *player, int x, int y)
{
	player->x = x;
	player->y = y;
	player->sword = 0;
	player->onexit = 0;
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
	new->player = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm",
		&useless1, &useless2);
	new->coll = mlx_xpm_file_to_image(data->mlx, "textures/collectible.xpm",
		&useless1, &useless2);
	new->exit = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm",
		&useless1, &useless2);
	new->mob = mlx_xpm_file_to_image(data->mlx, "textures/monster.xpm",
		&useless1, &useless2);
	return (new);
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
	data->win = mlx_new_window(data->mlx, data->max_width * 40,
			data->max_height * 40, "Spaghetti");
	data->img = ft_img_init(data);
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
	if (c == '1' || c == 'S')
	mlx_put_image_to_window(data->mlx, data->win, data->img->wall,
		j * 40, i * 40);
	else if (c == '0')
	mlx_put_image_to_window(data->mlx, data->win, data->img->floor,
		j * 40, i * 40);
	else if (c == 'P')
	mlx_put_image_to_window(data->mlx, data->win, data->img->player,
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

int	ft_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img->wall);
	mlx_destroy_image(data->mlx, data->img->floor);
	mlx_destroy_image(data->mlx, data->img->player);
	mlx_destroy_image(data->mlx, data->img->coll);
	mlx_destroy_image(data->mlx, data->img->exit);
	mlx_destroy_image(data->mlx, data->img->mob);
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
//	ft_printf("%d|%d\n", player->x, player->y);
	if (!player->onexit)
		mlx_put_image_to_window(data->mlx, data->win, data->img->floor, (player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit, (player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	mlx_put_image_to_window(data->mlx, data->win, data->img->player, (player->x + (wx / 2)) * 40, (--player->y + (wy / 2)) * 40);
}

void	ft_move_left(t_data *data, t_player *player, int wx, int wy)
{
//	ft_printf("%d|%d\n", player->x, player->y);
	if (!player->onexit)
		mlx_put_image_to_window(data->mlx, data->win, data->img->floor, (player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit, (player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	mlx_put_image_to_window(data->mlx, data->win, data->img->player, (--player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
}

void	ft_move_down(t_data *data, t_player *player, int wx, int wy)
{
//	ft_printf("%d|%d\n", player->x, player->y);
	if (!player->onexit)
		mlx_put_image_to_window(data->mlx, data->win, data->img->floor, (player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit, (player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	mlx_put_image_to_window(data->mlx, data->win, data->img->player, (player->x + (wx / 2)) * 40, (++player->y + (wy / 2)) * 40);
}

void	ft_move_right(t_data *data, t_player *player, int wx, int wy)
{
//	ft_printf("%d|%d\n", player->x, player->y);
	if (!player->onexit)
		mlx_put_image_to_window(data->mlx, data->win, data->img->floor, (player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img->exit, (player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
	mlx_put_image_to_window(data->mlx, data->win, data->img->player, (++player->x + (wx / 2)) * 40, (player->y + (wy / 2)) * 40);
}

void	ft_up(t_player *player, t_map *map, t_data *data, t_fstrct *fstrct)
{
	if (map->map[player->y][player->x] == '1'
		|| map->map[player->y][player->x] == 'C'
		|| map->map[player->y][player->x] == '0')
		player->onexit = 0;
	if (map->map[player->y - 1][player->x] == '1')
		return ;
	if (map->map[player->y - 1][player->x] == 'C')
		map->map[player->y - 1][player->x] = '0';
	ft_move_up(data, player, fstrct->wx, fstrct->wy);
	if (map->map[player->y][player->x] == 'E')
		ft_exitmove(map, player, data);
	player->score++;
}

void	ft_left(t_player *player, t_map *map, t_data *data, t_fstrct *fstrct)
{
	if (map->map[player->y][player->x] == '1'
		|| map->map[player->y][player->x] == 'C'
		|| map->map[player->y][player->x] == '0')
		player->onexit = 0;
	if (map->map[player->y][player->x - 1] == '1')
		return ;
	if (map->map[player->y][player->x - 1] == 'C')
		map->map[player->y][player->x - 1] = '0';
	ft_move_left(data, player, fstrct->wx, fstrct->wy);
	if (map->map[player->y][player->x] == 'E')
		ft_exitmove(map, player, data);
	player->score++;
}

void	ft_down(t_player *player, t_map *map, t_data *data, t_fstrct *fstrct)
{
	if (map->map[player->y][player->x] == '1'
		|| map->map[player->y][player->x] == 'C'
		|| map->map[player->y][player->x] == '0')
		player->onexit = 0;
	if (map->map[player->y + 1][player->x] == '1')
		return ;
	if (map->map[player->y + 1][player->x] == 'C')
		map->map[player->y + 1][player->x] = '0';
	ft_move_down(data, player, fstrct->wx, fstrct->wy);
	if (map->map[player->y][player->x] == 'E')
		ft_exitmove(map, player, data);
	player->score++;
}

void	ft_right(t_player *player, t_map *map, t_data *data, t_fstrct *fstrct)
{
	if (map->map[player->y][player->x] == '1'
		|| map->map[player->y][player->x] == 'C'
		|| map->map[player->y][player->x] == '0')
		player->onexit = 0;
	if (map->map[player->y][player->x + 1] == '1')
		return ;
	if (map->map[player->y][player->x + 1] == 'C')
		map->map[player->y][player->x + 1] = '0';
	ft_move_right(data, player, fstrct->wx, fstrct->wy);
	if (map->map[player->y][player->x] == 'E')
		ft_exitmove(map, player, data);
	player->score++;
}

int	ft_controls(int key, t_fstrct *fstrct)
{
	t_data		*data;
	t_map		*map;
	t_player	*player;

	data = fstrct->data;
	map = fstrct->map;
	player = fstrct->player;
	if (key == 65307)
		ft_destroy(fstrct->data);
	else if (key == 119)
		ft_up(player, map, data, fstrct);
	else if (key == 97)
		ft_left(player, map, data, fstrct);
	else if (key == 115)
		ft_down(player, map, data, fstrct);
	else if (key == 100)
		ft_right(player, map, data, fstrct);
}
