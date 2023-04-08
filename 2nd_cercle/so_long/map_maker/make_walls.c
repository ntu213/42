/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:41:15 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/08 17:48:04 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapmaker.h"

char **ft_strrdup(char **strr, int size)
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

	if (strr[y][x] == 'P' || strr[y][x] == 'E' || strr[y][x] == '1' || strr[y][x] == 'C')
		return (0);
	if (is_side_wall(strr, y, x))
		res = ft_random(50, ft_randomadr(x * y + SEED + wplacer));
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

char	**ft_build_walls(char **strr, int wid, int hei)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < hei - 1 && WDENSITY)
	{
		j = 1;
		while (j < wid - 1)
		{
			if (ft_place_wall(strr, i, j))
			{
				strr[i][j] = '1';
			}
			else
				count = new_count(count);
			j++;
		}
		i++;
	}
	return (strr);
}

int	ft_ppos(char **strr, int wid, int hei)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (strr[j][i] != 'P' && i < hei - 1)
	{
		i++;
		j = 1;
		while (strr[j][i] != 'P' && strr[j][i] != '1' && j < wid - 1)
		{
			j++;
		}
	}
	return ((j * wid) + i);
}

char	**ft_is_recursive(char **strr, int pos, int wid, int *res)
{
	int		y;
	int		x;

	x = pos / wid;
	y = pos % wid;
	ft_recursive(strr, x, y, res);
	return (strr);
}

void	ft_strrfree(char **strr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(strr[i++]);
	free(strr);
}

char	**ft_make_walls(char **strr, int wid, int hei)
{
	char	**new;
	int		res;
	int		shuffle;

	res = 0;
	shuffle = 0;
	new = ft_build_walls(ft_strrdup(strr, hei), wid, hei);
	ft_strrfree(ft_is_recursive(ft_strrdup(new, hei), 3, 2, &res), hei);
	while (total_items(new, wid, hei) == res && shuffle < WDENSITY * 10)
	{
		res = 0;
		ft_is_recursive(ft_strrdup(new, hei), ft_ppos(strr, wid, hei), wid, &res);
		ft_strrfree(strr, hei);
		strr = new;
		new = ft_build_walls(ft_strrdup(strr, hei), wid, hei);
		shuffle++;
	}
	ft_strrfree(new, hei);
	return (strr);
}
//1431679776