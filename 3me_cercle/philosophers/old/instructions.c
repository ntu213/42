/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiraudo <vgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:48:21 by vgiraudo          #+#    #+#             */
/*   Updated: 2023/05/08 16:29:36 by vgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_unlock(pthread_mutex_t *m1, pthread_mutex_t *m2, pthread_mutex_t *m3, pthread_mutex_t *m4)
{
	if (m1)
		pthread_mutex_unlock(m1);
	if (m2)
		pthread_mutex_unlock(m2);
	if (m3)
		pthread_mutex_unlock(m3);
	if (m4)
		pthread_mutex_unlock(m4);
	return ;
}

void	ft_take_fork(int id, t_myphilo* me, t_philo *philo)
{
	pthread_mutex_lock(philo->mutex[me->id - 1]);
	ft_isdead(*me, philo);
	me->fork_i = 1;
	pthread_mutex_lock(philo->print);
	if (philo->start || philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(philo->print, philo->mutex[me->id - 1], NULL, NULL));
	gettimeofday(&philo->tv, NULL);
	ft_printtime(philo);
	printf("Philosopher %d has taken left fork\n", id);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(philo->mutex[me->id % philo->count]);
	ft_isdead(*me, philo);
	me->fork_r = 1;
	pthread_mutex_lock(philo->print);
	if (philo->start || philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(philo->print, philo->mutex[me->id - 1],
			philo->mutex[me->id % philo->count], NULL));
	gettimeofday(&philo->tv, NULL);
	ft_printtime(philo);
	printf("Philosopher %d has taken right fork\n", id);
	pthread_mutex_unlock(philo->print);
}

void	ft_drop_fork(t_myphilo *me, t_philo *philo)
{
	pthread_mutex_unlock(philo->mutex[me->id - 1]);
	me->fork_i = 0;
	pthread_mutex_unlock(philo->mutex[me->id % philo->count]);
	me->fork_r = 0;
}

void	ft_sleep(t_myphilo me, t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	if (philo->start || philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(philo->print, NULL, NULL, NULL));
	gettimeofday(&philo->tv, NULL);
	ft_printtime(philo);
	printf("Philosopher %d is sleeping\n", me.id);
	pthread_mutex_unlock(philo->print);
	usleep(philo->time_to_sleep);
}

void	ft_printtime(t_philo *philo)
{
	if (philo->tv.tv_usec / 1000 - philo->msec >= 0)
		printf("[%.4ld%.3ld] ",
			philo->tv.tv_sec - philo->sec,
			philo->tv.tv_usec / 1000 - philo->msec);
	else
		printf("[%.4ld%.3ld] ",
			philo->tv.tv_sec - philo->sec - 1,
			1000 + (philo->tv.tv_usec / 1000 - philo->msec));
}

void	ft_eat(t_myphilo *me, t_philo *philo)
{
	ft_take_fork(me->id, me, philo);
	pthread_mutex_lock(philo->print);
	if (philo->start || philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(philo->print, philo->mutex[me->id - 1],
			philo->mutex[me->id % philo->count], NULL));
	gettimeofday(&philo->tv, NULL);
	ft_printtime(philo);
	printf("Philosopher %d is eating\n", me->id);
	pthread_mutex_unlock(philo->print);
	usleep(philo->time_to_eat);
	ft_drop_fork(me, philo);
	ft_add_eat(me, philo);
}

void	ft_think(t_myphilo me, t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	if (philo->start || philo->death || philo->end_eat >= philo->count)
		return (ft_unlock(philo->print, NULL, NULL, NULL));
	gettimeofday(&philo->tv, NULL);
	ft_printtime(philo);
	printf("Philosopher %d is thinking\n", me.id);
	pthread_mutex_unlock(philo->print);
	ft_isdead(me, philo);
}
