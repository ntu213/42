/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:27:49 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/06/27 12:39:48 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_lst
{
	int				val;
	int				pos;
	int				category;
	char			**str;
	struct s_lst	*first;
	struct s_lst	*next;
}			t_lst;

char	*get_next_line(int fd);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s);
void	ft_putstr(char *str);

#endif