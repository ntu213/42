/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:04:52 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/17 10:05:01 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_lines(char **file, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < y)
	{
		while (file[j][i])
		{
			i++;
			if (i > x)
				return (0);
		}
		if (i < x)
			return (0);
		j++;
		i = 0;
	}
	if (j < 3 || x < 3 || (x * y) < 15)
		return (0);
	return (1);
}

int	ft_ok_char(char **file)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[j])
	{
		while (file[j][i])
		{
			if (!(file[j][i] == '0' || file[j][i] == '1'
					|| file[j][i] == 'P' || file[j][i] == 'C'
					|| file[j][i] == 'E' || file[j][i] == 'M'
					|| file[j][i] == 'I' || file[j][i] == 'S'))
				return (0);
			i++;
		}
		j++;
		i = 0;
	}
	return (1);
}

int	ft_ok_border(char **file, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (file[i])
	{
		if (i == 0 || i == y - 1)
		{
			while (file[i][j])
			{
				if (file[i][j] != '1')
					return (0);
				j++;
			}
		}
		if (file[i][0] != '1' || file[i][x - 1] != '1')
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

char	**ft_strrdup(char **strr, int size)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * (size + 1));
	while (strr[i])
	{
		new[i] = ft_strdup(strr[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	ft_char_type(char c, t_check *check, int x, int y)
{
	if (c == 'M')
		check->m++;
	else if (c == 'P')
	{
		check->pposx = x;
		check->pposy = y;
		check->p++;
	}
	else if (c == 'C')
		check->c++;
	else if (c == 'E')
		check->e++;
}
