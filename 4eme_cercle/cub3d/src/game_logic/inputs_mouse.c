/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/22 14:46:31 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	handle_mouse_quit_window(t_data *data)
{
	if (data->mousex < 10 || data->mousex > data->win_width - 10)
	{
		mlx_mouse_move(data->mlx, data->win, data->win_width / 2,
			data->win_height / 2);
		data->mousex = data->win_width / 2;
		data->mousey = data->win_height / 2;
		data->previous_mousex = data->mousex;
		data->previous_mousey = data->mousey;
	}
	if (data->mousey < 10 || data->mousey > data->win_height - 10)
	{
		mlx_mouse_move(data->mlx, data->win, data->win_width / 2,
			data->win_height / 2);
		data->mousex = data->win_width / 2;
		data->mousey = data->win_height / 2;
		data->previous_mousex = data->mousex;
		data->previous_mousey = data->mousey;
	}
}

void	handle_mouse(t_data *data)
{
	double	speed;
	int		deltax;
	int		deltay;

	mlx_mouse_get_pos(data->mlx, data->win, &data->mousex, &data->mousey);
	deltax = data->previous_mousex - data->mousex;
	deltay = data->previous_mousey - data->mousey;
	data->previous_mousex = data->mousex;
	data->previous_mousey = data->mousey;
	handle_mouse_quit_window(data);
	if (deltax || deltay)
	{
		speed = deltax * data->config.speed_mouse_x;
		player_rotate_left(data, speed);
		speed = deltay * data->config.speed_mouse_y;
		player_look_up_down(data, speed);
	}
}

int	handle_mouse_click(int button, int x, int y, t_data *data)
{
	shoot(data);
	ft_printf("Clic: bouton %d à la position (%d, %d)\n", button, x, y);
	return (0);
}
