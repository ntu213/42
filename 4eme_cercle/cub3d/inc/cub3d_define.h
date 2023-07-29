/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_define.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:51:20 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 11:52:08 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_DEFINE_H
# define CUB3D_DEFINE_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <sys/time.h>

// *************** CONFIG ***************************

# define WITH_MLX_LEAKS 0

# define SHOOTING_HEIGHT 40	// * decalage y du gun qund on tire
# define TEXTURE_DOOR "./textures/val/door.xpm"
# define TEXTURE_GUN "./textures/val/gunz.xpm"

// *************** XXXXXXX ***************************

# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3

# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_DOWN 65364

/*
# define KEY_ESC 65307
# define KEY_SPACE 32

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_R 114

# define KEY_Q 113
# define KEY_C 99
# define KEY_V 118
# define KEY_B 98
# define KEY_Z 122
# define KEY_X 120
# define KEY_8 65431
# define KEY_2 65433
# define KEY_C 99
# define KEY_V 118
# define KEY_P 112
*/

typedef struct s_ray_wall
{
	double	raydirx;
	double	raydiry;
	double	camerax;
	int		mapx;
	int		mapy;
	double	side_distx;
	double	side_disty;
	double	delta_distx;
	double	delta_disty;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		wall_orientation;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_id;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}				t_ray_wall;

typedef struct s_ray_sprite
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	int		v_move_screen;
	int		sprite_height;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_width;
	int		draw_start_x;
	int		draw_end_x;
	int		tex_x;
	int		tex_y;
}					t_ray_sprite;

/*
 *
 *	int		width; // * nbre colonnes
 *	int		height; // * nbre lignes
 *	char	**mapfile_strs;	// * toutes les lignes du fichier map
 *	char	**mapfile_strs_infos; // * les lignes INFOS (textures ...)
 *	char	**mapfile_strs_desc; // * les lignes DESCRIPTION (0 1 ...)
 *
 *
 */
typedef struct s_map
{
	char	*texture_wall_n;
	char	*texture_wall_s;
	char	*texture_wall_w;
	char	*texture_wall_e;
	char	*texture_floor;
	char	*texture_ceil;
	char	*texture_door;
	char	*texture_gun;
	char	*texture_enemy_1;
	char	*texture_enemy_2;
	char	*texture_enemy_target;
	char	*texture_enemy_dead_1;
	char	*texture_enemy_dead_2;
	char	*color_rgb_str_floor;
	char	*color_rgb_str_ceil;
	int		color_floor;
	int		color_ceil;
	int		width;
	int		height;
	char	**map_cells;
	char	**mapfile_strs;
	char	**mapfile_strs_infos;
	char	**mapfile_strs_desc;

}				t_map;

typedef struct s_canvas
{
	int	left;
	int	top;
	int	width;
	int	height;
	int	transparency_color;
	int	color;
}	t_canvas;

/*
 *	double	dir_x; // * (-1 pour N, 1 pour S, 0 sinon)
 *	double	dir_y; // * (-1 pour W, 1 pour E, 0 sinon)
 *	double	pitch_z;
 *	double	plan_x; // * (0.66 pour E, -0.66 pour W, 0 sinon)
 *	double	plan_y; // * (0.66 pour N, -0.66 pour S, 0 sinon)
 *
*/
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	pos_z;
	double	dir_x;
	double	dir_y;
	double	pitch_z;
	double	plan_x;
	double	plan_y;
}	t_player;

typedef struct s_mlximg
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_mlximg;

/*
 *	t_mlximg	texture[5];	// 0,1: normal	// 2: tarrget // 3, 4 : shoot
 *
 */
typedef struct s_sprite
{
	int			exist;
	t_mlximg	texture[5];
	int			text_num;
	double		x;
	double		y;
	double		size_divizor;
	double		vertical_move;
	double		sprite_distance;
	int			is_in_viseur;
	int			is_alive;
	long		killed_timestamp;

}	t_sprite;

typedef struct s_config
{
	int		key_move_front;
	int		key_move_back;
	int		key_step_left;
	int		key_step_right;
	int		key_rotate_left;
	int		key_rotate_right;
	int		key_look_up;
	int		key_look_down;
	int		key_moove_up;
	int		key_moove_down;
	int		key_open_door;
	int		key_shoot;
	int		key_minimap_toggle;
	int		key_minimap_grow;
	int		key_minimap_shrink;
	int		key_move_run;
	int		screen_width;
	int		screen_height;
	double	speed_walk;
	double	speed_mouse_x;
	double	speed_mouse_y;
	double	fov;
	int		minimap_size;
	int		debug_show_hud;
	int		gun_width;
	int		gun_height;
	int		gun_shoot_height;
}	t_config;

/*
 *	t_mlximg	txtr_walls[5]; // la dernière, c'est pour les portes
 *	/// t_mlximg	txtr_enemy[4]; // 0 et 1: anim, 2: in_viseur, 3; dead
 *
 *
 *
 */
typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	t_map		*map;
	t_config	config;
	t_mlximg	mlximg;
	t_mlximg	txtr_walls[5];
	t_mlximg	txtr_floor;
	t_mlximg	txtr_ceil;
	t_mlximg	gun;
	t_sprite	**spritex;
	double		*z_buffer;
	int			mousex;
	int			mousey;
	int			previous_mousex;
	int			previous_mousey;
	t_player	player;
	long		previous_frame_timestamp;
	int			tmp_frame;
	int			frame_rate;
	int			frame_delta_time;
	int			selected_door_x;
	int			selected_door_y;
	int			enemies_count;
	int			enemies_count_initial;
	int			shooting;
}				t_data;

#endif
