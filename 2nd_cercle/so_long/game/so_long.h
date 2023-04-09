/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:15:52 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/08 19:24:55 by vgiraudo         ###   ########.fr       */
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

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		max_width;
	int		max_height;
}			t_data;

typedef struct s_player
{
	int	x;
	int	y;
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

int			ft_strnstr(const char *src, const char *obj, size_t n);
int			ft_atoi(const char *str);
int			ft_ok_file(t_map *obj, t_check *check);
void		ft_first(t_map **str, int j);
void		*ft_calloc(size_t n, size_t size);
char		*ft_strjoin(char *s1, char *s2, int freee);
char		**ft_split(char const *s, char c);
t_data		*ft_init_data(t_map **map, int j);
t_check		*ft_check_init(void);
t_player	*ft_init_player(int x, int y, int score);

#endif