/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/24 16:24:41 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	mlxx_put_str(t_data *data, t_canvas *canvas, char *text)
{
	mlx_string_put(data->mlx, data->win, canvas->left, canvas->top,
		canvas->color, text);
}

void	mlxx_put_str_double(t_data *data, t_canvas *canvas, char *str, double d)
{
	char	*double_str;
	char	*full_str;

	double_str = ft_dtoa(d);
	full_str = ft_strs_concat(2, str, double_str);
	mlx_string_put(data->mlx, data->win, canvas->left, canvas->top,
		canvas->color, full_str);
	free(double_str);
	free(full_str);
}

void	mlxx_put_str_int(t_data *data, t_canvas *canvas, char *str, int i)
{
	char	*int_str;
	char	*full_str;

	int_str = ft_itoa(i);
	full_str = ft_strs_concat(2, str, int_str);
	mlx_string_put(data->mlx, data->win, canvas->left, canvas->top,
		canvas->color, full_str);
	free(int_str);
	free(full_str);
}

void	mlxx_set_font_size(t_data *data, int size)
{
	char	*str;
	char	*size_str;

	if (!WITH_MLX_LEAKS)
		return ;
	size_str = ft_itoa(size);
	str = ft_strs_concat(3, "-misc-fixed-*-*-*-*-", size_str, "-*-*-*-*-*-*-*");
	mlx_set_font(data->mlx, data->win, str);
	free(size_str);
	free(str);
}
