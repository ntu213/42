/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:34:48 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/30 08:34:48 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_pos
{
	int	pos;
	int	value;
}			t_pos;

typedef struct s_tab
{
	int	*taba;
	int	*tabb;
	int	*indexa;
	int	*indexb;
	int	size_a;
	int	size_b;
}			t_tab;

int		ft_strrlen(char **strr);
int		ft_atoi(const char *str);
int		ft_nb_pos(int *tab, int pos, int n);
int		ft_get_new_min(int *tab, int size, int old);
int		ft_end(int *taba, int *tabb, int size_a, int size_b);
int		ft_getmin(int *taba, int *tabb, int size_a, int size_b);
int		*ft_get_index(int *tab, int size);
char	**ft_split(char const *s, char c);
void	ft_swap(int *tab);
void	ft_r_pa(t_tab *tab);
void	ft_r_pb(t_tab *tab);
void	ft_putstr(char *str);
void	ft_run(int *taba, int n);
void	ft_ss(int *taba, int *tabb);
void	ft_bzero(void *s, size_t n);
void	ft_free(char **str, int *tab);
void	ft_rotate(int *tab, int size);
void	ft_revrot(int *tab, int size);
void	ft_radix(int *taba, int size_a);
void	ft_r_up(int *tab1, int *tab2, int size);
void	ft_r_down(int *tab1, int *tab2, int size);
void	ft_rr(int *taba, int *tabb, int size_a, int size_b);
void	ft_r_rot(int *tab1, int *tab2, int size, char *str);
void	ft_rrr(int *taba, int *tabb, int size_a, int size_b);
void	ft_pa(int *taba, int *tabb, int *size_a, int *size_b);
void	ft_pb(int *taba, int *tabb, int *size_a, int *size_b);
void	ft_push(int *tab1, int *tab2, int *size1, int *size2);
void	ft_top(int *taba, int *tabb, int *size_a, int *size_b);
void	ft_bot(int *taba, int *tabb, int *size_a, int *size_b);
void	ft_r_revrot(int *tab1, int *tab2, int size, char *str);
void	*ft_calloc(size_t n, size_t size);

#endif