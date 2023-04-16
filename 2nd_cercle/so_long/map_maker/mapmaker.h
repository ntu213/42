/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmaker.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:02:06 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/14 10:37:03 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPMAKER_H
# define MAPMAKER_H

# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef SEED
#  define SEED 1
# endif

# ifndef WSIDE
#  define WSIDE 40
# endif

# ifndef WDENSITY
#  define WDENSITY 3
# endif

# ifndef CDENSITY
#  define CDENSITY 5
# endif

# ifndef MOBS
#  define MOBS 0
# endif

int		ft_randomadr(int n);
int		ft_max(int a, int b);
int		new_count(int count);
int		ft_atoi(const char *str);
int		ft_argerror(int n, char *str);
int		is_side_wall(char **strr, int y, int x);
int		ft_place_wall(char **strr, int y, int x);
int		ft_random(int n, unsigned long int next);
int		total_items(char **strr, int wid, int hei);
int		ft_get_player(char **strr, int wid, int hei);
int		ft_build_path(char **strr, int y, int x, int rdm);
int		ft_haschar(char **strr, int wid, int hei, char c);
int		ft_strnstr(const char *src, const char *obj, size_t n);
void	ft_strrfree(char **strr, int size);
void	ft_new_loc_e(char **strr, int y, int x);
void	ft_recursive(char **strr, int x, int y, int *res);
char	*ft_line(int size, char c);
char	*ft_strjoin(char *s1, char *s2, int freee);
char	**make_map(int wid, int hei);
char	**ft_strrdup(char **strr, int size);
char	**ft_make_walls(char **strr, int wid, int hei);

#endif