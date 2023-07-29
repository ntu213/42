/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/25 11:48:40 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
// UNUSED - TOO MANY ARGS
void	mlxx_put_pixel_in_img(t_mlximg *mlximg, t_data *data, int x, int y,
	int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > data->win_width - 1 || y > data->win_height - 1)
		return ;
	dst = (char *) mlximg->addr
		+ (y * mlximg->line_length + x * (mlximg->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
*/

void	mlxx_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > data->win_width - 1 || y > data->win_height - 1)
		return ;
	dst = (char *) data->mlximg.addr + (y
			* data->mlximg.line_length + x * (data->mlximg.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	create_texture(t_data *data, t_mlximg *mimg, char *file)
{
	mimg->img = mlx_xpm_file_to_image(data->mlx,
			file, &(mimg->width), &(mimg->height));
	if (!mimg->img)
	{
		print_error_message_x2("Texture Not Found: ", file);
		free_and_exit_if_texture_not_found(data);
	}
	mimg->addr = (int *)mlx_get_data_addr(mimg->img, &mimg->bits_per_pixel,
			&mimg->line_length, &mimg->endian);
}

void	render_sprite(t_data *data, t_mlximg *mlximg, t_canvas *canvas)
{
	int		x;
	int		y;
	int		color;
	float	x_ratio;
	float	y_ratio;

	x_ratio = mlximg->width / (float) canvas->width;
	y_ratio = mlximg->height / (float) canvas->height;
	x = 0;
	while (x < canvas->width)
	{
		y = 0;
		while (y < canvas->height)
		{
			color = mlximg->addr[mlximg->line_length * (int)(y * y_ratio) / 4
				+ (int)(x * x_ratio)];
			if (color != canvas->transparency_color)
			{
				mlxx_put_pixel(data, x + canvas->left, y + canvas->top, color);
			}
			y += 1;
		}
		x += 1;
	}
}
