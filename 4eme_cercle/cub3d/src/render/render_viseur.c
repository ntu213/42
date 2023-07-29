/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_viseur.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleuty           #+#    #+#             */
/*   Updated: 2023/07/22 14:18:18 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	render_viseur(t_data *data)
{
	int	x;
	int	y;
	int	size;

	size = 50;
	x = data->win_width / 2 - size;
	y = data->win_height / 2 - size;
	while (y < data->win_height / 2 + size)
	{
		mlxx_put_pixel(data, data->win_width / 2, y, 0x00FF00);
		y++;
	}
	while (x < data->win_width / 2 + size)
	{
		mlxx_put_pixel(data, x, data->win_height / 2, 0x00FF00);
		x++;
	}
}
