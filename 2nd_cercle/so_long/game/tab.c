/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:53:48 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/03/21 20:04:35 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*

	void	*mlx;
	void	*win;
	void	*win2;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	win2 = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	(void)win;
	(void)win2;
*/

void	ft_first(char **str)
{
	int	width;
	int	height;
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_ok_file(&width, &height, ft_atoi(str[i]), str[i + 1]))
			ft_printf("[Error] %s: Invalid file format\n", str[i + 1]);
		else
		{
			ft_printf("%s: (temp) File OK\n", str[i + 1]);
		}
		i += 2;
	}
}
