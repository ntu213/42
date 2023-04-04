/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:14:26 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/04 14:36:27 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapmaker.h"

char	*ft_line(int size, char c)
{
	int		i;
	char	*res;

	i = 1;
	res = malloc(size + 1);
	res[0] = '1';
	res[size - 1] = '1';
	res[size] = '\0';
	while (i < size - 1)
	{
		res[i] = c;
		i++;
	}
	return (res);
}

int	ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	ft_get_player(char **strr, int wid, int hei)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = ft_random((wid - 1) * (hei - 1), SEED * SEED - 5);
	while (i < hei - 2 && count)
	{
		j = 1;
		i++;
		while (j < wid - 2 && count)
		{
			j++;
			count--;
		}
	}
	strr[i][j] = 'P';
	return (i * wid + j);
}

void	ft_new_loc_e(char **strr, int y, int x)
{
	if (strr[y + 1][x] != 'P' && strr[y + 1][x] != '1')
		strr[y + 1][x] = 'E';
	else if (strr[y - 1][x] != 'P' && strr[y - 1][x] != '1')
		strr[y - 1][x] = 'E';
	else if (strr[y][x + 1] != 'P' && strr[y][x + 1] != '1')
		strr[y][x + 1] = 'E';
	else if (strr[y][x - 1] != 'P' && strr[y][x - 1] != '1')
		strr[y][x - 1] = 'E';
	else
		exit(ft_argerror(0, "Error while placing the Exit"));
}

int	ft_build_path(char **strr, int y, int x, int rdm)
{
	int	goal;
	int	count;

	count = ft_random((x * y) * 5, SEED * SEED);
	goal = 1;
	while (count)
	{
		goal = ft_random(4, SEED * rdm + count * y * x);
		rdm = ft_random(10000, SEED * goal + count * y * x);
		if (goal == 0 && strr[y + 1][x] != '1' && strr[y + 1][x] != 'P')
			y++;
		else if (goal == 1 && strr[y - 1][x] != '1' && strr[y - 1][x] != 'P')
			y--;
		else if (goal == 2 && strr[y][x + 1] != '1' && strr[y][x + 1] != 'P')
			x++;
		else if (goal == 3 && strr[y][x - 1] != '1' && strr[y][x - 1] != 'P')
			x--;
		if (strr[y][x] != 'P')
			strr[y][x] = '2';
		count--;
	}
	if (strr[y][x] == 'P')
		ft_new_loc_e(strr, y, x);
	else
		strr[y][x] = 'E';
	return (1);
}

int	ft_crandom(int wid, int hei)
{
	int	left;

	left = ft_random(((wid * hei) * CDENSITY) / 100 + 1, wid * hei * SEED);
	if (!left)
		left = 1;
	return (left);
}

void	ft_put_c(char **strr, int wid, int hei)
{
	int	i;
	int	j;
	int	left;
	int	count;

	i = 1;
	count = 0;
	left = ft_crandom(wid, hei);
	while (left)
	{
		if (i >= hei - 2)
			i = 1;
		j = 1;
		while (j < wid - 2 && left)
		{
			if (strr[i][j] != 'P' && strr[i][j] != 'E'
				&& ft_random(1000 - count, i * j * SEED) < CDENSITY)
			{
				strr[i][j] = 'C';
				left--;
			}
			else
				count++;
			j++;
		}
		i++;
	}
}

void	ft_get_path(char **strr, int wid, int hei)
{
	int	p_pos;

	p_pos = ft_get_player(strr, wid, hei);
	ft_build_path(strr, p_pos / wid, p_pos % wid, wid * hei / 3);
	ft_put_c(strr, wid, hei);
}

char	**make_map(int wid, int hei)
{
	char	**res;
	int		i;

	i = 1;
	res = malloc(sizeof(char *) * hei);
	res[0] = ft_line(wid, '1');
	res[hei - 1] = ft_line(wid, '1');
	while (i < hei - 1)
	{
		res[i] = ft_line(wid, '0');
		i++;
	}
	ft_get_path(res, wid, hei);
	return (res);
}
