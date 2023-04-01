/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:15:55 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/31 10:15:55 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_val
{
	int	val;
	int	index;
	int	i_bin;
}			t_val;

typedef struct s_tab
{
	t_val	**tab;
	int		size;
}			t_tab;

int		ft_atoi(const char *str);
int		ft_getmin(t_tab *tab1, t_tab *tab2);
char	**ft_split(char const *s, char c);
void	ft_run(t_tab *a, int *tab);
void	ft_ra(t_tab *tab);
void	ft_rra(t_tab *tab);
void	ft_top(t_tab *a, t_tab *b);
void	ft_bot(t_tab *a, t_tab *b);
void	ft_push(t_tab *tab1, t_tab *tab2, char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n, size_t size);
t_tab	*ft_init_tab(int *tab, int size);

#endif