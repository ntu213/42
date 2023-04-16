/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_walls_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:43:25 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/14 10:36:04 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapmaker.h"

char	**ft_strrdup(char **strr, int size)
{
	int		i;
	char	**new;

	i = 0;
	new = malloc(sizeof(char *) * size);
	while (i < size)
	{
		new[i] = ft_strdup(strr[i]);
		i++;
	}
	return (new);
}

int	total_items(char **strr, int wid, int hei)
{
	int	i;
	int	j;
	int	res;

	i = 1;
	res = 0;
	while (i < hei - 1)
	{
		j = 1;
		while (j < wid - 1)
		{
			if (strr[i][j] == 'C' || strr[i][j] == 'E')
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

int	is_side_wall(char **strr, int y, int x)
{
	if (strr[y + 1][x] == '1'
		|| strr[y - 1][x] == '1'
		|| strr[y][x + 1] == '1'
		|| strr[y][x - 1] == '1')
		return (1);
	return (0);
}

int	ft_place_wall(char **strr, int y, int x)
{
	int			res;
	static int	wplacer = 0;

	if (strr[y][x] == 'P' || strr[y][x] == 'E' || strr[y][x] == '1'
		|| strr[y][x] == 'C')
		return (0);
	if (is_side_wall(strr, y, x))
		res = ft_random(WSIDE, ft_randomadr(x * y + SEED + wplacer));
	else
		res = ft_random(100, ft_randomadr(x * y + SEED + wplacer));
	if (res < WDENSITY)
		return (1);
	return (0);
}

void	ft_recursive(char **strr, int x, int y, int *res)
{
	if (strr[y][x] == '1' || strr[y][x] == 'P' || !strr[y][x])
		return ;
	if (strr[y][x] == 'C' || strr[y][x] == 'E')
		(*res)++;
	strr[y][x] = '1';
	ft_recursive(strr, x + 1, y, res);
	ft_recursive(strr, x - 1, y, res);
	ft_recursive(strr, x, y + 1, res);
	ft_recursive(strr, x, y - 1, res);
}
