/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:15:52 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/21 20:10:21 by vgiraudo         ###   ########.fr       */
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
	int		width;
	int		height;
	int		fd;
	char	*name;
	char	**map;
}			t_map;

int		ft_strnstr(const char *src, const char *obj, size_t n);
char	*ft_strjoin(char *s1, char *s2, int freee);
void	ft_first(char **str);
int		ft_ok_file(int *width, int *height, int fd, char *filename);
int		ft_atoi(const char *str);

#endif