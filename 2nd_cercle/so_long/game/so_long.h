/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:15:52 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/10 18:50:48 by vgiraudo         ###   ########.fr       */
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
	void	*player;
	void	*coll;
	void	*exit;
	void	*mob;
}			t_imgg;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_imgg	*img;
	int		max_width;
	int		max_height;
}			t_data;

typedef struct s_player
{
	int	x;
	int	y;
	int	hp;
	int	sword;
	int	score;
}			t_player;

typedef struct s_mob
{
	int	x;
	int	y;
}			t_mob;

typedef struct s_map
{
	int		width;	//largeur de la map
	int		height;	//hauteur de la map
	int		fd;		//fd pertmettant d'acceder a la map
	int		ok;		//si ok = 1 la map est valide sinon ok = 0
	char	*name;	//nom entre afin de rechercher la map
	char	**map;	//tableau de tableau contenant le fichier
}			t_map;

typedef struct s_fstrct
{
	t_data		*data;
	t_player	*player;
	t_map		*map;
	int			wx;
	int			wy;
}			t_fstrct;

int			ft_atoi(const char *str);
int			ft_destroy(t_data *data);
int			ft_ok_file(t_map *obj, t_check *check);
int			ft_strnstr(const char *src, const char *obj, size_t n);
void		ft_first(t_map **str, int j);
void		ft_reset_map(t_data *data);
void		ft_place_map(t_data *data, t_map *map, int wx, int wy);
void		ft_reset_player(t_player *player, int x, int y, int score);
void		*ft_calloc(size_t n, size_t size);
char		*ft_strjoin(char *s1, char *s2, int freee);
char		**ft_split(char const *s, char c);
t_data		*ft_init_data(t_map **map, int j);
t_check		*ft_check_init(void);
t_player	*ft_init_player(void);

#endif