/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfleury <dfleury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:11:09 by dfleury           #+#    #+#             */
/*   Updated: 2023/07/24 16:11:24 by dfleury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

#define ENEMY_TIME_DIE_1 100
#define ENEMY_TIME_DIE_2 100

long	get_timestamp_ms(void)
{
	long			now;
	struct timeval	now_time;

	gettimeofday(&now_time, NULL);
	now = (now_time.tv_sec * 1000) + (now_time.tv_usec / 1000);
	return (now);
}

static void	calc_frame_rate(t_data *data)
{
	long	now;

	now = get_timestamp_ms();
	data->frame_delta_time = now - data->previous_frame_timestamp;
	data->frame_rate = 1000 / data->frame_delta_time;
	data->previous_frame_timestamp = get_timestamp_ms();
}

void	anim_enemy_alive(t_data *data, t_sprite *enemy)
{
	if (!(data->tmp_frame % 10))
	{
		enemy->text_num++;
		if (enemy->text_num > 1)
			enemy->text_num = 0;
	}
}

void	anim_enemy_killed(t_sprite *enemy)
{
	long	diff;

	diff = get_timestamp_ms() - enemy->killed_timestamp;
	if (diff < ENEMY_TIME_DIE_1)
		enemy->text_num = 3;
	else if (diff < ENEMY_TIME_DIE_1 + ENEMY_TIME_DIE_2)
		enemy->text_num = 4;
	else
	{
		enemy->is_alive = 0;
		enemy->text_num = 0;
	}
}

void	handle_frames(t_data *data)
{
	int	i;

	data->tmp_frame++;
	i = 0;
	while (data->spritex[i])
	{
		if (!data->spritex[i]->is_alive)
		{
			i++;
			continue ;
		}
		else if (data->spritex[i]->killed_timestamp > 0)
			anim_enemy_killed(data->spritex[i]);
		else if (data->spritex[i]->is_in_viseur)
			data->spritex[i]->text_num = 2;
		else
			anim_enemy_alive(data, data->spritex[i]);
		i++;
	}
	if (data->tmp_frame > 100000)
		data->tmp_frame = 0;
	calc_frame_rate(data);
}
