/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:01:39 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/06/25 18:13:35 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s);
void	ft_putstr(char *str);

#endif