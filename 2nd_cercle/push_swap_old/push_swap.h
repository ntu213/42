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
//#include <stdlib.h>	//--> NULL

typedef struct s_pos
{
	int	pos;
	int	value;
}			t_pos;

typedef struct s_tab
{
	int	**btabb;
	int	**btaba;
	int	*taba;
	int	*tabb;
	int	*indexa;
	int	*indexb;
	int	size_a;
	int	size_b;
}			t_tab;

int		ft_atoi(const char *str);
int		ft_end(int *taba, int *tabb, int size_a, int size_b);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t n, size_t size);
void	ft_bzero(void *s, size_t n);
void	ft_run(int *taba, int n);
void	ft_putstr(char *str);
void	ft_push(int *tab1, int *tab2, int *size1, int *size2);
void	ft_ss(int *taba, int *tabb);
void	ft_swap(int *tab);
void	ft_rotate(int *tab, int size);
void	ft_rr(int *taba, int *tabb, int size_a, int size_b);
void	ft_revrot(int *tab, int size);
void	ft_rrr(int *taba, int *tabb, int size_a, int size_b);
void	ft_top(int *taba, int *tabb, int *size_a, int *size_b);
void	ft_bot(int *taba, int *tabb, int *size_a, int *size_b);
void	ft_pa(int *taba, int *tabb, int *size_a, int *size_b);
void	ft_pb(int *taba, int *tabb, int *size_a, int *size_b);
void	ft_radix(int *taba, int size_a);

#endif