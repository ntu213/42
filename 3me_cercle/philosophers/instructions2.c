/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:10:41 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/05/15 12:57:13 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_add_eat(t_myphilo *me, t_philo *philo)
{
	pthread_mutex_lock(&philo->verif);
	me->count_of_eat++;
	if (me->count_of_eat == philo->count_of_eat)
		philo->end_eat++;
	pthread_mutex_unlock(&philo->verif);
	pthread_mutex_lock(&philo->time);
	gettimeofday(&philo->tv, NULL);
	me->last_meat = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
	pthread_mutex_unlock(&philo->time);
}

t_tmp	ft_get_tmp(t_myphilo *me, t_philo *philo)
{
	t_tmp	new;

	new.me = me;
	new.philo = philo;
	return (new);
}

void	ft_printtime(t_philo *philo)
{
	pthread_mutex_lock(&philo->time);
	gettimeofday(&philo->tv, NULL);
	if (philo->tv.tv_usec / 1000 - philo->msec >= 0)
		printf("[%.4ld%.3ld] ",
			philo->tv.tv_sec - philo->sec,
			philo->tv.tv_usec / 1000 - philo->msec);
	else
		printf("[%.4ld%.3ld] ",
			philo->tv.tv_sec - philo->sec - 1,
			1000 + (philo->tv.tv_usec / 1000 - philo->msec));
	pthread_mutex_unlock(&philo->time);
}

void	ft_isdead(t_myphilo me, t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->time);
	gettimeofday(&philo->tv, NULL);
	time = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
	pthread_mutex_unlock(&philo->time);
	pthread_mutex_lock(&philo->verif);
	if (time - me.last_meat >= me.time_to_die && !philo->death)
	{
		pthread_mutex_unlock(&philo->verif);
		pthread_mutex_lock(&philo->verif);
		if (philo->death || philo->end_eat >= philo->count)
			return (ft_unlock(&philo->verif, &philo->print, NULL, NULL));
		philo->death = 1;
		pthread_mutex_unlock(&philo->verif);
		pthread_mutex_lock(&philo->print);
		ft_printtime(philo);
		printf("Philosopher %d is dead\n", me.id);
		pthread_mutex_unlock(&philo->print);
	}
	else
		pthread_mutex_unlock(&philo->verif);
}

void	*ft_death_thread(t_tmp *tmp)
{
	t_myphilo	*me;
	t_philo		*philo;

	me = tmp->me;
	philo = tmp->philo;
	while (1)
	{
		pthread_mutex_lock(&philo->verif);
		if (philo->death || philo->end_eat >= philo->count)
			break ;
		pthread_mutex_unlock(&philo->verif);
		ft_isdead(*me, philo);
		usleep(1000);
	}
	pthread_mutex_unlock(&philo->verif);
	return (tmp);
}
