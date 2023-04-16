/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:05:09 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/16 19:12:56 by vgiraudo         ###   ########.fr       */
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
					|| file[j][i] == 'I' || file[j][i] == 'S'))
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

void	ft_new_win(t_data *data)
{
	if (data->max_height != 0 && data->max_width != 0)
		data->win = mlx_new_window(data->mlx, data->max_width * 40,
			data->max_height * 40, "Spaghetti");
	else
		data->win = mlx_new_window(data->mlx, 400,
			400, "Spaghetti");
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
	data->img = ft_img_init(data);
	
	ft_new_win(data);
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
	if (c == '1' || c == 'I')
		mlx_put_image_to_window(data->mlx, data->win, data->img->wall,
		j * 40, i * 40);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img->floor,
		j * 40, i * 40);
	else if (c == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img->playerd,
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
	else if (c == 'S')
		mlx_put_image_to_window(data->mlx, data->win, data->img->weapon,
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
	data->img->playerd = mlx_xpm_file_to_image(data->mlx, "textures/playerd2.xpm",
		&useless1, &useless2);
	data->img->playera = mlx_xpm_file_to_image(data->mlx, "textures/playera2.xpm",
		&useless1, &useless2);
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
		mlx_put_image_to_window(data->mlx, data->win, data->img->wall, i * 40, 0);
		i++;
	}
	while (i < data->max_width)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img->hp, i * 40, 0);
		i++;
	}
}

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

void	ft_is_on_mob(t_player *player, t_data *data, t_mob **mobtab, int mcount)
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

void	ft_replace_mobs(t_data *data, t_mob *mob, t_fstrct *fstrct, int x,
	int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img->floor,
		((fstrct->wx / 2) + mob->x) * 40, ((fstrct->wy / 2) + mob->y) * 40);
	mob->x = x;
	mob->y = y;
	mlx_put_image_to_window(data->mlx, data->win, data->img->mob,
		((fstrct->wx / 2) + mob->x) * 40, ((fstrct->wy / 2) + mob->y) * 40);
}

void	ft_direction(t_mob *mob, t_fstrct *fstrct, int n)
{
	if (n == 0 && ft_can_mob_move(mob->x, mob->y + 1, fstrct->map))
		ft_replace_mobs(fstrct->data, mob, fstrct, mob->x, mob->y + 1);
	else if (n == 1 && ft_can_mob_move(mob->x, mob->y - 1, fstrct->map))
		ft_replace_mobs(fstrct->data, mob, fstrct, mob->x, mob->y - 1);
	else if (n == 2 && ft_can_mob_move(mob->x + 1, mob->y, fstrct->map))
		ft_replace_mobs(fstrct->data, mob, fstrct, mob->x + 1, mob->y);
	else if (n == 3 && ft_can_mob_move(mob->x - 1, mob->y, fstrct->map))
		ft_replace_mobs(fstrct->data, mob, fstrct, mob->x - 1, mob->y);
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

t_mob	*ft_init_mob(int i, int j)
{
	t_mob	*new;

	new = malloc(sizeof(t_mob));
	new->x = j;
	new->y = i;
	new->alive = 1;
	return (new);
}

t_mob	**ft_place_mobs(t_map *map, int *n)
{
	int		i;
	int		j;
	int		count;
	t_mob	**mobs;

	*n = ft_mobs_count(map);
	i = 0;
	count = 0;
	mobs = malloc(sizeof(t_mob *) * *n);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] == 'M')
				mobs[count++] = ft_init_mob(i, j);
			j++;
		}
		i++;
	}
	return (mobs);
}

void	ft_free_mobs(t_mob **tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(tab[i++]);
	free(tab);
}
