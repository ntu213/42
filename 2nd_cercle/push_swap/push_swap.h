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
//#include <stdlib.h>	//--> NULL

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

t_tab	*ft_init_tab(int *tab, int size);

#endif