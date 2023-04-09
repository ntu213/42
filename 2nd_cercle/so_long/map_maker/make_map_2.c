/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 19:49:49 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/08 19:51:33 by vgiraudo         ###   ########.fr       */
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

int	ft_get_player(char **strr, int wid, int hei)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = ft_random((wid - 1) * (hei - 1), SEED * SEED - 5);
	while (i < hei - 1 && count)
	{
		j = 1;
		i++;
		while (j < wid - 1 && count)
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
		count--;
	}
	if (strr[y][x] == 'P')
		ft_new_loc_e(strr, y, x);
	else
		strr[y][x] = 'E';
	return (1);
}

int	new_count(int count)
{
	count++;
	if (count > CDENSITY / 10)
		count = CDENSITY / 10;
	return (count);
}
