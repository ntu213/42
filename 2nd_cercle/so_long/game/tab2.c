/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:01:51 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/04/17 10:02:18 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_end_sec(t_data *data, t_player *player)
{
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data);
	free(player);
}

int	ft_hasexit(int n, int score, char *name, int i)
{
	if (!n)
		return (0);
	else if (n == 1)
		ft_printf("[\e[0;31mGame Exit\e[0;37m] Total Score: %d\n", score);
	else if (n == 2)
		ft_printf("[\e[0;32mWin\e[0;37m] Level %d: %s %s of %d\n", i + 1,
			name, "finished with a total score", score);
	else if (n == 3)
		ft_printf("[\e[0;31mDeath\e[0;37m] Level %d Total Score: %d\n",
			i + 1, score);
	return (1);
}

void	ft_clear_check(t_check **check, int j)
{
	int	i;

	i = 0;
	while (i < j)
		free(check[i++]);
	free(check);
}
