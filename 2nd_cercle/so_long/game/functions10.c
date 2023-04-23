/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:23:22 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/17 10:32:29 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
