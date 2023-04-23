/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:15:52 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/17 11:37:30 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../GNL/get_next_line.h"
# include "../mlx/mlx_int.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

# ifndef HP
#  define HP 1
# endif

typedef struct s_check
{
	int	p;
	int	m;
	int	c;
	int	e;
	int	pposx;
	int	pposy;
}			t_check;

typedef struct s_imgg
{
	void	*wall;
	void	*floor;
	void	*playerw;
	void	*playera;
	void	*players;
	void	*playerd;
	void	*coll;
	void	*exit;
	void	*mob;
	void	*weapon;
	void	*hp;
}			t_imgg;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_imgg	*img;
	int		max_width;
	int		max_height;
	int		hasexit;
}			t_data;

typedef struct s_player
{
	int	x;
	int	y;
	int	hp;
	int	sword;
	int	score;
	int	onexit;
}			t_player;

typedef struct s_mob
{
	int	x;
	int	y;
	int	alive;
}			t_mob;

typedef struct s_map
{
	int		width;
	int		height;
	int		fd;
	int		ok;
	char	*name;
	char	**map;
}			t_map;

typedef struct s_fstrct
{
	t_data		*data;
	t_player	*player;
	t_map		*map;
	t_mob		**mobs;
	int			wx;
	int			wy;
	int			mcount;
}			t_fstrct;

int			ft_intlen(int n);
int			ft_exit(t_data *data);
int			ft_strrlen(char **str);
int			ft_ok_char(char **file);
int			ft_atoi(const char *str);
int			ft_mobs_count(t_map *map);
int			ft_lines(char **file, int x, int y);
int			ft_ok_file(t_map *obj, t_check *check);
int			ft_controls(int key, t_fstrct *fstrct);
int			ft_ok_border(char **file, int x, int y);
int			ft_left_c(char **strr, int wid, int hei);
int			ft_random(int n, unsigned long int next);
int			ft_map_check(t_check *check, char **map);
int			ft_can_mob_move(int x, int y, t_map *map);
int			ft_check_compare(t_check *c1, t_check *c2);
int			ft_hasexit(int n, int score, char *name, int i);
int			ft_is_possible(char **map, int size, t_check *check);
int			ft_strnstr(const char *src, const char *obj, size_t n);
void		ft_new_win(t_data *data);
void		ft_destroy(t_data *data);
void		ft_reset_map(t_data *data);
void		ft_first(t_map **str, int j);
void		ft_free_mobs(t_mob **tab, int n);
void		ft_clear_check(t_check **check, int j);
void		ft_rewrite_mobs(t_fstrct *fstrct, int n);
void		ft_godmode(t_player *player, t_data *data);
void		ft_end_sec(t_data *data, t_player *player);
void		ft_print_hp(t_data *data, t_player *player);
void		ft_put_img(t_data *data, char c, int i, int j);
void		ft_direction(t_mob *mob, t_fstrct *fstrct, int n);
void		ft_char_type(char c, t_check *check, int x, int y);
void		ft_place_map(t_data *data, t_map *map, int wx, int wy);
void		ft_mobs_move(t_fstrct *fstrct, t_mob **mobtab, int py);
void		ft_exitmove(t_map *map, t_player *player, t_data *data);
void		ft_img_init_2(t_imgg *new, t_data *data, int n1, int n2);
void		ft_ok_recursive(char **map, t_check *check, int x, int y);
void		ft_move_up(t_data *data, t_player *player, int wx, int wy);
void		ft_replace_mobs(t_mob *mob, t_fstrct *fstrct, int x, int y);
void		ft_move_left(t_data *data, t_player *player, int wx, int wy);
void		ft_move_down(t_data *data, t_player *player, int wx, int wy);
void		ft_print_hp_score(t_data *data, t_player *player, int score);
void		ft_move_right(t_data *data, t_player *player, int wx, int wy);
void		ft_reset_player(t_data *data, t_player *player, int x, int y);
void		ft_up(t_player *player, t_map *map, t_data *data, t_fstrct *fstrct);
void		ft_left(t_player *player, t_map *map, t_data *data,
				t_fstrct *fstrct);
void		ft_down(t_player *player, t_map *map, t_data *data,
				t_fstrct *fstrct);
void		ft_right(t_player *player, t_map *map, t_data *data,
				t_fstrct *fstrct);
void		ft_is_on_mob(t_player *player, t_data *data, t_mob **mobtab,
				int mcount);
void		*ft_calloc(size_t n, size_t size);
char		*get_file(int fd);
char		*ft_strjoin(char *s1, char *s2, int freee);
char		**ft_split(char const *s, char c);
char		**ft_strrdup(char **strr, int size);
t_mob		*ft_init_mob(int i, int j);
t_mob		**ft_place_mobs(t_map *map, int *n);
t_imgg		*ft_img_init(t_data *data);
t_data		*ft_init_data(t_map **map, int j);
t_check		*ft_check_init(void);
t_player	*ft_init_player(int n);

#endif