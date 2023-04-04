/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:41:15 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/04 18:41:32 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapmaker.h"

char **strrdup(char **strr, int size)
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
	while (i < hei - 2)
	{
		j = 1;
		while (j < wid - 2)
		{
			if (strr[i][j] == 'C')
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

void	ft_recursive(char **strr, int x, int y, int *res)
{
	if (strr[y][x] == '1' || strr[y][x] == 'E' || strr[y][x] == 'P')
		return ;
	if (strr[y][x] == 'C')
		(*res)++;
	ft_recursive(strr, x + 1, y, res);
	ft_recursive(strr, x - 1, y, res);
	ft_recursive(strr, x, y + 1, res);
	ft_recursive(strr, x, y - 1, res);
}

char	**ft_build_walls(char **strr, int wid, int hei)
{
	int	i;
	int	j;
	int	left;
	int	count;

	i = 1;
	count = 0;
	left = 1;
	while (i < hei - 2 || left)
	{
		j = 1;
		while (j < wid - 2 || left)
		{
			if (ft_place_wall(strr, i, j)) //strr[i][j] != 'P' && strr[i][j] != 'E' && ft_random(100 - count, i * j * SEED) < CDENSITY
			{
				strr[i][j] = '1';
				left = 0;
			}
			else
				count = new_count(count);
			j++;
		}
		i++;
	}
	return (strr);
}

char	**ft_make_walls(char **strr, int wid, int hei)
{
	char	**new;
	int		i;
	int		res;

	res = 0;
	new = ft_build_walls(strrdup(strr, hei), wid, hei);
	ft_recursive(new, 1, 1, &res);
	while (total_items(new, wid, hei) == res)
	{
		i = 0;
		res = 0;
		ft_recursive(new, ft_ppos(strr) / wid, ft_ppos(strr) % wid, &res);
		while (i < hei)
			free(strr[i++]);
		free(strr);
		strr = new;
		new = ft_build_walls(strrdup(strr, hei), wid, hei);
	}
	i = 0;
	while (i < hei)
		free(new[i++]);
	free(new);
	return (strr);
}
