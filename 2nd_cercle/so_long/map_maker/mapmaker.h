/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmaker.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:02:06 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/04 18:11:28 by vgiraudo         ###   ########.fr       */
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

# ifndef WDENSITY
#  define WDENSITY 100
# endif

# ifndef CDENSITY
#  define CDENSITY 5
# endif

# ifndef MOBS
#  define MOBS 0
# endif

int		new_count(int count);
int		ft_atoi(const char *str);
int		ft_argerror(int n, char *str);
int		ft_random(int n, unsigned long int next);
int		ft_strnstr(const char *src, const char *obj, size_t n);
char	*ft_strjoin(char *s1, char *s2, int freee);
char	**make_map(int wid, int hei);

#endif