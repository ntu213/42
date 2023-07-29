/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rgb_to_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 11:04:07 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
 *	prend un char *rgb  ("255,255,255") et renvoie un int (0x00FFFFFF)
 *	return (-1) en cas d'erreur (format)
 *
 *	pas besoin de gerer les cas negatif
 *
 *	utilisé dans le fichier  map_parsing/map_utils_set_color_ceil_and_floor
 */

int	ft_strrlen(char **strr)
{
	int	i;

	i = 0;
	while (strr[i])
		i++;
	return (i);
}

int	strs_no_atoi(char **strr)
{
	int	i;
	int	j;

	i = 0;
	while (strr[i])
	{
		j = 0;
		while (strr[i][j])
		{
			if (strr[i][j] < '0' || strr[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_str_rgb_to_int(char *rgb)
{
	int		res;
	char	**tmp;

	tmp = ft_split(rgb, ',');
	if (ft_strrlen(tmp) != 3 || ft_atoi(tmp[0]) > 255 || ft_atoi(tmp[0]) < 0
		|| ft_atoi(tmp[1]) > 255 || ft_atoi(tmp[1]) < 0
		|| ft_atoi(tmp[2]) > 255 || ft_atoi(tmp[2]) < 0 || !strs_no_atoi(tmp))
	{
		ft_strs_free(tmp);
		return (-1);
	}
	res = (ft_atoi(tmp[0]) * 256 * 256) + (ft_atoi(tmp[1])
			* 256) + ft_atoi(tmp[2]);
	ft_strs_free(tmp);
	return (res);
}

int	ft_get_color(int x, int y)
{
	int	color;

	if (x % 2 && y % 2)
		color = 0x000004F5;
	else if (!(x % 2) && !(y % 2))
		color = 0x00494AFF;
	else if (!(x % 2) && y % 2)
		color = 0x002349E0;
	else
		color = 0x00401EE0;
	return (color);
}
