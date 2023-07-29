/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:26:15 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 11:21:59 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./cub3d_define.h"
# include "./cub3d_define_keys.h"

// **************************************************** todo.c

int		ft_str_rgb_to_int(char *rgb);

// **************************************************** utils.c

int		print_error_message(char *msg);
int		print_error_message_x2(char *msg, char *msg2);

// **************************************************** game.c

int		door_in_front_of_player(t_data *data);
int		game_loop(t_data *data);

// **************************************************** render .... .c

//void	draw_mini_case(t_data *data, int x, int y, int color);
void	render_minimap(t_data *data);
void	render_floor_ceiling(t_data *data);
void	render_walls(t_data *data);
void	draw_background(t_data *data);
void	render_hud_debug(t_data *data);
void	render_hud(t_data *data);
void	render_sprites(t_data *data);
void	render_gun(t_data *data);
void	render_viseur(t_data *data);
void	render_vgiraudo(t_data *data);
void	render_floor_ceiling_untextured(t_data *data);

// **************************************************** mlx_utils.c

void	mlxx_put_pixel(t_data *data, int x, int y, int color);

/*
void	mlxx_put_str(t_data *data, int x, int y, int color, char *text);
void	mlxx_put_str_double(t_data *d, int x, int y, int c, char *te, double d);
void	mlxx_put_str_int(t_data *d, int x, int y, int color, char *str, int i);
*/
void	mlxx_put_str(t_data *data, t_canvas *canvas, char *text);
void	mlxx_put_str_int(t_data *data, t_canvas *canvas, char *str, int i);
void	mlxx_put_str_double(t_data *data, t_canvas *canva, char *str, double d);

void	create_texture(t_data *data, t_mlximg *mimg, char *file);
void	render_sprite(t_data *data, t_mlximg *mlximg, t_canvas *canvas);
void	mlxx_set_font_size(t_data *data, int size);

// **************************************************** map_open.c

void	open_map(t_data *data, char *filename);

// ************************************************** map_open_utils_set_strsss

void	set_mapfile_strs_or_exit(t_data *data, char *filename);
int		get_map_start_line_index_or_exit(t_data *data);
void	set_map_desc_strs(t_data *data, int map_start_line_index);
void	set_map_infos_strs(t_data *data, int map_start_line_index);

// **************************************************** map_parsing_check.c

int		ft_check_wall(char **map, int i, int j);
int		is_wall_ok(char **map);
int		is_player_ok(char **map);
void	set_color_ceil_and_floor_from_rgb_or_exit(t_data *data);

// **************************************************** player_movement.c

void	player_move(t_data *data, double dirx, double diry);
void	player_rotate_left(t_data *data, double rotation_speed);
void	player_rotate_right(t_data *data, double rotation_speed);
void	player_look_up_down(t_data *data, double speed);
void	player_up_down(t_data *data, double speed);

// **************************************************** player_actions.c

void	shoot(t_data *data);
void	open_door(t_data *data);

// **************************************************** inputs.c

int		handle_key(int keycode, t_data *data);
void	handle_mouse(t_data *data);
int		handle_mouse_click(int button, int x, int y, t_data *data);

// **************************************************** main.c

int		game_quit(t_data *data);

// **************************************************** player_init.c

void	player_init(t_data *data);

// **************************************************** enemies_init.c

void	init_enemies(t_data *data);

// **************************************************** frames.c

long	get_timestamp_ms(void);
void	handle_frames(t_data *data);

// **************************************************** free_exit.c

int		free_data_and_exit(t_data *data);
void	free_map(t_map *map);
int		game_quit(t_data *data);
int		free_exit_with_error(t_data *data, char *msg);
int		free_exit_with_error_x2(t_data *data, char *msg, char *msg2);
void	free_strs_if_exist(char **strs);
void	free_str_if_exist(char *str);
int		free_and_exit_if_texture_not_found(t_data *data);

// **************************************************** config_init.c

void	init_config(t_data *data);

// **************************************************** xxxxxxxxxxxx.c

void	init_textures(t_data *data);
long	get_timestamp_ms(void);
void	minimap_toggle(t_data *data);
void	minimap_change_size(t_data *data, int n);

#endif
