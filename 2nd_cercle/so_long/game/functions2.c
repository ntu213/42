/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:07:13 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/17 10:07:39 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
