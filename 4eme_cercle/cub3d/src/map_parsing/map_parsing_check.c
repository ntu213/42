/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:25:57 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 10:08:34 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_check_wall(char **map, int i, int j)
{
	if (!i || !j || !map[i + 1] || !map[i - 1]
		|| (int)ft_strlen(map[i - 1]) <= j || (int)ft_strlen(map[i + 1]) <= j
		|| map[i - 1][j] == ' ' || !map[i][j + 1]
		|| !map[i - 1][j] || !map[i + 1][j] || !map[i][j - 1]
		|| map[i + 1][j] == ' ' || map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
		return (0);
	return (1);
}

int	is_wall_ok(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'D' || map[i][j] == 'Z')
				if (!ft_check_wall(map, i, j))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_player_ok(char **map)
{
	int	i;
	int	j;
	int	p;

	p = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				if (p)
					return (0);
				p++;
			}
			j++;
		}
		i++;
	}
	if (p)
		return (1);
	return (0);
}
