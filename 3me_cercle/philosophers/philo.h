/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:48:49 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/05/01 17:51:02 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	int				count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				count_of_eat;
	int				death;
	int				start;
//	int				sec;
//	int				usec;
	int				*fork;
	pthread_t		*thread;
	struct timeval	tv;
//	pthread_mutex_t	**mutex;
}			t_philo;

typedef struct s_myphilo
{
	int	id;
	int	count_of_eat;
	int	fork_i;
	int	fork_r;
}			t_myphilo;

typedef struct s_rules
{
	int	count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	count_of_eat;
}			t_rules;

int	ft_atoi(const char *str);

#endif