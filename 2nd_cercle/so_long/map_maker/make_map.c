/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:14:26 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/08 19:51:36 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapmaker.h"

void	ft_put_c(char **strr, int wid, int hei)
{
	int	i;
	int	j;
	int	left;
	int	count;

	i = 1;
	count = 0;
	left = 1;
	while (i < hei - 1 || left)
	{
		j = 1;
		while (j < wid - 1 || left)
		{
			if (strr[i][j] != 'P' && strr[i][j] != 'E'
				&& ft_random(100 - count, i * j * SEED) < CDENSITY)
			{
				strr[i][j] = 'C';
				left = 0;
			}
			else
				count = new_count(count);
			j++;
		}
		i++;
	}
}

char	**ft_place_mob(char **strr, int wid, int hei, int n)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	len = ft_random(wid * hei, wid * hei * n + 5);
	while (i < hei - 1 && len)
	{
		j = 1;
		while (j < wid - 1 && len)
		{
			if (strr[i][j] == '0')
				len--;
			j++;
		}
		i++;
	}
	if (i > 1)
		i--;
	if (j > 1)
		j--;
	strr[i][j] = 'M';
	return (strr);
}

void	ft_put_solo_c(char **strr, int wid, int hei)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (strr[i][j] != '0' && i < hei - 1)
	{
		j = 1;
		while (strr[i][j] != '0' && j < wid - 1)
			j++;
		i++;
	}
	if (i != 1)
		i--;
	strr[i][j] = 'C';
}

char	**ft_get_path(char **strr, int wid, int hei)
{
	int	p_pos;

	p_pos = ft_get_player(strr, wid, hei);
	ft_build_path(strr, p_pos / wid, p_pos % wid, wid * hei / 3);
	ft_put_c(strr, wid, hei);
	if (!ft_haschar(strr, wid, hei, 'C'))
		ft_put_solo_c(strr, wid, hei);
	if (ft_haschar(strr, wid, hei, '0'))
		strr = ft_make_walls(strr, wid, hei);
	p_pos = 0;
	while (p_pos < MOBS && ft_haschar(strr, wid, hei, '0'))
		strr = ft_place_mob(strr, wid, hei, p_pos++);
	return (strr);
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
	res = ft_get_path(res, wid, hei);
	return (res);
}
