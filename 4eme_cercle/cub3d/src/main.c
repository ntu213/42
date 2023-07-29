/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 11:50:16 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
 *	Afficher Error et Exit si :
 *		- Il n'y a pas UN ET UN SEUL arg
 *		- L'arg ne finit pas par ".cub"
 */
void	exit_if_arg_error(int argc, char **argv)
{
	if (argc != 2)
		exit (print_error_message("One (and only one) argument expected !"));
	if (!ft_str_endswith(argv[1], ".cub"))
		exit (print_error_message("Map must have .cub extension !"));
}

void	init_data(t_data *data)
{
	data->win_width = data->config.screen_width;
	data->win_height = data->config.screen_height;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"dFleury & vGiraudo's Ouuuuutstanding Cub3D !");
	data->z_buffer = ft_calloc(sizeof(double), data->win_width + 1);
	data->tmp_frame = 0;
	data->previous_frame_timestamp = get_timestamp_ms();
	data->shooting = 0;
	data->previous_mousex = data->win_width / 2;
	data->previous_mousey = data->win_height / 2;
	data->mlximg.img = mlx_new_image(data->mlx, data->win_width,
			data->win_height);
	data->mlximg.addr = (int *)mlx_get_data_addr(data->mlximg.img,
			&data->mlximg.bits_per_pixel, &data->mlximg.line_length,
			&data->mlximg.endian);
}

int	main(int argc, char **argv)
{
	t_data		data;

	exit_if_arg_error(argc, argv);
	init_config(&data);
	data.z_buffer = NULL;
	data.spritex = NULL;
	open_map(&data, argv[1]);
	init_data(&data);
	player_init(&data);
	init_enemies(&data);
	init_textures(&data);
	mlxx_set_font_size(&data, 24);
	mlx_hook(data.win, 2, 1L << 0, handle_key, &data);
	mlx_hook(data.win, 17, 1L << 0, game_quit, &data);
	mlx_mouse_move(data.mlx, data.win, 10, 10);
	mlx_mouse_hook(data.win, handle_mouse_click, &data);
	mlx_mouse_move(data.mlx, data.win, data.win_width / 2, data.win_height / 2);
	if (WITH_MLX_LEAKS)
		mlx_mouse_hide(data.mlx, data.win);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
